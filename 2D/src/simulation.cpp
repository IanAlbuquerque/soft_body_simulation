#include <stdio.h>
#include "simulation.h"
#include <stdexcept>
#include <float.h>

void initVertices(Vertex** list_of_vertices, int* num_vertices, const char* file_name, double* gravity, double* step)
{
	FILE* input_file;
	int num_vertices_read;
	int num_edges_read;
	double pos_x;
	double pos_y;
	double vel_x;
	double vel_y;
	double mass;
	int num_neig;
	int int_fix;
	Vertex *list;
	Vector* position;
	Vector* velocity;
	int v1;
	int v2;
	double k;
	double dist;
	double g;
	double h;

	input_file = fopen(file_name, "r");
	if(input_file == NULL)
	{
		throw std::runtime_error("ARQUIVO DE ENTRADA INEXISTENTE");
	}

	if(fscanf(input_file, " h= %lf", &h) != 1)
	{
		throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO h= step");
	}
	if(fscanf(input_file, " g= %lf", &g) != 1)
	{
		throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO g= gravity");
	}
	if(fscanf(input_file, " num_v= %d", &num_vertices_read) != 1)
	{
		throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO num_v= |V|");
	}
	if(fscanf(input_file, " num_e= %d", &num_edges_read) != 1)
	{
		throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO num_e= |E|");
	}

	list = new Vertex[num_vertices_read];

	for(int i=0; i<num_vertices_read; i++)
	{
		if(fscanf(input_file, " pos= %lf %lf", &pos_x, &pos_y) != 2)
		{
			throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO pos= x y");
		}
		if(fscanf(input_file, " vel= %lf %lf", &vel_x, &vel_y) != 2)
		{
			throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO vel= x y");
		}
		if(fscanf(input_file, " mass= %lf", &mass) != 1)
		{
			throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO mass= m");
		}
		if(fscanf(input_file, " num_neig= %d", &num_neig) != 1)
		{
			throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO num_neig= n");
		}
		if(fscanf(input_file, " fix= %d", &int_fix) != 1)
		{
			throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO fix= <0 ou 1>");
		}

		position = new Vector(2);
		(*position)[0] = pos_x;
		(*position)[1] = pos_y;

		velocity = new Vector(2);
		(*velocity)[0] = vel_x;
		(*velocity)[1] = vel_y;

		list[i].position = position;
		list[i].velocity = velocity;
		list[i].mass = mass;
		list[i].num_neighbours = 0;
		list[i].fixed = (bool) int_fix;

		list[i].neighbours = new int[num_neig];
		list[i].coeff_k = new double[num_neig];
		list[i].rest_r = new double[num_neig];
	}

	for(int i=0; i<num_edges_read; i++)
	{
		if(fscanf(input_file, " ver= %d %d", &v1, &v2) != 2)
		{
			throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO ver= v1 v2");
		}
		if(fscanf(input_file, " k= %lf", &k) != 1)
		{
			throw std::runtime_error("SINTAXE ARQUIVO INVALIDA: FALTANDO k= k");
		}

		list[v1].neighbours[list[v1].num_neighbours] = v2;
		list[v2].neighbours[list[v2].num_neighbours] = v1;

		list[v1].coeff_k[list[v1].num_neighbours] = k;
		list[v2].coeff_k[list[v2].num_neighbours] = k;

		dist = (*(list[v1].position) - *(list[v2].position)).norm();
		list[v1].rest_r[list[v1].num_neighbours] = dist;
		list[v2].rest_r[list[v2].num_neighbours] = dist;

		list[v1].num_neighbours++;
		list[v2].num_neighbours++;
	}

	fclose(input_file);

	*list_of_vertices = list;
	*num_vertices = num_vertices_read;
	*gravity = g;
	*step = h;

/*	Vertex *list = new Vertex[2];

	Vector *position1 = new Vector(2);
	(*position1)[0] = 0.5;
	(*position1)[1] = 0.5;

	Vector *velocity1 = new Vector(2);
	(*velocity1)[0] = 1.0;
	(*velocity1)[1] = 0.5;

	Vector *position2 = new Vector(2);
	(*position2)[0] = 1.0;
	(*position2)[1] = -0.5;

	Vector *velocity2 = new Vector(2);
	(*velocity2)[0] = -0.5;
	(*velocity2)[1] = 0.5;

	int *n1 = new int[1];
	n1[0] = 1;

	double *c1 = new double[1];
	c1[0] = 10;

	double *d = new double[1];
	d[0] = (*position1 - *position2).norm();

	Vertex one = { .node = 0, .mass = 1.0, .position = position1, .velocity = velocity1, .neighbours = n1, .coeff_k = c1, .rest_r = d, .num_neighbours = 1, .fixed = true };
	list[0] = one;

	int *n2 = new int[1];
	n2[0] = 0;

	Vertex two = { .node = 1, .mass = 1.0, .position = position2, .velocity = velocity2, .neighbours = n2, .coeff_k = c1, .rest_r = d, .num_neighbours = 1, .fixed = false  };
	list[1] = two;

	*list_of_vertices = list;
	*num_vertices = 2;*/
}

Vector getPosition(Vertex* list_of_vertex, int num_vertex)
{
	return *(list_of_vertex[num_vertex].position);
}

void printVertices(Vertex* list_of_vertices, int num_vertices)
{
	for(int i=0; i<num_vertices; i++)
	{
		cout << *(list_of_vertices[i].position);
	}
}

void fillWithRegularForces(	Vector* forces,
							Vertex* list_of_vertices,
							int num_vertices,
							double gravity)
{
	Vector force(2);
	Vertex vertex;
	Vector d(2);
	double d_norm;
	int neighbour_index;
	Vertex neighbour;

	for(int i=0; i<num_vertices; i++)
	{
		vertex = list_of_vertices[i];

		force[0] = 0;
	 	force[1] = -gravity*vertex.mass;

		for(int j=0; j<vertex.num_neighbours; j++)
		{
			neighbour_index = vertex.neighbours[j];
			neighbour = list_of_vertices[neighbour_index];
			d = *(neighbour.position) - *(vertex.position);
			d_norm = d.norm();

			force += vertex.coeff_k[j] * ( d_norm - vertex.rest_r[j]) * d / d_norm;
		}

		forces[i] = force;
	}
	return;
}

void fillWithDerivatives(	Vector* d_positions,
							Vector* d_velocities,
							Vertex* list_of_vertices,
							int num_vertices,
							double gravity)
{
	Vector::setDefaultSize(2);
	Vector* forces = new Vector[num_vertices];
	
	fillWithRegularForces(forces, list_of_vertices, num_vertices, gravity);

	for(int i=0; i<num_vertices; i++)
	{
		d_positions[i] = *(list_of_vertices[i].velocity);
		d_velocities[i] =  forces[i] / list_of_vertices[i].mass;
	}

	delete[] forces;
}

void fillWithCopy(		Vertex* new_list,
						Vertex* list_of_vertices,
						int num_vertices)
{
	for(int i=0; i<num_vertices; i++)
	{
		new_list[i].mass = list_of_vertices[i].mass;
		new_list[i].num_neighbours = list_of_vertices[i].num_neighbours;
		new_list[i].fixed = list_of_vertices[i].fixed;

		new_list[i].position = new Vector(2);
		*(new_list[i].position) = *(list_of_vertices[i].position);

		new_list[i].velocity = new Vector(2);
		*(new_list[i].velocity) = *(list_of_vertices[i].velocity);

		new_list[i].neighbours = new int[list_of_vertices[i].num_neighbours];
		new_list[i].coeff_k = new double[list_of_vertices[i].num_neighbours];
		new_list[i].rest_r = new double[list_of_vertices[i].num_neighbours];
		for(int j=0; j<list_of_vertices[i].num_neighbours; j++)
		{
			(new_list[i].neighbours)[j] = (list_of_vertices[i].neighbours)[j];
			(new_list[i].coeff_k)[j] = (list_of_vertices[i].coeff_k)[j];
			(new_list[i].rest_r)[j] = (list_of_vertices[i].rest_r)[j];
		}
	}
}

void updateWithStep(		Vertex* list_after_step,
							Vector* d_positions,
							Vector* d_velocities,
							Vertex* list_of_vertices,
							int num_vertices,
							double step)
{
	for(int i=0; i<num_vertices; i++)
	{
		if(list_after_step[i].fixed == false)
		{
			*(list_after_step[i].position) = *(list_of_vertices[i].position) + step * d_positions[i];
			*(list_after_step[i].velocity) = *(list_of_vertices[i].velocity) + step * d_velocities[i];
		}
		else
		{
			*(list_after_step[i].position) = *(list_of_vertices[i].position);
			*(list_after_step[i].velocity) = 0;
		}
	}
}

void freeList(Vertex* list_of_vertices, int num_vertices)
{
	for(int i=0; i<num_vertices; i++)
	{
		delete list_of_vertices[i].position;
		delete list_of_vertices[i].velocity;
		delete[] list_of_vertices[i].neighbours;
		delete[] list_of_vertices[i].coeff_k;
		delete[] list_of_vertices[i].rest_r;
	}
	delete[] list_of_vertices;	
}

void rungeKutta(Vertex* list_of_vertices, int num_vertices, double h, double gravity)
{
	Vector::setDefaultSize(2);
	Vector* new_positions = new Vector[num_vertices];
	Vector* new_velocities = new Vector[num_vertices];
	Vector* d_positions = new Vector[num_vertices];
	Vector* d_velocities = new Vector[num_vertices];

	for(int i=0; i<num_vertices; i++)
	{
		new_positions[i] = 0.0;
		new_velocities[i] = 0.0;
	}

	Vertex* aux_list = new Vertex[num_vertices];
	fillWithCopy(aux_list, list_of_vertices, num_vertices);

	fillWithDerivatives(d_positions, d_velocities, list_of_vertices, num_vertices, gravity);
	updateWithStep(aux_list, d_positions, d_velocities, list_of_vertices, num_vertices, h);
	for(int i=0; i<num_vertices; i++)
	{
		new_positions[i] += *(aux_list[i].position);
		new_velocities[i] += *(aux_list[i].velocity);
	}

	fillWithDerivatives(d_positions, d_velocities, aux_list, num_vertices, gravity);
	updateWithStep(aux_list, d_positions, d_velocities, list_of_vertices, num_vertices, h/2.0);
	for(int i=0; i<num_vertices; i++)
	{
		new_positions[i] += *(aux_list[i].position) * 2.0;
		new_velocities[i] += *(aux_list[i].velocity) * 2.0;
	}

	fillWithDerivatives(d_positions, d_velocities, aux_list, num_vertices, gravity);
	updateWithStep(aux_list, d_positions, d_velocities, list_of_vertices, num_vertices, h/2.0);
	for(int i=0; i<num_vertices; i++)
	{
		new_positions[i] += *(aux_list[i].position) * 2.0;
		new_velocities[i] += *(aux_list[i].velocity) * 2.0;
	}

	fillWithDerivatives(d_positions, d_velocities, aux_list, num_vertices, gravity);
	updateWithStep(aux_list, d_positions, d_velocities, list_of_vertices, num_vertices, h);
	for(int i=0; i<num_vertices; i++)
	{
		new_positions[i] += *(aux_list[i].position);
		new_velocities[i] += *(aux_list[i].velocity);
	}

	for(int i=0; i<num_vertices; i++)
	{
		*(list_of_vertices[i].position) = new_positions[i]/6.0;
		*(list_of_vertices[i].velocity) = new_velocities[i]/6.0;
	}

	freeList(aux_list, num_vertices);
	delete[] new_positions;
	delete[] new_velocities;
	delete[] d_positions;
	delete[] d_velocities;
}

void simulate(Vertex* list_of_vertices, int num_vertices, double time_to_simulate, double gravity, double step)
{
	double h;
	int num_iterations;
	double last_h;

	if( step > time_to_simulate)
	{
		h = (double) time_to_simulate;
		num_iterations = 1;
		last_h = 0.0;
	}
	else
	{
		h = step;
		num_iterations = (int) (time_to_simulate / step);
		last_h = time_to_simulate - num_iterations * step;
	}

	if(h > DBL_EPSILON)
	{
		for(int i=0; i<num_iterations; i++)
		{
			rungeKutta(list_of_vertices, num_vertices, h, gravity);
		}
		if(last_h > DBL_EPSILON)
		{
			rungeKutta(list_of_vertices, num_vertices, last_h, gravity);
		}
	}
}

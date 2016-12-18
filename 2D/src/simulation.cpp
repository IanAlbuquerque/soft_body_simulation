#include <stdio.h>
#include "simulation.h"

#define GRAVITY_CTE 0.00

void f()
{
	printf("f was called\n");
}

void initVertices(Vertex** list_of_vertices, int* num_vertices, const char* file_name)
{
	Vertex *list = new Vertex[2];

	Vector *position1 = new Vector(2);
	(*position1)[0] = 0.5;
	(*position1)[1] = 0.5;

	Vector *velocity1 = new Vector(2);
	(*velocity1)[0] = 0.5;
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
	c1[0] = 1;

	double *d = new double[1];
	d[0] = (*position1 - *position2).norm();

	Vertex one = { .node = 0, .mass = 1.0, .position = position1, .velocity = velocity1, .neighbours = n1, .coeff_k = c1, .rest_r = d, .num_neighbours = 1 };
	list[0] = one;

	int *n2 = new int[1];
	n2[0] = 0;

	Vertex two = { .node = 1, .mass = 1.0, .position = position2, .velocity = velocity2, .neighbours = n2, .coeff_k = c1, .rest_r = d, .num_neighbours = 1 };
	list[1] = two;

	*list_of_vertices = list;
	*num_vertices = 2;
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

void derivative(	Vector position,
					Vector velocity,
					Vector* d_position,
					Vector* d_velocity,
					int vertex_index,
					Vertex* list_of_vertices,
					double gravity)
{
	Vector force(2);
	Vertex v = list_of_vertices[vertex_index];
	Vector d(2);
	double d_norm;
	int neighbour_index;
	Vertex neighbour;

	force[0] = 0;
 	force[1] = gravity;

	for(int i=0; i<v.num_neighbours; i++)
	{
		neighbour_index = v.neighbours[i];
		neighbour = list_of_vertices[neighbour_index];
		d = *(neighbour.position) - position;
		d_norm = d.norm();
		force += v.coeff_k[i] * ( d_norm - v.rest_r[i]) * d / d_norm;
	}

	*d_position = velocity;
	*d_velocity = force / (double) v.mass;
}

void simulate(Vertex* list_of_vertices, int num_vertices, double time_to_simulate)
{
	Vector** new_positions = new Vector*[num_vertices];
	Vector** new_velocities = new Vector*[num_vertices];

	Vector position(2);
	Vector velocity(2);
	Vector d_position(2);
	Vector d_velocity(2);

	double h = (double) time_to_simulate;

	for(int i=0; i<num_vertices; i++)
	{
		new_positions[i] = new Vector(2);
		new_velocities[i] = new Vector(2);

		*(new_positions[i]) = 0;
		*(new_velocities[i]) = 0;

		position = *(list_of_vertices[i].position);
		velocity = *(list_of_vertices[i].velocity);

		// --------------- step 1

		derivative(	position,
					velocity,
					&d_position,
					&d_velocity,
					i,
					list_of_vertices,
					GRAVITY_CTE);

		position = *(list_of_vertices[i].position) + h*d_position;
		velocity = *(list_of_vertices[i].velocity) + h*d_velocity;

		*(new_positions[i]) += position;
		*(new_velocities[i]) += velocity;

		// --------------- step 2

		derivative(	position,
					velocity,
					&d_position,
					&d_velocity,
					i,
					list_of_vertices,
					GRAVITY_CTE);

		position = *(list_of_vertices[i].position) + h/2.0*d_position;
		velocity = *(list_of_vertices[i].velocity) + h/2.0*d_velocity;

		*(new_positions[i]) += 2*position;
		*(new_velocities[i]) += 2*velocity;

		// --------------- step 3

		derivative(	position,
					velocity,
					&d_position,
					&d_velocity,
					i,
					list_of_vertices,
					GRAVITY_CTE);


		position = *(list_of_vertices[i].position) + h/2.0*d_position;
		velocity = *(list_of_vertices[i].velocity) + h/2.0*d_velocity;

		*(new_positions[i]) += 2*position;
		*(new_velocities[i]) += 2*velocity;

		// --------------- step 4

		derivative(	position,
					velocity,
					&d_position,
					&d_velocity,
					i,
					list_of_vertices,
					GRAVITY_CTE);
		position = *(list_of_vertices[i].position) + h*d_position;
		velocity = *(list_of_vertices[i].velocity) + h*d_velocity;

		*(new_positions[i]) += position;
		*(new_velocities[i]) += velocity;

		*(new_positions[i]) /= 6.0;
		*(new_velocities[i]) /= 6.0;


	}

	for(int i=0; i<num_vertices; i++)
	{
		delete list_of_vertices[i].position;
		delete list_of_vertices[i].velocity;
		list_of_vertices[i].position = new_positions[i];
		list_of_vertices[i].velocity = new_velocities[i];
	}

	delete new_positions;
	delete new_velocities;
}

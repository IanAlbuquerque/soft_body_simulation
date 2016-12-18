#include <stdio.h>
#include "simulation.h"

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

	int *n1 = new int[1];
	n1[0] = 0;

	Vertex one = { .node = 0, .mass = 0, .position = position1, .velocity = velocity1, .neighbours = n1, .coeff_k = NULL, .rest_r = NULL, .num_neighbours = 1 };
	list[0] = one;

	Vector *position2 = new Vector(2);
	(*position2)[0] = 1.0;
	(*position2)[1] = -0.5;

	Vector *velocity2 = new Vector(2);
	(*velocity2)[0] = 0.5;
	(*velocity2)[1] = 0.5;

	int *n2 = new int[1];
	n2[0] = 1;

	Vertex two = { .node = 1, .mass = 0, .position = position2, .velocity = velocity2, .neighbours = n2, .coeff_k = NULL, .rest_r = NULL, .num_neighbours = 1 };
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

void derivative(	Vector& d_position,
					Vector& d_velocity,
					int vertex_index,
					Vertex* list_of_vertices,
					int* num_vertices,
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
		d = *(neighbour.position) - *(v.position);
		d_norm = d.norm();
		force += -v.coeff_k[i] * ( d_norm - v.rest_r[i]) * d / d_norm;
	}

	d_position = (*v.velocity);
	d_velocity = force / v.mass;
}

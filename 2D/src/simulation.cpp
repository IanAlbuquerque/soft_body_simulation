#include <stdio.h>
#include "simulation.h"

void f()
{
	printf("f was called\n");
}

struct _Vertex {
	int node;
	double mass;
	Vector position;
	Vector velocity;
	int *neighbours;
	double *coeff_k;
	double *rest_r;
	int num_neighbours;
};

void initVertices(Vertex* list_of_vertices, int* num_vertices, char* file_name)
{
	Vertex *list = (Vertex*)malloc(sizeof(Vertex));

	Vector position(2);
	position[0] = 0.5;
	position[1] = 0.5;

	Vector velocity(2);
	position[0] = 0.5;
	position[1] = 0.5;
	Vertex one = { .node = 0, .mass = 0, .position = position, .velocity = velocity, .neighbours = NULL, .coeff_k = NULL, .rest_r = NULL, .num_neighbours = 1 };

	list[0] = one;

	list_of_vertices = list;
	*num_vertices = 1;
}

Vector getPosition(Vertex* list_of_vertex, int num_vertex)
{
	Vector position(2);
	position[0] = 0.5;
	position[1] = 0.5;
	return position;
}

void derivative(	Vector& d_position
					Vector& d_velocity,
					int vertex_index,
					Vertex* list_of_vertices,
					int* num_vertices,
					double gravity)
{
	Vector force(2);
	Vertex v = list_of_vertices[vertex_index];
	Vector d;
	double d_norm;
	int neighbour_index;
	Vertex neighbour;

	force[0] = 0;
	force[1] = gravity;

	for(int i=0; i<v->num_neighbours; i++)
	{
		neighbour_index = v->neighbours[i];
		neighbour = list_of_vertices[neighbour_index];
		d = neighbour->position - v->position;
		force += -v->coeff_k[i] * ( - v->rest_r[i])
	}

	d_position = v->velocity;
	d_velocity = force / v->mass;
}
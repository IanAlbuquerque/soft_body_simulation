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
};

void initVertices(Vertex* list_of_vertices, int* num_vertices, char* file_name)
{
	Vertex *list = (Vertex*)malloc(sizeof(Vertex));

	Vector position(2);
	position[0] = 0.5;
	position[1] = 0.5;
	Vertex one = { .node = 0, .mass = 0, .position = position, .neighbours = NULL, .coeff_k = NULL, .rest_r = NULL };

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

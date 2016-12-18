#include <stdio.h>
#include "simulation.h"

void f()
{
	printf("f was called\n");
}

struct _Vertex {
	int node;
	double mass;
	Vector *position;
	Vector *velocity;
	int *neighbours;
	double *coeff_k;
	double *rest_r;
};

void initVertices(Vertex* list_of_vertices, int* num_vertices, char* file_name)
{
	Vertex *list = (Vertex*)malloc(2*sizeof(Vertex));

	Vector *position1 = new Vector(2);
	position1[0] = 0.5;
	position1[1] = 0.5;

	Vector *velocity1 = new Vector(2);
	velocity1[0] = 0.5;
	velocity1[1] = 0.5;

	Vertex one = { .node = 0, .mass = 0, .position = position1, .velocity = velocity1, .neighbours = NULL, .coeff_k = NULL, .rest_r = NULL };

	Vector *position2 = new Vector(2);
	position2[0] = 1.0;
	position2[1] = -0.5;

	Vector *velocity2 = new Vector(2);
	velocity2[0] = 0.5;
	velocity2[1] = 0.5;

	Vertex two = { .node = 0, .mass = 0, .position = position2, .velocity = velocity2, .neighbours = NULL, .coeff_k = NULL, .rest_r = NULL };

	list[0] = one;
	list[1] = two;

	list_of_vertices = list;
	*num_vertices = 2;
}

Vector getPosition(Vertex* list_of_vertex, int num_vertex)
{
	Vertex v = list_of_vertex[num_vertex];
	Vector position(2);
	position[0] = (*v.position)[0];
	position[1] = (*v.position)[1];

	// position[0] = (*list_of_vertex[num_vertex].position)[0];
	// position[1] = (*list_of_vertex[num_vertex].position)[1];
	// printf("%g\n", *list_of_vertex[num_vertex].position[0]);
	// position[0] = 1;
	// position[1] = 1;
	return position;
}

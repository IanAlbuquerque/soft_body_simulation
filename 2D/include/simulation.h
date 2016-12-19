#ifndef SIMULATION_H
#define SIMULATION_H

#include "Vector.h"
#include <vector>

struct _Vertex {
	double mass;
	int num_neighbours;
	bool fixed;

	Vector *position;
	Vector *velocity;

	int *neighbours;
	double *coeff_k;
	double *rest_r;
	bool *rigid;
};

typedef struct _Vertex Vertex;

void initVertices(Vertex** list_of_vertices, int* num_vertices, const char* file_name, double* gravity, double* step, int* rigid_bars_count);

void simulate(Vertex* list_of_vertices, int num_vertices, double time_to_simulate, double gravity, double step, int rigid_bars_count);

void printVertices(Vertex* list_of_vertices, int num_vertices);

Vector getPosition(Vertex* list_of_vertex, int num_vertex);

#endif
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Vector.h"

typedef struct _Vertex Vertex;

void initVertices(Vertex** list_of_vertices, int* num_vertices, char* file_name);

void simulate(Vertex* list_of_vertices, int num_vertices, double time_to_simulate);

void printVertices(Vertex* list_of_vertices, int num_vertices);

Vector getPosition(Vertex* list_of_vertex, int num_vertex);

#endif
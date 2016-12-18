#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"

typedef struct _Vertex Vertex;

void simulate(Vertex* list_of_vertices, int num_vertices, double time_to_simulate);

void initVertices(Vertex* list_of_vertices, int* num_vertices, char* file_name);

#endif
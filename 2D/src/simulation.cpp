#include <stdio.h>
#include "Vector.h"

void f()
{
	printf("f was called\n");
}

typedef struct Vertex {
	int node;
	double mass;
	Vector position;
	int *neighbours;
	double *coeff_k;
	double *rest_r;
};

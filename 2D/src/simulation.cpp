#include <stdio.h>
#include "Vector.h"
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

#include <stdio.h>

void f()
{
	printf("f was called\n");
}

typedef struct Vertex {
	int node;
	double mass;
	double position;
	int *neighbours;
	double *coeff;
};

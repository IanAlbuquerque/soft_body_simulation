#include <stdio.h>

void f()
{
	printf("f was called\n");
}

typedef struct Vertice {
	int no;
	double massa;
	double posicao;
	Viz ** vizinhos;

};

typedef struct Viz
{
	int no;
	double mola;
	Viz *prox;
};

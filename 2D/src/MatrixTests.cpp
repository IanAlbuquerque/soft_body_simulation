#include <stdio.h>
#include "linalg.h"

using namespace std;

int main(int argc, char** argv)
{
	Matrix matrix(2,2);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;
	cout << matrix;
}
#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{

	int n = 3;
	
	Vector v = new Vector(n);

	for (int i = 0; i < n; i++)
	{
		v[i] = (double)(i + 1);
	}

	cout << v << endl;

	return 0;
}

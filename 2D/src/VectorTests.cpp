#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{

	int n = 3;
	int dimension;
	bool result;
	
	Vector v1(n);
	Vector v2(n);
	Vector v3(n);
	Vector v5(n+1);

	for (int i = 0; i < n; i++)
	{
		v1[i] = (double)(i + 1);
		v2[i] = (double)(i + 1);
	}

	cout << "[] operator test" << endl;
	cout << "V1" << endl << v1 << endl;
	cout << "V2" << endl << v2 << endl;
	cout << endl;

	cout << "init with other vector test" << endl;
	Vector v4(v1);
	cout << "V4(V1)" << endl << v4 << endl << endl;

	cout << "= operator test" << endl;
	v3 = v1;
	cout << "V3 = V1" << endl << v3 << endl << endl;

	cout << "+= operator test" << endl;
	v1 += v2;
	cout << "V1 += V2" << endl << v1 << endl << endl;

	cout << "-= operator test" << endl;
	v1 -= v2;
	cout << "V1 -= V2" << endl << v1 << endl << endl;

	cout << "- operator test" << endl;
	v1 = v1 - v2;
	cout << "V1 = V1 - V2" << endl << v1 << endl << endl;

	cout << "+ operator test" << endl;
	v1 = v1 + v2;
	cout << "V1 = V1 + V2" << endl << v1 << endl << endl;

	cout << "*= operator test" << endl;
	v1 *= 2;
	cout << "V1 *= 2" << endl << v1 << endl << endl;

	cout << "/= operator test" << endl;
	v1 /= 2;
	cout << "V1 /= 2" << endl << v1 << endl << endl;

	cout << "/ operator test" << endl;
	v1 = v1 / 2;
	cout << "V1 = V1 / 2" << endl << v1 << endl << endl;

	cout << "* operator test" << endl;
	v1 = v1 * 2;
	cout << "V1 = V1 * 2" << endl << v1 << endl << endl;

	cout << "== (true) operator test" << endl;
	result = v3 == v1;
	cout << "V3 == V1" << endl << result << endl << endl;

	cout << "== (false) operator test" << endl;
	v3 *= 2;
	result = v3 == v1;
	cout << "V3 *= 2 -> V3 == V1" << endl << result << endl << endl;

	cout << "!= (true) operator test" << endl;
	result = v3 != v1;
	cout << "V3 != V1" << endl << result << endl << endl;

	cout << "!= (false) operator test" << endl;
	v3 /= 2;
	result = v3 != v1;
	cout << "V3 /= 2 -> V3 != V1" << endl << result << endl << endl;

	cout << "getDimension test" << endl;
	dimension = v1.getDimension();
	cout << "V1 getDimension" << endl << dimension << endl << endl;

	cout << "WRONG DIMENSIONS TESTS" << endl << endl;

	try
	{
		v5 = v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(3) = V1(2)" << endl << err.what() << endl << endl;
	}

	try
	{
		v5 += v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(3) += V1(2)" << endl << err.what() << endl << endl;
	}

	try
	{
		v5 = v5 + v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(3) = V5(3) + V1(2)" << endl << err.what() << endl << endl;
	}

	try
	{
		v5 -= v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(3) -= V1(2)" << endl << err.what() << endl << endl;
	}

	try
	{
		v5 = v5 - v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(3) = V5(3) - V1(2)" << endl << err.what() << endl << endl;
	}

	try
	{
		result = v5 == v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(3) == V1(2)" << endl << err.what() << endl << endl;
	}

	try
	{
		result = v5 != v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(3) != V1(2)" << endl << err.what() << endl << endl;
	}

	return 0;
}

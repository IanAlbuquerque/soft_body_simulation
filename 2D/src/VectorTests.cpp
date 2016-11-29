#include "Vector.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{

	int n = 3;
	int dimension;
	double dot;
	double norm;
	bool result;
	
	Vector v1(n);
	Vector v2(n);
	Vector v3(n);
	Vector vz(n);
	Vector v5(n+1);

	//Constants
	int j = 2;
	float f = 2.0;
	double d = 2.0;
	//

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

	cout << "= operator test (constant)" << endl;
	vz = 0;
	cout << "Vz = 0" << endl << vz << endl << endl;

	cout << "+= operator test (vector)" << endl;
	v1 += v2;
	cout << "V1 += V2" << endl << v1 << endl << endl;

	cout << "+= operator test (double)" << endl;
	v1 += d;
	cout << "V1 += 2.0" << endl << v1 << endl << endl;

	cout << "-= operator test (vector)" << endl;
	v1 -= v2;
	cout << "V1 -= V2" << endl << v1 << endl << endl;

	cout << "-= operator test (double)" << endl;
	v1 -= d;
	cout << "V1 -= 2.0" << endl << v1 << endl << endl;

	cout << "- operator test" << endl;
	v1 = v1 - v2;
	cout << "V1 = V1 - V2" << endl << v1 << endl << endl;

	cout << "+ operator test (vector)" << endl;
	v1 = v1 + v2;
	cout << "V1 = V1 + V2" << endl << v1 << endl << endl;

	cout << "+ operator test (double)" << endl;
	v1 = v1 + d;
	cout << "V1 = v1 + 2.0" << endl << v1 << endl << endl;

	cout << "- operator test (double)" << endl;
	v1 = v1 - d;
	cout << "V1 = v1 - 2.0" << endl << v1 << endl << endl;

	cout << "+ operator test (int)" << endl;
	v3 = j + v3;
	cout << "V3 = 2 + V3" << endl << v3 << endl << endl;

	cout << "+ operator test (float)" << endl;
	v3 = f + v3;
	cout << "V3 = 2.0 + V3" << endl << v3 << endl << endl;

	cout << "+ operator test (double)" << endl;
	v3 = d + v3;
	cout << "V3 = 2.0 + V3" << endl << v3 << endl << endl;

	cout << "- operator test (int)" << endl;
	v3 = j - v3;
	cout << "V3 = 2 - V3" << endl << v3 << endl << endl;

	cout << "- operator test (float)" << endl;
	v3 = f - v3;
	cout << "V3 = 2.0 - V3" << endl << v3 << endl << endl;

	cout << "- operator test (double)" << endl;
	v3 = d - v3;
	cout << "V3 = 2.0 - V3" << endl << v3 << endl << endl;

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

	cout << "* operator test (int)" << endl;
	v3 = j * v3;
	cout << "V3 = 2 * V3" << endl << v3 << endl << endl;

	cout << "* operator test (float)" << endl;
	v3 = f * v3;
	cout << "V3 = 2.0 * V3" << endl << v3 << endl << endl;

	cout << "* operator test (double)" << endl;
	v3 = d * v3;
	cout << "V3 = 2.0 * V3" << endl << v3 << endl << endl;

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

	cout << "WRONG DIMENSIONS TESTS" << endl << endl;

	try
	{
		v5 = v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(4) = V1(3)" << endl << err.what() << endl << endl;
	}

	try
	{
		v5 += v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(4) += V1(3)" << endl << err.what() << endl << endl;
	}

	try
	{
		v5 = v5 + v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(4) = V5(4) + V1(3)" << endl << err.what() << endl << endl;
	}

	try
	{
		v5 -= v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(4) -= V1(3)" << endl << err.what() << endl << endl;
	}

	try
	{
		v5 = v5 - v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(4) = V5(4) - V1(3)" << endl << err.what() << endl << endl;
	}

	try
	{
		result = v5 == v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(4) == V1(3)" << endl << err.what() << endl << endl;
	}

	try
	{
		result = v5 != v1;
	}
	catch(const runtime_error& err)
	{
		cout << "V5(4) != V1(3)" << endl << err.what() << endl << endl;
	}

	cout << "OTHER FUNCTIONS TESTS" << endl << endl;

	cout << "getDimension test" << endl;
	dimension = v1.getDimension();
	cout << "V1 getDimension" << endl << dimension << endl << endl;

	cout << "Dot test" << endl;
	dot = v1.dot(v2);
	cout << "V1.dot(V2)" << endl << dot << endl << endl;

	cout << "Dot test with invalid dimension" << endl;
	try
	{
		dot = v1.dot(v5);
	}
	catch(const runtime_error& err)
	{
		cout << "V1[3](V5[4])" << endl << err.what() << endl << endl;
	}

	cout << "Norm test" << endl;
	norm = v1.norm();
	cout << "V1.norm()" << endl << norm << endl << endl;

	return 0;
}

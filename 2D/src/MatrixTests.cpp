#include <stdio.h>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main(int argc, char** argv)
{
	Matrix A(2,2);
	A[0][0] = 1.0;
	A[0][1] = 2.0;
	A[1][0] = 3.0;
	A[1][1] = 4.0;
	cout << "----" << endl;
	cout << A;

	Matrix B(2,2);
	B[0][0] = -3.0;
	B[0][1] = -2.0;
	B[1][0] = -1.0;
	B[1][1] = 1.0;
	cout << "----" << endl;
	cout << B;

	cout << "----" << endl;
	cout << A+B;

	Matrix C = A+B;
	cout << "----" << endl;
	cout << C*2;

	Matrix D(2,3);
	cout << "----" << endl;
	cout << D;

	Matrix E(A);
	cout << "----" << endl;
	cout << E;

	A *= 2;

	cout << "----" << endl;
	cout << A;
	cout << "----" << endl;
	cout << E;

	Matrix F = A+(E/10)+(2*B);
	cout << "----" << endl;
	cout << A;
	cout << E/10;
	cout << 2*B;
	cout << F;

	Matrix G(2,2);
	G[0][0] = 2.0;
	G[0][1] = 4.0;
	G[1][0] = 6.0;
	G[1][1] = 8.0;

	cout << "----" << endl;
	bool boo;
	boo = A == G;
	cout << boo << endl;
	boo = A != G;
	cout << boo << endl;
	boo = A == E;
	cout << boo << endl;
	boo = A != E;
	cout << boo << endl;

	cout << "----" << endl;
	Matrix H(2,2);
	H = 1;
	cout << H;
	H += 3;
	cout << H;
	H -= 5;
	cout << H;

	cout << "----" << endl;
	Matrix I(3,3);
	H = 5;
	cout << H;
	H = 100 - H;
	cout << H;
	H = 5 + H;
	cout << H;

	cout << "----" << endl;
	Matrix J = Matrix::I(5,5);
	cout << J;

	cout << "----" << endl;

	Matrix K(3,3);
	K[0][0] = 1.0;
	K[0][1] = 2.0;
	K[0][2] = 3.0;
	K[1][0] = 4.0;
	K[1][1] = 5.0;
	K[1][2] = 6.0;
	K[2][0] = 7.0;
	K[2][1] = 8.0;
	K[2][2] = 9.0;
	cout << K;
	cout << K.T();

	cout << "----" << endl;

	Matrix I3 = Matrix::I(3,3);

	cout << K;
	cout << I3;
	cout << K * I3;
	cout << E * E;

	Matrix L = Matrix::I(2,3);
	Matrix M = Matrix::I(3,5);
	cout << L * M;

	cout << "----" << endl;

	Vector v(2);
	v[0] = 10;
	v[1] = 0.1;

	cout << E * v << endl;
	cout << "----" << endl;

	Matrix T(3,3);
	Vector b1(3);
	Vector b2(3);
	T[0][0] = 1;  T[0][1] = 2; T[0][2] = -1;
	T[1][0] = 2;  T[1][1] = 1; T[1][2] = -2;
	T[2][0] = -3; T[2][1] = 1; T[2][2] = 1;
	b1[0] = 3;     b1[1] = 3;    b1[2] = -6;
	b2[0] = 3;     b2[1] = 3;    b2[2] = -6;

	Matrix P = T.pivot(&b1);

	cout << P << endl << b1 << endl;

	Vector x = T.solve(b2);

	cout << x << endl;

	Matrix T2(6,6);
	Vector b3(6);
	T2[0][0] = 3;   T2[0][1] = -1;  T2[0][2] = 0;  T2[0][3] = 0;   T2[0][4] = 0;   T2[0][5] = 0.5;
	T2[1][0] = -1;  T2[1][1] = 3;   T2[1][2] = -1; T2[1][3] = 0;   T2[1][4] = 0.5; T2[1][5] = 0;
	T2[2][0] = 0;   T2[2][1] = -1;  T2[2][2] = 3;  T2[2][3] = -1;  T2[2][4] = 0;   T2[2][5] = 0;
	T2[3][0] = 0;   T2[3][1] = 0;   T2[3][2] = -1; T2[3][3] = 3;   T2[3][4] = -1;  T2[3][5] = 0;
	T2[4][0] = 0;   T2[4][1] = 0.5; T2[4][2] = 0;  T2[4][3] = -1;  T2[4][4] = 3;   T2[4][5] = -1;
	T2[5][0] = 0.5; T2[5][1] = 0;   T2[5][2] = 0;  T2[5][3] = 0;   T2[5][4] = -1;  T2[5][5] = 3;
	b3[0] = 2.5;   b3[1] = 1.5;   b3[2] = 1;    b3[3] = 1;     b3[4] = 1.5;   b3[5] = 2.5;

	Vector x2 = T2.solve(b3);

	cout << x2 << endl;

	return 0;
}
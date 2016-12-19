#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"
#include <iostream>

using namespace std;

class Matrix
{
private:
	double** M;
	int num_rows;
	int num_cols;

	class Row
	{
    friend class Matrix;
	private:
		Matrix& _matrix;
		int _row_number;
		Row(Matrix& matrix,const int row_number) : _matrix(matrix), _row_number(row_number) {}
	public:
        double& operator[](const int col)
        { 
        	return _matrix.M[this->_row_number][col];
        }	
	};

public:
	Matrix(int num_rows, int num_cols);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix &other);
	Matrix& operator=(const double constant);
	Matrix& operator+=(const Matrix &other);
	Matrix& operator+=(const double constant);
	Matrix& operator-=(const Matrix &other);
	Matrix& operator-=(const double constant);
	Matrix& operator*=(const double constant);
	Matrix& operator/=(const double constant);
	const Matrix operator+(const Matrix &other) const;
	const Matrix operator-(const Matrix &other) const;
	const Matrix operator+(const double constant) const;
	const Matrix operator-(const double constant) const;
	const Matrix operator*(const double constant) const;
	const Matrix operator/(const double constant) const;
	bool operator==(const Matrix &other) const;
	bool operator!=(const Matrix &other) const;
	~Matrix();
	Row operator[](const int row);
	const Matrix T() const;
	Matrix& operator*=(const Matrix &other);
	const Matrix operator*(const Matrix &other) const;
	const Vector operator*(const Vector &other) const;
	const int getNumRows() const;
	const int getNumCols() const;
	const Vector solve(Vector b) const;
	const Matrix pivot(Vector* b) const;
	void swapLines(const int line1, const int line2);

	friend ostream& operator<<(ostream& os, const Matrix& matrix);

	static const Matrix I(int num_rows, int num_cols);
};


ostream& operator<<(ostream& os, const Matrix& matrix);
const Matrix operator*(double constant, const Matrix& matrix);
const Matrix operator*(float constant, const Matrix& matrix);
const Matrix operator*(int constant, const Matrix& matrix);
const Matrix operator+(double constant, const Matrix& matrix);
const Matrix operator+(float constant, const Matrix& matrix);
const Matrix operator+(int constant, const Matrix& matrix);
const Matrix operator-(double constant, const Matrix& matrix);
const Matrix operator-(float constant, const Matrix& matrix);
const Matrix operator-(int constant, const Matrix& matrix);

#endif
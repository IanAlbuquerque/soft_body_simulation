#ifndef MATRIX_H
#define MATRIX_H

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
	private:
		Matrix& _matrix;
		int _row_number;
	public:
		Row(Matrix& matrix,const int _row_number) : _matrix(matrix), _row_number(_row_number) {}
        double& operator[](const int col)
        { 
        	return _matrix.M[this->_row_number]*[col];
        }
        const double& operator[](const int col) const
        { 
        	return _matrix.M[this->_row_number]*[col];
        }		
	};

public:
	Matrix::Matrix(int num_rows, int num_cols);
	Matrix::Matrix(const Matrix& other);
	Matrix& Matrix::operator=(const Matrix &other);
	Matrix& Matrix::operator+=(const Matrix &other);
	Matrix& Matrix::operator-=(const Matrix &other);
	Matrix& Matrix::operator*=(const double constant);
	Matrix& Matrix::operator*=(const double constant);
	const Matrix Matrix::operator+(const Matrix &other) const;
	const Matrix Matrix::operator-(const Matrix &other) const;
	const Matrix Matrix::operator*(const double constant) const;
	const Matrix Matrix::operator/(const double constant) const;
	bool Matrix::operator==(const Matrix &other) const;
	bool Matrix::operator!=(const Matrix &other) const;
	Matrix::~Matrix();
	const Row& operator[](const int row) const;
	Row& operator[](const int row);
	friend ostream& operator<<(ostream& os, const Matrix& matrix); 
};

#endif
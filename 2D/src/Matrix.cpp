#include "Vector.h"
#include "Matrix.h"
#include <stdexcept>
#include <iostream>
#include <math.h>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols)
{
	this->num_rows = num_rows;
	this->num_cols = num_cols;
	this->M = new double* [num_rows];
	for(int i=0; i<this->num_rows; i++)
	{
		this->M[i] = new double[num_cols];
	}
}

Matrix::Matrix(const Matrix& other)
{
	this->num_rows = other.num_rows;
	this->num_cols = other.num_cols;

	this->M = new double*[this->num_rows];
	for(int i=0; i<this->num_rows; i++)
	{
		this->M[i] = new double[this->num_cols];
	}

	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<this->num_cols; j++)
		{
			this->M[i][j] = other.M[i][j];
		}
	}
}

Matrix& Matrix::operator=(const Matrix &other)
{
	if(this == &other)
	{
		return *this;
	}

	if(this->num_rows != other.num_rows || this->num_cols != other.num_cols)
	{
		throw std::runtime_error("DIMENSOES DIFERENTES");	
	}

	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<this->num_cols; j++)
		{
			this->M[i][j] = other.M[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator=(const double constant)
{
	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<this->num_cols; j++)
		{
			this->M[i][j] = constant;
		}
	}

	return *this;
}

Matrix& Matrix::operator+=(const Matrix &other)
{
	if(this->num_rows != other.num_rows || this->num_cols != other.num_cols)
	{
		throw std::runtime_error("DIMENSOES DIFERENTES");	
	}

	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<this->num_cols; j++)
		{
			this->M[i][j] += other.M[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator+=(const double constant)
{
	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<this->num_cols; j++)
		{
			this->M[i][j] += constant;
		}
	}

	return *this;
}

Matrix& Matrix::operator-=(const double constant)
{
	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<this->num_cols; j++)
		{
			this->M[i][j] -= constant;
		}
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix &other)
{
	if(this->num_rows != other.num_rows || this->num_cols != other.num_cols)
	{
		throw std::runtime_error("DIMENSOES DIFERENTES");	
	}

	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<this->num_cols; j++)
		{
			this->M[i][j] -= other.M[i][j];
		}
	}

	return *this;
}


Matrix& Matrix::operator*=(const double constant)
{
	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<this->num_cols; j++)
		{
			this->M[i][j] *= constant;
		}
	}

	return *this;
}


Matrix& Matrix::operator/=(const double constant)
{
	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<this->num_cols; j++)
		{
			this->M[i][j] /= constant;
		}
	}

	return *this;
}

const Matrix Matrix::operator+(const double constant) const 
{
	Matrix result = *this;
	result += constant;
	return result;
}

const Matrix Matrix::operator-(const double constant) const 
{
	Matrix result = *this;
	result -= constant;
	return result;
}

const Matrix Matrix::operator+(const Matrix &other) const 
{
	Matrix result = *this;
	result += other;
	return result;
}

const Matrix Matrix::operator-(const Matrix &other) const 
{
	Matrix result = *this;
	result -= other;
	return result;
}

const Matrix Matrix::operator*(const double constant) const 
{
	Matrix result = *this;
	result *= constant;
	return result;
}

const Matrix Matrix::operator/(const double constant) const 
{
	Matrix result = *this;
	result /= constant;
	return result;
}

bool Matrix::operator==(const Matrix &other) const
{
	if(this->num_rows != other.num_rows || this->num_cols != other.num_cols)
	{
		throw std::runtime_error("DIMENSOES DIFERENTES");	
	}

	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<this->num_cols; j++)
		{
			if(this->M[i][j] != other.M[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix &other) const
{
	return !(*this == other);
}

Matrix::~Matrix()
{
	for(int i=0; i<this->num_rows; i++)
	{
		delete this->M[i];
	}
	delete this->M;
}

ostream& operator<<(ostream& os, const Matrix& matrix)
{
	for(int i=0; i<matrix.num_rows; i++)
	{
		for(int j=0; j<matrix.num_cols; j++)
		{
			os << matrix.M[i][j] << " ";
		}
		os << endl;
	}
	return os;	
}

Matrix::Row Matrix::operator[](const int row)
{
	return Matrix::Row(*this, row);
}

const Matrix operator*(int constant, const Matrix& matrix)  
{  
    return matrix*(double)constant;  
}  

const Matrix operator*(float constant, const Matrix& matrix)  
{  
    return matrix*(double)constant;  
} 

const Matrix operator*(double constant, const Matrix& matrix)  
{  
    return matrix*constant;  
}

const Matrix operator+(int constant, const Matrix& matrix)  
{  
    return matrix+(double)constant;  
}  

const Matrix operator+(float constant, const Matrix& matrix)  
{  
    return matrix+(double)constant;  
} 

const Matrix operator+(double constant, const Matrix& matrix)  
{  
    return matrix+constant;  
}

const Matrix operator-(int constant, const Matrix& matrix)  
{  
    return (-1)*matrix+(double)constant;  
}  

const Matrix operator-(float constant, const Matrix& matrix)  
{  
    return (-1)*matrix+(double)constant;  
} 

const Matrix operator-(double constant, const Matrix& matrix)  
{  
    return (-1)*matrix+constant;  
}

const Matrix Matrix::I(int num_rows, int num_cols)
{
	Matrix I(num_rows, num_cols);
	for(int i=0; i<num_rows; i++)
	{
		for(int j=0; j<num_cols; j++)
		{
			I[i][j] = i==j?1.0:0.0;
		}
	}
	return I;
}

const Matrix Matrix::T() const
{
	Matrix T(this->num_cols, this->num_rows);
	for(int i=0; i<T.num_rows; i++)
	{
		for(int j=0; j<T.num_cols; j++)
		{
			T[i][j] = this->M[j][i];
		}
	}
	return T;	
}

Matrix& Matrix::operator*=(const Matrix &other)
{
	(*this) = (*this) * other;
	return *this;
}

const Matrix Matrix::operator*(const Matrix &other) const 
{
	if(this->num_cols != other.num_rows)
	{
		throw std::runtime_error("DIMENSOES DIFERENTES");	
	}

	Matrix result(this->num_rows, other.num_cols);

	for(int i=0; i<this->num_rows; i++)
	{
		for(int j=0; j<other.num_cols; j++)
		{
			result[i][j] = 0.0;
			for(int k=0; k<this->num_cols; k++)
			{
				result[i][j] += this->M[i][k] * other.M[k][j];
			}
		}
	}

	return result;
}

const Vector Matrix::operator*(const Vector &other) const 
{
	int dimension = other.getDimension();

	if(this->num_cols != dimension)
	{
		throw std::runtime_error("DIMENSOES DIFERENTES");	
	}

	Vector result(this->num_rows);

	for(int i=0; i<this->num_rows; i++)
	{
		result[i] = 0.0;
		for(int j=0; j<dimension; j++)
		{
			result[i] += this->M[i][j] * other[j];
		}
	}

	return result;
}


const int Matrix::getNumRows() const
{
	return this->num_rows;
}

const int Matrix::getNumCols() const
{
	return this->num_cols;
}

Vector Matrix::solve(Vector b) const
{
	Matrix A = this->pivot(&b);
	//cout << "A: " << endl << A << endl << "b: " << b << endl;
	Vector x = Vector(A.num_rows);
	double f, s;

	for (int j = 0; j < A.num_rows - 1; j++)
	{
		for (int i = j + 1; i < A.num_rows; i++)
		{
			f = A[i][j] / A[j][j];
			for (int k = j; k < A.num_rows; k++)
			{
				A[i][k] -= A[j][k]*f;
			}
			b[i] -= b[j] * f;
		}
	}

	for (int i = A.num_rows - 1; i >= 0; i--)
	{
		s = 0;
		for (int j = A.num_rows - 1; j > i; j--)
		{
			s += A[i][j] * x[j];
		}
		x[i] = (b[i] - s) / A[i][i];
	}

	return x;
}

const Matrix Matrix::pivot(Vector* b) const
{
	Matrix P = *this;
	int pivot;

	for (int j = 0; j < P.num_cols - 1; j++)
	{
		pivot = j;
		for (int i = j + 1; i < P.num_rows; i++)
		{
			if (fabs(P[i][j]) > (fabs(P[pivot][j])))
			{
				pivot = i;
			}
			P.swapLines(pivot, j);
			(*b).swapLines(pivot, j);
		}
	}

	return P;
}

void Matrix::swapLines(const int line1, const int line2)
{
	double aux;
	for (int j = 0; j < this->num_cols; j++)
	{
		aux = this->M[line1][j];
		this->M[line1][j] = this->M[line2][j];
		this->M[line2][j] = aux;
	}
}

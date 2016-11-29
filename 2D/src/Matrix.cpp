#include "Matrix.h"
#include <stdexcept>
#include <iostream>

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

	if(this->num_rows != other.num_cols || this->num_cols != other.num_cols)
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
	if(this->num_rows != other.num_cols || this->num_cols != other.num_cols)
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
	if(this->num_rows != other.num_cols || this->num_cols != other.num_cols)
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
	if(this->num_rows != other.num_cols || this->num_cols != other.num_cols)
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
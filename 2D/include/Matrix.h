#ifndef MATRIX_H
#define MATRIX_H

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
	Matrix(int num_rows, int num_cols);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix &other);
};

#endif
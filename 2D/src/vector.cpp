#include "vector.h"
#include <stdexcept>

/*****************************
	INIT & DEINIT
*****************************/

Vector::Vector(const int n)
{
	size = n;
	elements = new int[size];
}

Vector::Vector(const Vector &other)
{
	size = other.size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
	{
		elements[i] = other.elements[i];
	}
}

Vector::~Vector()
{
	delete elements;
}

/*****************************
	SAME CLASS OPERATIONS
*****************************/

Vector& Vector::operator=(const Vector &rhs) 
{

	if(this->size != rhs.size) {
		throw std::runtime_error('DIMENSOES DIFERENTES');
	}

	if(this != &rhs)
	{
		delete this;
		this = new Vector(rhs.size);

		for(int i = 0; i < rhs.size; i++)
		{
			this->elements[i] = rhs.elements[i];
		}
	}

	return *this;
}

Vector& Vector::operator+=(const Vector &rhs) 
{

	if(this->size != rhs.size) {
		throw std::runtime_error('DIMENSOES DIFERENTES');
	}

	for(int i = 0; i < rhs.size; i++)
	{
		this->elements[i] = this->elements[i] + rhs.elements[i];
	}

	return *this;
}

Vector& Vector::operator-=(const Vector &rhs) 
{

	if(this->size != rhs.size) {
		throw std::runtime_error('DIMENSOES DIFERENTES');
	}

	for(int i = 0; i < rhs.size; i++)
	{
		this->elements[i] = this->elements[i] - rhs.elements[i];
	}

	return *this;
}

Vector& Vector::operator+(const Vector &other) const
{
	return Vector(*this) += other;
}

Vector& Vector::operator-(const Vector &other) const
{
	return Vector(*this) -= other;
}

bool Vector::operator==(const Vector &rhs) const
{
	if(this->size != rhs.size) {
		throw std::runtime_error('DIMENSOES DIFERENTES');
	}

	for (int i = 0; i < this->size; i++)
	{
		if (this->elements[i] != rhs.elements[i])
		{
			return false
		}
	}

	return true;
}

bool Vector::operator==(const Vector &rhs) const
{
	return !(*this == other);
}

/*****************************
	OTHER OPERATIONS
*****************************/

Vector & Vector::operator*=(const double rhs)
{
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = this->elements[i] * rhs;
	}
}

Vector & Vector::operator/=(const double rhs)
{
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = this->elements[i] / rhs;
	}
}

Vector& Vector::operator*(const double other) const
{
	return Vector(*this) *= other;
}

Vector& Vector::operator/(const double other) const
{
	return Vector(*this) /= other;
}

const double& Vector::operator[](const int index) const
{
	return this->elements[index];
}

double& Vector::operator[](const int index)
{
	return this->elements[index];
}

/*****************************
	OTHER FUNCTIONS
*****************************/

const int Vector::getDimension(const Vector &v) const
{
	return v.size;
}

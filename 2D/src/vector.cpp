#include "Vector.h"
#include <stdexcept>

using namespace std;

/*****************************
	INIT & DEINIT
*****************************/

Vector::Vector(const int n)
{
	size = n;
	elements = new double[size];
}

Vector::Vector(const Vector &other)
{
	size = other.size;
	elements = new double[size];
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
		throw std::runtime_error("DIMENSOES DIFERENTES");
	}

	if(this != &rhs)
	{
		for(int i = 0; i < rhs.size; i++)
		{
			this->elements[i] = rhs.elements[i];
		}
	}

	return *this;
}

Vector & Vector::operator=(const double rhs)
{
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = rhs;
	}

	return *this;
}

Vector& Vector::operator+=(const Vector &rhs) 
{
	if(this->size != rhs.size) {
		throw std::runtime_error("DIMENSOES DIFERENTES");
	}

	for(int i = 0; i < rhs.size; i++)
	{
		this->elements[i] = this->elements[i] + rhs.elements[i];
	}

	return *this;
}

Vector& Vector::operator+=(const double rhs) 
{
	for(int i = 0; i < this->size; i++)
	{
		this->elements[i] = this->elements[i] + rhs;
	}

	return *this;
}

Vector& Vector::operator-=(const Vector &rhs) 
{

	if(this->size != rhs.size) {
		throw std::runtime_error("DIMENSOES DIFERENTES");
	}

	for(int i = 0; i < rhs.size; i++)
	{
		this->elements[i] = this->elements[i] - rhs.elements[i];
	}

	return *this;
}

Vector& Vector::operator-=(const double rhs) 
{
	for(int i = 0; i < this->size; i++)
	{
		this->elements[i] = this->elements[i] - rhs;
	}

	return *this;
}

const Vector Vector::operator+(const Vector &other) const
{
	return Vector(*this) += other;
}

const Vector Vector::operator+(const double other) const
{
	return Vector(*this) += other;
}

const Vector operator+(int constant, const Vector& v)
{
	return v + (double)constant;  
}

const Vector operator+(float constant, const Vector& v)
{
	return v + (double)constant;  
}

const Vector operator+(double constant, const Vector& v)
{
	return v + constant;  
}

const Vector Vector::operator-(const Vector &other) const
{
	return Vector(*this) -= other;
}

const Vector Vector::operator-(const double other) const
{
	return Vector(*this) -= other;
}

const Vector operator-(int constant, const Vector& v)
{
	return (-1 * v) + (double)constant;  
}

const Vector operator-(float constant, const Vector& v)
{
	return (-1 * v) + (double)constant;  
}

const Vector operator-(double constant, const Vector& v)
{
	return (-1 * v) + constant;  
}

bool Vector::operator==(const Vector &other) const
{
	if(this->size != other.size) {
		throw std::runtime_error("DIMENSOES DIFERENTES");
	}

	for (int i = 0; i < this->size; i++)
	{
		if (this->elements[i] != other.elements[i])
		{
			return false;
		}
	}

	return true;
}

bool Vector::operator!=(const Vector &other) const
{
	return !(*this == other);
}

/*****************************
	OTHER OPERATIONS
*****************************/

Vector& Vector::operator*=(const double rhs)
{
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = this->elements[i] * rhs;
	}

	return *this;
}

Vector& Vector::operator/=(const double rhs)
{
	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = this->elements[i] / rhs;
	}

	return *this;
}

const Vector Vector::operator*(const double other) const
{
	return Vector(*this) *= other;
}

const Vector operator*(int constant, const Vector& v)
{
	return v * (double)constant;  
}

const Vector operator*(float constant, const Vector& v)
{
	return v * (double)constant;  
}

const Vector operator*(double constant, const Vector& v)
{
	return v * constant;  
}

const Vector Vector::operator/(const double other) const
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

const int Vector::getDimension() const
{
	return this->size;
}

ostream& operator<<(ostream& os, const Vector& other)
{
	os << '[';
	for (int i = 0; i < other.size; i++)
	{
		os << other.elements[i] << ", ";
	}
	os << ']';

	return os;
}

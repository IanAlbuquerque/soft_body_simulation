#include <iostream>

using namespace std;

class Vector
{
	private:
		double* elements;
		int size;
	public:
		Vector(const int n); //T
		Vector(const Vector &other); //T
		~Vector();
		//Same class operations
		Vector & operator=(const Vector &rhs); //T
		Vector & operator+=(const Vector &rhs); //T
		Vector & operator-=(const Vector &rhs); //T
		const Vector operator+(const Vector &other) const; //T
		const Vector operator-(const Vector &other) const; //T
		bool operator==(const Vector &other) const; //T
		bool operator!=(const Vector &other) const; //T
		//Other operations
		Vector & operator*=(const double rhs); //T
		Vector & operator/=(const double rhs); //T
		const Vector operator*(const double other) const; //T
		const Vector operator/(const double other) const; //T
		const double& operator[](const int index) const; //T
		double& operator[](const int index); //T
		//Other functions
		const int getDimension() const; //T
		friend ostream& operator<<(ostream& os, const Vector& other); //T
};

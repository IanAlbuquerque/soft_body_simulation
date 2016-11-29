
class Vector
{
	private:
		double* elements;
		int size;
	public:
		Vector(const int n);
		Vector(const Vector &other);
		~Vector();
		//Same class operations
		Vector & operator=(const Vector &rhs);
		Vector & operator+=(const Vector &rhs);
		Vector & operator-=(const Vector &rhs);
		Vector & operator+(const Vector &other) const;
		Vector & operator-(const Vector &other) const;
		bool operator==(const Vector &rhs);
		bool operator!=(const Vector &rhs);
		//Other operations
		Vector & operator*=(const double rhs);
		Vector & operator/=(const double rhs);
		Vector & operator*(const double other) const;
		Vector & operator/(const double other) const;
		const double& operator[](const int index) const;
		double& operator[](const int index);
		//Other functions
		const int getDimension(const Vector &v) const;
};

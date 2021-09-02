#ifndef VECTORN_H
#define VECTORN_H
#include <iostream>

/*
 * Header file for  the VectorN class
 * Author: Jeff Byerly
 * Zid: Z1860060
 * Date: 3/27/19
*/


class VectorN
{
	friend std::ostream& operator<<(std::ostream& lhs, const VectorN& rhs);
	friend VectorN operator*(const double,const VectorN&); 

	private:
	double* vArray;
	size_t vCapacity;

	public:
	VectorN();
	VectorN(const double*, size_t);
	VectorN(const VectorN&);
	~VectorN();
	VectorN& operator=(const VectorN&);
	void clear();
	size_t size() const;
	VectorN operator+(const VectorN&) const;
	VectorN operator-(const VectorN&) const;
	double operator*(const VectorN&) const;
	VectorN operator*(const double) const;
	double operator[](int) const;
	double& operator[](int);
	bool operator==(const VectorN&) const;

};
#endif

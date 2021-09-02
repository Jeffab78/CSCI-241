/*
Name: Jeff Byerly
Zid: Z1860060
Date: 3/27/19
*/

#include "VectorN.h"
#include <iostream>
using namespace std;

VectorN::VectorN() //default constructor
{
	vCapacity=0;
	vArray=nullptr;
}

/*
Constructor
Use: initializes the object
Arguments: uses an array of doubles and an insigned int as it's size
*/
VectorN::VectorN(const double values[],size_t n)  
{
	vCapacity=n;
	if (n==0)
		vArray=nullptr;
	else
		vArray= new double[vCapacity];
       for (size_t i=0; i < vCapacity; ++i)
       	{
 		vArray[i]=values[i];
	}

}

/*
Copy constructor
Use: Used to copy the value of another object
Arguments: takes in a reference to another VectorN object
*/
VectorN::VectorN(const VectorN& other) 
{

	vCapacity=other.vCapacity;
	if (vCapacity==0)
		vArray=nullptr;
	else
		vArray=new double[vCapacity];
	for (size_t i=0; i < vCapacity; ++i)
	{	
		vArray[i]=other.vArray[i];
	}
}


VectorN::~VectorN() //The dectructor for the VectorN class. calls the clear() method.
{
	clear();
}

void VectorN::clear() // deallocates the memory used by the object.
{
	delete vArray;
	vArray=nullptr;
	vCapacity=0;
}

/*
Method: size()
Use: used to find the size of the vector
Arguments: takes in no arguments
Returns: returns the vCapacity of the object
*/
size_t VectorN::size() const 
{
	return vCapacity;
}

/*
Function: operator<<
Use: overloads the << operator to output the vector objects
Arguments: takes in a reference to an ostream object and a reference to a const VectorN
Returns: Returns the new ostream object
*/
ostream& operator<<(ostream& lhs, const VectorN& rhs) //overloaded output operator
{
	size_t i;

	if (rhs.vCapacity==0)
		lhs << "()";
	else
	{
		lhs << "(";
		for (i=0; i <(rhs.vCapacity-1);++i)
		{
			lhs << rhs.vArray[i] << ", ";
		}
		lhs << rhs.vArray[i] <<  ")";
	}
	return lhs;
}

/*
Method: operator[] const version
Use: overloads the subscript operator
Arguments: takes an int
Returns: returns element "sub" of vArray
*/
double VectorN::operator[](int sub) const
{
	return vArray[sub];
}

/*
Method: operator[] non-const version
Use: overloads the subscript operator
Arguments: takes an int
Returns: returns element "sub" of vArray
*/
double& VectorN::operator[](int sub)
{
	return vArray[sub];
}

/*
Method: operator=() 
Use: Assigns one vectorn object other to the other
Arguments: takes in a reference to a VectorN object
Returns: returns a reference to the new VectorN object
*/
VectorN& VectorN::operator=(const VectorN& other)
{
	if (this==&other)
		return *this;
	else
	{
		delete this->vArray;
		this->vCapacity=other.vCapacity;

		if (other.vCapacity==0)
			this->vArray=nullptr;
		else
			this->vArray=new double[vCapacity];

		for (size_t i=0; i<vCapacity; ++i)
		{
			vArray[i]=other.vArray[i];
		}
	return *this;
	};
}

/*
Method: operator+
Use: Adds two VectorN together
Arguments: takes in two VectorN's
Returns: returns the new VectorN
*/
VectorN VectorN::operator+(const VectorN& rhs) const
{
	VectorN result;
	if(vCapacity<rhs.vCapacity)
		result.vCapacity=vCapacity;
	else
		result.vCapacity=rhs.vCapacity;

	result.vArray=new double[result.vCapacity];

	for (size_t i=0; i<result.vCapacity;++i)
	{
		result.vArray[i]=vArray[i]+rhs.vArray[i];
	}
	return result;
}
/*
Method: operator-
Use: used to subtract one VectorN from another
Arguments: takes two Vectorn
Returns: returns the new VectorN
*/
VectorN VectorN::operator-(const VectorN& rhs) const
{
	VectorN result;

	if(vCapacity<rhs.vCapacity)
		result.vCapacity=vCapacity;
	else
		result.vCapacity=rhs.vCapacity;

	result.vArray=new double[result.vCapacity];

	for (size_t i=0; i<result.vCapacity;++i)
	{
		result.vArray[i]=vArray[i]-rhs.vArray[i];
	}
	return result;
}
/*
Method: operator*
Use: multiplies two VectorN's to get a single double
Arguments: takes two VectorN objects
Returns: returns a double which is the result of the multiplication
*/
double VectorN::operator*(const VectorN& rhs) const
{
	double result=0.0;


	for (size_t i=0; i<vCapacity && i<rhs.vCapacity; ++i)
		result+=(vArray[i]*rhs.vArray[i]);
	return result;
}
/*
Method: operator*
Use: Multiplies a VectorN object by a double
ArgumentS: takes a VectorN object and a const double
Returns: returns a new VectorN object of the result
*/
VectorN VectorN::operator*(const double rhs) const
{
	VectorN result;
	result.vCapacity=this->vCapacity;
	
	result.vArray=new double[result.vCapacity];

	for (size_t i=0;i<vCapacity;++i)
		result.vArray[i]=vArray[i]*rhs;
	return result;
}

/*
Method: operator*
Use: multiplies a double by a vectorN object
Arguments: takes a const double and a vectorN object
Returns: a new vectorN object of the  result
*/
VectorN operator*(const double a,const VectorN& rhs) 
{
	VectorN result;
	result.vCapacity=rhs.vCapacity;
	
	result.vArray=new double[result.vCapacity];

	for (size_t i=0;i<rhs.vCapacity;++i)
		result.vArray[i]=a*rhs.vArray[i];
	return result;
}
/*
Method: operator==
Use: compares two VectorN objects
Arguments: takes two VectorN objects
Returns: a bool of whether or no they are equal
*/
bool VectorN::operator==(const VectorN& lhs) const
{	
	size_t max;
	if (vCapacity!=lhs.vCapacity)
		return false;
	else
		max=vCapacity;

	for (size_t i=0;i<max;++i)
	{
		if (vArray[i]!=lhs.vArray[i])
			return false;
	}
	return true;
}

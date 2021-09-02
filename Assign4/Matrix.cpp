/*
 * Name: Jeff Byerly
 * ZID: z1860060
 * Date: 3/19/19
 */

#include "Matrix.h"
#include <iostream>
using namespace std;


Matrix::Matrix() //Default constructor
{
	matrixArray[0][0]=1;
	matrixArray[0][1]=0;
	matrixArray[1][0]=0;
	matrixArray[1][1]=1;
}

Matrix::Matrix(int array[][2]) //Constructor with a passed in array
{
	matrixArray[0][0]=array[0][0];
	matrixArray[0][1]=array[0][1];
	matrixArray[1][0]=array[1][0];
	matrixArray[1][1]=array[1][1];
}


/*
Method: determinant()
Use: used to find the determinant of a Matrix
Arguments: Takes no arguments
Returns: returns an int that is the determinant
*/
int Matrix::determinant() const
{
	int determ=(matrixArray[0][0]*matrixArray[1][1])-(matrixArray[0][1]*matrixArray[1][0]);
	return determ;
}


/*
Method: operator+
Use: adds two Matrices together
Arguments: Takes in a reference to a const Matrix object
Returns: returns the new Matrix object
*/
Matrix Matrix::operator +(const Matrix& rhs) const
{
	Matrix result; //declare temp object to hold result

	result.matrixArray[0][0]=this->matrixArray[0][0]+rhs.matrixArray[0][0];
	result.matrixArray[0][1]=this->matrixArray[0][1]+rhs.matrixArray[0][1];
	result.matrixArray[1][0]=this->matrixArray[1][0]+rhs.matrixArray[1][0];
	result.matrixArray[1][1]=this->matrixArray[1][1]+rhs.matrixArray[1][1];

	return result;

}


/*
Method: operator*
Use: multiplies a Matrix by an int
Arguments: Takes in an int
Returns: returns the new Matrix object
*/
Matrix Matrix::operator*(int rhs) const
{
	Matrix result;

	result.matrixArray[0][0]=this->matrixArray[0][0]*rhs;
	result.matrixArray[0][1]=this->matrixArray[0][1]*rhs;
	result.matrixArray[1][0]=this->matrixArray[1][0]*rhs;
	result.matrixArray[1][1]=this->matrixArray[1][1]*rhs;

	return result;
}



/*
Method: operator*
Use: multiplies two Matrices together
Arguments: Takes in a reference to a const Matrix object
Returns: returns the new Matrix object
*/

Matrix Matrix::operator*(const Matrix& rhs) const
{
	Matrix result;
	
	result.matrixArray[0][0]=(this->matrixArray[0][0]*rhs.matrixArray[0][0])+(this->matrixArray[0][1]*rhs.matrixArray[1][0]);
	result.matrixArray[0][1]=(this->matrixArray[0][0]*rhs.matrixArray[0][1])+(this->matrixArray[0][1]*rhs.matrixArray[1][1]);
	result.matrixArray[1][0]=(this->matrixArray[1][0]*rhs.matrixArray[0][0])+(this->matrixArray[1][1]*rhs.matrixArray[1][0]);
	result.matrixArray[1][1]=(this->matrixArray[1][0]*rhs.matrixArray[0][1])+(this->matrixArray[1][1]*rhs.matrixArray[1][1]);

	return result;
}


/*
Method: operator==
Use: checks if two matrices are equal 
Arguments: Takes in a reference to a const Matrix object
Returns: returns a bool
*/

bool Matrix::operator==(const Matrix& rhs) const
{
	if (this->matrixArray[0][0]==rhs.matrixArray[0][0] && this->matrixArray[0][1]==rhs.matrixArray[0][1] && this->matrixArray[1][0]==rhs.matrixArray[1][0] && this->matrixArray[1][1]==rhs.matrixArray[1][1])
		return true;
	else
		return false;
}



/*
Method: operator!=
Use: checks if two matrices are not equal 
Arguments: Takes in a reference to a const Matrix object
Returns: returns a bool
*/
bool Matrix::operator!=(const Matrix& rhs) const
{
	if (this->matrixArray[0][0]==rhs.matrixArray[0][0] && this->matrixArray[0][1]==rhs.matrixArray[0][1] && this->matrixArray[1][0]==rhs.matrixArray[1][0] && this->matrixArray[1][1]==rhs.matrixArray[1][1])
		return false;
	else
		return true;
}


ostream& operator<<(ostream& lhs, const Matrix& rhs)
{
	lhs << "[[" << rhs.matrixArray[0][0] << ", " << rhs.matrixArray[0][1] << "], [" << rhs.matrixArray[1][0] << ", " << rhs.matrixArray[1][1] << "]]";
	return lhs;
}

Matrix operator*(int lhs,const Matrix& rhs)
{
	Matrix result;

	result.matrixArray[0][0]=rhs.matrixArray[0][0]*lhs;
	result.matrixArray[0][1]=rhs.matrixArray[0][1]*lhs;
	result.matrixArray[1][0]=rhs.matrixArray[1][0]*lhs;
	result.matrixArray[1][1]=rhs.matrixArray[1][1]*lhs;

	return result;
}

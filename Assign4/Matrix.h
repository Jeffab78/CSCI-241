#ifndef  MATRIX_H
#define MATRIX_H
#include <iostream>

/*
 * Declaration for the Matrix class
 *
 * Author: Jeff Byerly 
 * Zid: z1860060
 * Date: 3/7/19
 */

class Matrix
{
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend Matrix operator*(int, const Matrix&);

	private:
		int matrixArray[2][2];
	public:
		Matrix();
		Matrix(int[][2]);
		int determinant() const;
		Matrix operator+(const Matrix&) const;
	       	Matrix operator*(int) const;
		Matrix operator*(const Matrix&) const;
		bool operator==(const Matrix&) const;
	 	bool operator!=(const Matrix&) const;	
};
#endif

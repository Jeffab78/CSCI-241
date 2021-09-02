#include "Seller.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 Default constructor for the Seller class
*/
Seller::Seller()
{
}

/*
 Constructor for the Seller class that that builds new Seller objects
*/
Seller::Seller(const char* newName, double newSalesTotal)
{
	strcpy(name,newName);
	salesTotal=newSalesTotal;
}

/*
Method:getName
Use: Used to get the name data member
Arguments: takes in no arguments
Returns: returns the name data member of the Seller object
*/
const char* Seller::getName() const
{
	return name;
}

/*
Method: getSalesTotal
Use: Used to get the sales total data member
Arguments: takes in no arguments
Returns: returns the sales total data member of the Seller object.
*/
double Seller::getSalesTotal() const
{
	return salesTotal;
}

/*
Method: setSalesTotal
Use: Used to modify the salesTotal data member of the Seller class
Arguments: takes in a double of what the data member should be set to
Returns: Returns nothing
*/
void Seller::setSalesTotal(double newSalesTotal)
{
	salesTotal=newSalesTotal;
}

/*
Method: print
Use: prints out the name and salesTotal data members
Arguments: takes no arguments
Returns: returns nothing
*/
void Seller::print() const
{
	cout << left << setw(30) << name;
	cout << right << setw(9) << salesTotal;
}

	

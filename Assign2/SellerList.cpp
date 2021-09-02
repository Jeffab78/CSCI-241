#include "SellerList.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

/*
Default constructor for the SellerList class
*/
SellerList::SellerList()
{
	numSellers=0;
}
/*
Constructor for the SellerList class to input the file data and build objects

*/
SellerList::SellerList(const string& fileName)
{
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.fail())//exits with error message if fails to open
	{
		cout << "file did not open";
		exit(-1);
	}

	inFile.read((char*) this, sizeof(SellerList));
	

	sortSellers(); //sorts the array of Seller objects
}
/*
Method:print()
Use: prints out the array of Seller objects with their names and sales total
Arguments: takes none
Returns: Returns nothing
*/
void SellerList::print() const
{
	cout << endl << "Seller Listing" << endl;
	cout << left << setw(30) <<  "Name" << right << setw(9) << "Sales\n\n";
	for (int i=0; i<numSellers ; i++)
	{ 	
		list[i].print();
		std::cout << endl;
	}
}

/*
Method: sortSellers()
Use: Sorts the Seller array in alphabetic order
Arguments: takes no arguments
Returns: returns nothing
*/
void SellerList::sortSellers()
{
	int i,j;
	Seller bucket;

	for (i=0; i < numSellers; i++)
	{
		bucket=list[i];
		for (j=i; (j>0) && (strcmp(list[j-1].getName(), bucket.getName()) > 0); j--)
				list[j]=list[j-1];
		list[j]=bucket;
	}
}
/*
Method: searchForSeller
Use: searches for a sellers name in the array and returns it's element number
Arguments: takes in a pointer to a char const of a name to be searched
Returns: an integer that is the location of the name in the array
*/
int SellerList::searchForSeller(const char* searchName) const
{
	int low =0;
	int high= numSellers;
	int mid;

	while (low<= high)
	{
		mid = (low +high) /2;

		if (strcmp(searchName,list[mid].getName())==0)
			return mid;
		if (strcmp(searchName,list[mid].getName())<0)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

/*
Method: processSalesData
Use: reads sales records and searches the array to see if the Seller exists and then updates their sales totals.
Arguments: takes in a string const
Returns: returns nothing
*/
void SellerList::processSalesData(const string& fileName)
{
	ifstream inFile;
	char lastName[21];
	char firstName[11];
	double salesAmount;
	char name[31];

	inFile.open(fileName);
	if (inFile.fail())
	{
		cout << "File did not open";
		exit(-1);
	}

	cout << left <<  "\n Sales Transactions\n\n"; 

	inFile >> lastName;
	while (inFile) 

	{
		inFile >> firstName;
		inFile >> salesAmount;

		strcat(lastName,", ");
		strcat(lastName, firstName);
		strcpy(name,lastName);
		

		int index = searchForSeller(name);
		if (index==-1)
			cout << name << " not found\n";
		else
		{
			cout << name << " sold " << salesAmount;
			cout << endl;
			list[index].setSalesTotal((list[index].getSalesTotal()+salesAmount));
		}
		inFile >> lastName;
	}
	inFile.close();
}


	

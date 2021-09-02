#ifndef SORTS_H
#define SORTS_H
/*Assignment 8
Name: Jeff Byerly
zid: z1860060
date: 4/22/19
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//template declarations
template <class T>
void builList(vector<T>&,const char*);

template <class T>
void printList(const vector<T>&, int, int);

template <class T>
bool lessThan(const T&, const T&);

template <class T>
bool greaterThan(const T&, const T&);

//function definitions
template <class T>
void buildList(vector<T>& set,const char* fileName)
{
	T item;
	ifstream inFile;
	inFile.open(fileName);
	if(!inFile)
		perror("File did not open");

	inFile >> item;
	while (inFile)
	{
		set.push_back(item);
		inFile >> item;
	}
	inFile.close();
}
/*
function: printList
Use: Prints a list of items stored in a vector
Arguments: takes a reference to a const vector object and 2 ints
Returns: nothing
*/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	for (int i=0; i < (int) set.size(); i++)
	{
		cout << setw(itemWidth) << set[i];
		if ((i+1)%numPerLine==0)
			cout << endl;
	}	
}

/*
Function: lessThan
Use: determines if one item is less than another
Arguments: takes in two items of the template type
Returns: returns a bool
*/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
	if (item1 < item2)
		return true;
	else
		return false;
}
/*
Function: greaterThan
Use: determines if one item is less than another
Arguments: takes in two items of the template type
Returns: returns a bool
*/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	if (item1>item2)
		return true;
	else
		return false;
}

















#endif

#ifndef QUICKSORT_H
#define QUICKSORT_H
/*
Name: Jeff Byerly
Zid: z1860060
Date: 4/25/19
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//function declarations
template <class T>
void quickSort(vector<T>&, bool (*)(const T&,const T&));

template <class T>
void quickSort(vector<T>&, int, int, bool (*)(const T&, const T&));

template <class T>
int partition(vector<T>&, int, int, bool (*)(const T&, const T&));

//function definitions
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	quickSort(set, 0, set.size()-1,compare);
}

template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotPoint;

	if (start < end)
	{
		pivotPoint = partition(set, start, end, compare);
		quickSort(set, start, pivotPoint -1,compare);
		quickSort(set, pivotPoint +1, end, compare);
	}
}

template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotIndex, mid;
	T pivotValue,temp;

	mid = (start + end)/2;

	temp = set[start];
	set[start]=set[mid];
	set[mid]=temp;

	pivotIndex=start;
	pivotValue=set[start];

	for (int scan = start +1; scan<= end; scan++)
	{
		if (compare(set[scan],pivotValue))
		{
			++pivotIndex;
			temp =set[pivotIndex];
			set[pivotIndex]=set[scan];
			set[scan]=temp;
		}
	}

	temp = set[start];
	set[start]=set[pivotIndex];
	set[pivotIndex]=temp;

	return pivotIndex;
}
















#endif

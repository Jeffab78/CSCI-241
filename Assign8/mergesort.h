#ifndef MERGESORT_H
#define MERGESORT_H
/*
Name: Jeff Byerly
Zid: z1860060
Date: 4/25/19
*/

#include <iostream>
#include <iomanip>

using namespace std;

//function declarations
template <class T>
void mergeSort(vector<T>&, bool (*)(const T&, const T&));

template <class T>
void mergeSort(vector<T>&,int, int, bool (*)(const T&, const T&));

template <class T>
void merge(vector<T>&, int, int, int, bool (*)(const T&, const T&));


//////function definitions/////

//this function calls the recursive function to sort it
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	mergeSort(set, 0, set.size()-1,compare);
}
//this recursive function divides a vector into two subvectors, sorts them, and then merges them
template <class T>
void mergeSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int mid;
	
	if (start < end)
	{
		mid = (start+end)/2;

		mergeSort(set,start,mid,compare);
		mergeSort(set, mid+1, end, compare);

		merge (set, start, mid, end, compare);
	}
}
//this function merges two sorted subvectors
template <class T>
void merge(vector<T>& set, int start, int mid, int end, bool (*compare)(const T&, const T&))
{
	vector<T> temp(end - start +1);

	int i= start;
	int j = mid+1;
	int k = 0;

	while (i<= mid && j <=end)
	{
		if (compare(set[i],set[j]))
		{
			temp[k]=set[i];
			i++;
			k++;
		}
		else
		{
			temp[k]=set[j];
			j++;
			k++;
		}
	}

	while ( i<=mid)
	{
		temp[k]=set[i];
		i++;
		k++;
	}

	while ( j<=end)
	{
		temp[k]=set[j];
		j++;
		k++;
	}

	for (i =0, j = start; j<=end; ++i, ++j)
		set[j]=temp[i];
}





















#endif

/*
Name: Jeff Byerly
ZID: z1860060
Date Due: 4/11/19
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack;

template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

template <class T>
class Stack
{
	friend ostream& operator<< <>(ostream&, const Stack<T>&);

	private:

	T* stackArray;
	size_t stackCap;
	size_t stackSize;
	
	public:
	Stack(); 
	~Stack();
	Stack(const Stack&);
	Stack<T>& operator=(const Stack<T>&);
	void clear();
	const size_t size() const;
	const size_t capacity() const;
	const bool empty() const;
	const T& top() const;
	void push(const T&);
	void pop();
	void reserve(size_t);
	


};

//*****************method definitions*****************

/*
Default constructor
*/
template <class T>
Stack<T>::Stack()
{
	stackSize=0;
	stackCap=0;
	stackArray=nullptr;
}

/*
Class Destructor
*/
template <class T>
Stack<T>::~Stack()
{
	delete[] stackArray;
}

/*
Copy constructor
*/
template <class T>
Stack<T>::Stack(const Stack<T>& rhs)
{
	stackCap=rhs.stackCap;
	stackSize=rhs.stackSize;

	if (stackCap==0)
		stackArray=nullptr;
	else
		stackArray = new T[stackCap];
	for (size_t i = 0; i < stackSize; ++i)
		stackArray[i]=rhs.stackArray[i];
}
/*
Method: Copy Assignment operator 
Use: Overloads the assignment operator
Arguments: takes in a const reference to a T item
Returns: nothing
*/
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
{
	if (this==&rhs)
		return *this;

	stackCap=rhs.stackCap;
	stackSize=rhs.stackSize;

	if (stackCap==0)
		stackArray=nullptr;
	else
		stackArray = new T[stackCap];
	for (size_t i = 0; i < stackSize; ++i)
		stackArray[i]=rhs.stackArray[i];
	return *this;


}
/*
Overloaded output operator
*/
template <class T>
ostream& operator<<(ostream& lhs, const Stack<T>& rhs)
{
	for (size_t i=0; i<rhs.stackSize; ++i)
	{
		lhs << rhs.stackArray[i] << " ";
	}
	return lhs;
}

/*
 Clear() function
*/
template <class T>
void Stack<T>::clear()
{
	stackSize=0;
}

/*
size() method
*/
template <class T>
const size_t Stack<T>::size() const
{
	return stackSize;
}

/*
Capacity method
*/
template <class T>
const size_t Stack<T>::capacity() const
{
	return stackCap;
}

/*
Empty() method
*/
template <class T>
const bool Stack<T>::empty() const
{
	if (stackSize==0)
		return true;
	else
		return false;
}
/*
Method: top()
Use: Returns the top element of the stack array
Arguments: none
Returns: the top element of the stack array
*/
template <class T>
const T& Stack<T>::top() const
{
	return stackArray[stackSize-1];
}
/*
Method: push()
Use: used to push something onto the stack
Arguments: Takes in a reference to a const item of the template type
Returns: nothing
*/
template <class T>
void Stack<T>::push(const T& val)
{
	if (stackSize==stackCap)
	{
		if (stackCap==0)
			reserve(1);
		else
			reserve(stackCap*2);
	}

	stackArray[stackSize]=val;
	++stackSize;
}
/*
Method: pop()
Use: Decrements the stack size by 1
Arguments: none
Returns: nothing
*/
template <class T>
void Stack<T>::pop()
{
	stackSize--;
}
/*
Method: reserve()
Use: Increases the stack capacity of the array
Arguments: takes a single integer
Returns: nothing
*/
template <class T>
void Stack<T>::reserve(size_t x)
{
	if (x<stackSize || x==stackCap)
		return;
	stackCap=x;
	T* temp;
	if (stackCap==0)
		temp=nullptr;
	else
		temp = new T[stackCap];
	for (size_t i=0;i<stackSize;++i)
	{
		temp[i]=stackArray[i];
	}

	delete[] stackArray;
	stackArray=temp;
}

#endif

/*
Assign7:
Name: Jeff Byerly
Zid: z1860060
Date: 4/18/2019
*/
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

template <class T>
struct Node;

template <class T>
struct Node //struct node declaration
{
	T data;
	Node<T>* next;

	Node(const T& = T(), Node<T>* next = nullptr);
};


template <class T>
Node<T>::Node(const T& data,Node* next) // node definition
{
	this->data=data;
	this->next=next;
}

template <class T>
class Queue;

template <class T>
ostream& operator<<(ostream&, const Queue<T>&);

template <class T>
class Queue //Queue class declaration
{
	friend ostream& operator<< <>(ostream&, const Queue<T>&);

	private:
	Node<T>* qFront;
	Node<T>* qBack;
	size_t qSize;
	void copyList(const Queue<T>&);

	public:
	Queue();
	~Queue();
	Queue(const Queue<T>&);
	Queue<T>& operator=(const Queue<T>&);
	const size_t size() const;
	const bool empty() const;
	void push(const T&);
	void clear();
	void pop();
	const T& front() const;
	const T& back() const;
};


//**************METHOD DEFINITIONS*************************************
//******************************************************************
/*
Overloaded output operator
*/
template <class T>
ostream& operator<<(ostream& lhs,const Queue<T>& rhs)
{
	Node<T>* ptr;

	for (ptr = rhs.qFront; ptr != nullptr;ptr= ptr->next)
		lhs << ptr->data << ' ';
	return lhs;
}

/*
Default constructor
*/
template <class T>
Queue<T>::Queue()
{
	qFront=nullptr;
	qBack=nullptr;
	qSize=0;
}

/*
Copy constructor
*/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
	qFront = qBack = nullptr;
	qSize=0;

	copyList(other);
}

/*
Copy assignment operator
*/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this !=&other)
	{	
		clear();
		copyList(other);
	}
	return *this;
}

/*
Method: size()
Use: gets the size of the Queue
Arguments: none
Returns: an unsigned int
*/
template <class T>
const size_t Queue<T>::size() const
{
	return qSize;
}

/*
Method: empty()
Use: finds out if the Queue is empty or not
Arguments: none
Returns: a bool
*/
template <class T>
const bool Queue<T>::empty() const
{
	if (qSize==0)
		return true;
	else
		return false;
}

/*
Method: push()
Use: pushin an item onto the Queue
Arguments: a reference to a const T item
Returns: nothing
*/
template <class T>
void Queue<T>::push(const T& val)
{
	Node<T>* newNode = new Node<T>(val);

	if (qSize==0)
		qFront=newNode;
	else
		qBack->next=newNode;

	qBack=newNode;
	++qSize;
}

/*
Method: copyList()
Use: copies the linked list
Arguments: a linked list to be copied
Returns: nothing
*/
template <class T>
void Queue<T>::copyList(const Queue<T>& other)
{
	Node<T>* ptr;

	for (ptr=other.qFront; ptr != nullptr; ptr = ptr->next)
		push(ptr->data);
}

/*
Method: clear()
Use: empties out the Queue
Arguments: none
Returns: nothing
*/
template <class T>
void Queue<T>::clear()
{
	while (qSize!=0)
		pop();
}

/*
Method: pop()
Use: remove the from item from queue
Arguments: none
Returns: nothing
*/
template <class T>
void Queue<T>::pop()
{
	if (qSize==0)
		throw underflow_error("Queue underflow on pop()");

	Node<T>* delNode = qFront;
	qFront= qFront->next;

	if (qFront==nullptr)
		qBack=nullptr;
	delete delNode;
	--qSize;
}

/*
Method: front()
Use: returns the front node of the Queue
Arguments: none
Returns: a reference to a const item
*/
template <class T>
const T& Queue<T>::front() const
{
	if (qSize==0)
		throw underflow_error("Queue underflow on front()");
	return qFront->data;
}

/*
Method: back()
Use: returns the back node of the queue
Arguments: none
Returns: a reference to a const item
*/
template <class T>
const T& Queue<T>::back() const
{
	if (qSize==0)
		throw underflow_error("Queue underflow on back()");
	return qBack->data;
}
/*
Destructor
*/
template <class T>
Queue<T>::~Queue()
{
	clear();
}



#endif

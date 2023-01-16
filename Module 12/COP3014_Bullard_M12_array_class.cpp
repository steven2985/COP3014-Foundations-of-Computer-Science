#include <iostream>
#include "array_class.h"
using namespace std;

array_class::array_class()
{
	cout<<"Default Constructor has been called\n";
	capacity=10;
	count = 0;
	A = new int[capacity];
	/*for(count=0; count<5;count++)
	{
		A[count] = count;
	}*/
}

array_class::array_class(const array_class & Org)
{
	cout<<"Copy Constructor has been called\n";
	(*this).capacity = Org.capacity;
	this->count = Org.count;
		
	A = new int[capacity];

	for(int i=0;  i<count;i++)
	{
		A[i] = Org.A[i];
	}
}
array_class::~array_class()
{
	cout<<"Destructor has been called\n";
	delete [ ] A;
}

///****************************************************************
// OPERLOADING THE << OPERATOR AS A FRIEND FUNCTION OF THE CLASS
// WITHOUT CHAINING.   << ----- operator<<
// ****************************************************************/
//void operator<<(ostream & out, array_class & Org)
//{
//	for(int i=0; i<Org.count; i++)
//	{
//		out<<Org.A[i]<<endl;
//	}
//}

/****************************************************************
 OPERLOADING THE << OPERATOR AS A FRIEND FUNCTION OF THE CLASS
 WITH CHAINING.   << ----- operator<<
 ****************************************************************/
ostream & operator<<(ostream & out, array_class & Org)
{
	for(int i=0; i<Org.count; i++)
	{
		out<<Org.A[i]<<endl;
	}
	return out;
}

//array_class & operator+(array_class & org, int item)
//{
//	if (org.count< org.capacity)
//	{
//		org.A[org.count] = item;
//		org.count++;
//	}
//	else
//	{
//		cout<<"A is full\n";
//	}
//	return org;
//}

array_class & array_class::operator+(int item)
{
	//if (this->count < this->capacity)
	//if ((*this).count < (*this).capacity)
	if (count < capacity)
	{
		A[count] = item;
		count++;
	}
	else
	{
		cout<<"A is full\n";
	}
	return *this;
}


int operator*(array_class &  BB, int key)
{
	for(int i=0; i<BB.get_count(); i++)
	{
		if (BB.get_array_value(i) == key)
			return i;
	}
	return -1;

}

array_class & array_class::operator=(array_class & Org)
{
	cout<<"operator= has been called\n";

	if (this != &Org)
	{
		if (A != 0)
		{
			delete [] A;
		}
		count = 0;
		(*this).capacity = Org.capacity;
		this->count = Org.count;

		A = new int[capacity];

		for(int i=0;  i<count;i++)
		{
			A[i] = Org.A[i];
		}
		cout<<"count = "<<count<< endl;
	}
	return *this;
}

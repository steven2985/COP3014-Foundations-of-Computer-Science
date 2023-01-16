#include <iostream>
using namespace std;

#ifndef ARRAY_CLASS_H
#define ARRAY_CLASS_H
class array_class
{
public:
	array_class();
	array_class(const array_class &);  //copy constructor
	~array_class();

	//friend array_class & operator+(array_class &, int);
	array_class & operator+(int);

	void remove(int){};
	//friend void operator<<(ostream &, array_class &); //FRIEND NEEDED TO HERE TO GIVE OPERATOR<< PERMISSION TO THE STATE
	friend ostream & operator<<(ostream &, array_class &); //FRIEND NEEDED TO HERE TO GIVE OPERATOR<< PERMISSION TO THE STATE
	int get_count(){return count;};
	int get_array_value(int i){ return A[i];}
	array_class & operator=(array_class & );
	
private:
	int count;
	int capacity;
	int *A;
};

#endif
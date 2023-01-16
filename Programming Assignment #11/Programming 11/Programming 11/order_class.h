
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef ORDER_CLASS_A
#define ORDER_CLASS_A

class orderRecord
{
public:
	string pName;       // String variables for the names stored inside the file record
	string cName;
	double plantCost;   // Double variables for the different numerical amounts locate inside file record
	int quantity;       // Integer variable for quantity 
	double netCost;
	double taxRate;
	double purchaseTax;
	double discount;
	double totalCost;
};



class orderClass
{
public:
	orderClass();
	~orderClass(); //de-allocates all memory allocate to STR by operator new.
	bool isEmpty(); //inline implementation
	bool isFull();//inline implementation
	int search(const string key);//returns location of key if in STR; otherwise return -1
	void add(); //adds a order record to STR
	orderClass& operator-(const string key); //removes all items in STR with a plant name that matches key.
	void doubleSize();
	void process();
	friend ostream& operator<<(ostream& out, orderClass& ORG); //prints all the elements in ORG's STR to the screen
private:
	int count;
	int size;
	orderRecord* STR;
};

#endif
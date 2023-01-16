#include <iostream>
#include <fstream>
#include <iomanip>
#include "order_class.h"
using namespace std;


/************************************************************************************************************************************/
//Name: default constructor
//Precondition: File record was successfully opened
//Postcondition: Data inside the text file is readed
//Decription: Reads the data file of purchase order information (plant name, county name, plant cost and quantity) into the dynamic array of order records, 
//STR. If the count become equal to the size the function double_size is called and the memory allocated to STR is doubled.
/************************************************************************************************************************************/

orderClass::orderClass()
{
	count = 0;
	size = 1;
	STR = new orderRecord[size];
	ifstream in;
	in.open("nursery_stock.txt");

	if (in.fail())
	{
		cout << "Input file failed to open";
	}

	while (!in.eof())
	{
		if (count == size)
		{
			doubleSize();
		}
		in >> STR[count].pName;
		in >> STR[count].cName;
		in >> STR[count].plantCost;
		in >> STR[count].quantity;
		count++;
	}

	in.close();
	cout << "The default constructor has been called\n";

}

/***********************************************************************************************************************************/
//Name: isEmpty
//Precondition: File record was successfully opened
//Postcondition: Data inside the text file is readed
//Decription: returns true if STR is empty
/**********************************************************************************************************************************/

bool orderClass::isEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: isFull 
//Precondition: File record was successfully opened
//Postcondition: Data inside the text file is readed
//Decription: returns true if STR is full
/*********************************************************************************************************************************/

bool orderClass::isFull()
{
	if (count == size)
	{
		return true;
	}
	else
	{
		return false;
	}
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: Values were added to the array successfully
//Postcondition: Search for values in the array
//Decription: locates key in STR if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/

int orderClass::search(const string key)
{
	for (int i = 0; i < count; i++)
	{
		if (STR[i].pName == key)
		{
			return i;
		}
	}
	return -1;
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: Values were added to the array successfully
//Postcondition: New record is added
//Decription: adds a orderRecord to STR; if STR is full, doubleSize is called to increase the size of STR. The user 
//            is prompted to enter the plant name, county name, plant cost and quantity.
/********************************************************************************************************************************/

void orderClass::add()
{
	if (count < size)
	{
		cout << "Enter customer plant Name: ";
		cin >> STR[count].pName;
		cout << "Enter County Name: ";
		cin >> STR[count].cName;
		cout << "Plant Cost: ";
		cin >> STR[count].plantCost;
		cout << "Quantity: ";
		cin >> STR[count].quantity;
		count++;

	}
	else
	{
		doubleSize();
		cout << "Enter customer plant Name: ";
		cin >> STR[count].pName;
		cout << "Enter County Name: ";
		cin >> STR[count].cName;
		cout << "Plant Cost: ";
		cin >> STR[count].plantCost;
		cout << "Quantity: ";
		cin >> STR[count].quantity;
		count++;
	}
	process();
}

/********************************************************************************************************************************/
//Name: operator-
//Precondition: 
//Postcondition: 
//Decription: removes all order records in STR with a plant name field that matches key, if it is there.
/*******************************************************************************************************************************/
orderClass& orderClass::operator-(const string key)
{
	for (int i = 0; i < count; i++)
	{
		int loc = search(key);

		if (loc != -1)
		{
			for (int j = loc; j < count - 1; j++)
			{
				STR[j] = STR[j + 1];
			}

			this->count--;
		}
	}

	return *this; //returning the current object
}

/******************************************************************************************************************************/
//Name: doubleSize
//Precondition: File record was successfully opened
//Postcondition: Data inside the text file is readed
//Decription: doubles the size (capacity) of STR
/******************************************************************************************************************************/

void orderClass::doubleSize()
{
	size *= 2;
	orderRecord* temp = new orderRecord[size];

	for (int i = 0; i < count; i++)
	{
		temp[i] = STR[i];
	}

	delete[] STR;
	STR = temp;
}


/******************************************************************************************************************************/
//Name: process
//Precondition: Variables of input function were initialized successfully from data file record (orderRecord)
//Postcondition: Variables are validated to perform calculations
//Decription: calculate the net cost, tax rate, order tax, discount and total cost for every order record in STR. for every call record in STR.
/*****************************************************************************************************************************/

void orderClass::process()
{
	// Calculations will be performed here
	for (int i = 0; i < count; i++)
	{
		// Calculating the netcost
		STR[i].netCost = STR[i].quantity * STR[i].plantCost;

		// Calculating the discount
		if (STR[i].quantity == 0)
			STR[i].discount = 0;
		else if (STR[i].quantity >= 1 && STR[i].quantity <= 5)
			STR[i].discount = .01 * STR[i].netCost;
		else if (STR[i].quantity >= 6 && STR[i].quantity <= 11)
			STR[i].discount = .03 * STR[i].netCost;
		else if (STR[i].quantity >= 12 && STR[i].quantity <= 20)
			STR[i].discount = .05 * STR[i].netCost;
		else if (STR[i].quantity >= 21 && STR[i].quantity <= 50)
			STR[i].discount = .08 * STR[i].netCost;
		else if (STR[i].quantity > 50)
			STR[i].discount = .12 * STR[i].netCost;

		// Obtaining tax rate
		if (STR[i].cName == "dade")
			STR[i].taxRate = .065;
		else if (STR[i].cName == "broward")
			STR[i].taxRate = .06;
		else if (STR[i].cName == "palm")
			STR[i].taxRate = .07;

		// Calculating purchase tax 
		if (STR[i].cName == "dade")
			STR[i].purchaseTax = STR[i].netCost * STR[i].taxRate;
		else if (STR[i].cName == "broward")
			STR[i].purchaseTax = STR[i].netCost * STR[i].taxRate;
		else if (STR[i].cName == "palm")
			STR[i].purchaseTax = STR[i].netCost * STR[i].taxRate;

		// Calculating the total cost of purchase
		STR[i].totalCost = STR[i].netCost + STR[i].purchaseTax - STR[i].discount;
	}
}


/****************************************************************************************************************************/
//Name: operator<<
//Precondition: 
//Postcondition: 
//Decription: prints every field of every call_record in STR formatted to a file and return the stream.
/***************************************************************************************************************************/
ostream& operator<<(ostream& out, orderClass& org)
{
	static int run;
	// Magic formula to obtain numerical values with a decimal place of 2
	out.setf(ios::showpoint);
	out.setf(ios::fixed);
	out.precision(2);

	for (int i = 0; i < org.count; i++)
	{
		// Transfer data into new text file in an organize way
		out << setw(15) << left << org.STR[i].pName;
		out << setw(10) << left << org.STR[i].cName;
		out << setw(7) << right << org.STR[i].plantCost;
		out << setw(6) << right << org.STR[i].quantity;
		out << setw(8) << right << org.STR[i].netCost;

		out.precision(3); // Decimal precision of 3
		out << setw(6) << right << org.STR[i].taxRate;

		out.precision(2); // Decimal precision of 2
		out << setw(7) << right << org.STR[i].purchaseTax;
		out << setw(7) << right << org.STR[i].discount;
		out << setw(9) << right << org.STR[i].totalCost << endl;
	}

	out << "****************************\n";
	out << "*********end of run " << run << "****" << endl;
	out << "*******************************\n";
	run++;

	return out;//returning object that invoked the function
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: Other functions were called successfully 
//Postcondition: de-allocates memory of array 
//Decription: de-allocates all memory allocated to STR.  This will be the last function to be called (automatically by the compiler)
//before the program is exited.
/***************************************************************************************************************************/

orderClass::~orderClass()
{
	count = 0;
	size = 0;
	delete[] STR; // De-allocate all memory allocated to STR.
	cout << "The destructor has been called\n";
}

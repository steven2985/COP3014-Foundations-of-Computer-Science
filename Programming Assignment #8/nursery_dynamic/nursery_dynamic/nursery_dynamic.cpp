/*
Steven Fernandez   Total Points:  10
Due Date:          06/19/20
Course:            C0P3014
Assignment:        Programming Assignment 8
Professor:         Dr. Lofton Bullard

Description:       Program that 
                   1. Read the contents of a data file one record at a time into a dynamic array;
                   2. Process the data stored, in a dynamic array;
                   3. Print the records in a dynamic array to a data file using an ofstream;
                   4. Use the operator new to allocate memory for a dynamic array;
                   5. Use the operator delete to de-allocate the memory allocated by the new operator; basically, making previously used memory available for use again);
                   6. Copy the contents of one dynamic array into another dynamic array; basically, copying the memory contents from one location to another;
                   7. Be able to use a dynamic array of records;
                   8. Be able to use an ifstream object;
                   9. Use a static local variable in a function;
                   10. Use the append (app) mode when opening an ofstream object;
*/

#include <iostream> // Library por input/output
#include <string>   // Library for characters
#include <fstream>  // Library to perform file i/o
#include <iomanip>  // Library for character handling functions
using namespace std;


class orderRecord
{
public:
	string pName;      // String variables for the names stored inside the file record
	string cName; 
	double plantCost;  // Double variables for the different numerical amounts locate inside file record
	int quantity;      // Integer variable for quantity 
	double netCost;
	double taxRate;
	double purchaseTax;
	double discount;
	double totalCost;
};


// Functions Prototypes: initialize, isEmpty, isFull, search, add, remove, doubleSize, process, print, destroySTR


void initialize(orderRecord*& STR, int& count, int& size);
bool isEmpty(int count);
bool isFull(int count, int size);
int search(orderRecord* STR, int  count, string key);
void add(orderRecord*& STR, int& count, int& size);
void remove(orderRecord* STR, int& count, string key);
void doubleSize(orderRecord*& STR, int  count, int& size);
void process(orderRecord* STR, int count);
void print(const orderRecord* STR, const int  count);
void destroySTR(orderRecord* STR, int& count, int& size);


//Name: initialize
//Precondition: File record was successfully opened
//Postcondition: Data inside the text file is readed
//Decription: Reads the data file of call information (cell number, itemNumber, quantity, price, and processingPlant) into the dynamic 
//array of call record, STR. If the count because equal to the size the function doubleSize is called and the memory allocated to STR is doubled.

void initialize(orderRecord*& STR, int& count, int& size)
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
			doubleSize(STR, count, size);
		}
		in >> STR[count].pName;
		in >> STR[count].cName;
		in >> STR[count].plantCost;
		in >> STR[count].quantity;
		count++;
	}

	in.close();

}

//Name: isEmpty 
//Precondition: File record was successfully opened
//Postcondition: Data inside the text file is readed
//Decription: returns true if STR is empty

bool isEmpty(int count)
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

//Name: isFull 
//Precondition: File record was successfully opened
//Postcondition: Data inside the text file is readed
//Decription: returns true if STR is full

bool isFull(int count, int size)
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

//Name: search
//Precondition: Values were added to the array successfully
//Postcondition: Search for values in the array
//Decription: locates key in STR if it is there; otherwise -1 is returned

int search(orderRecord* STR, int  count, string key)
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


//Name: add
//Precondition: Values were added to the array successfully
//Postcondition: New record is added
//Decription: adds a new record to STR; if STR is full, doubleSize is called to increase the capacity of STR.

void add(orderRecord*& STR, int& count, int& size)
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
		doubleSize(STR, count, size);
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
	process(STR, count); 
}

//Name: Remove
//Precondition: Values were added to the array successfully
//Postcondition: Remove a string value
//Decription: Remove all occurences of key from STR if it is there.

void remove(orderRecord* STR, int& count, string key)
{
	for (int i = 0; i < count; i++)
	{
		int loc = search(STR, count, key);

		if (loc != -1)
		{
			for (int j = loc; j < count - 1; j++)
			{
				STR[j] = STR[j + 1];
			}
			count--;
		}
	}
	
}

//Name: doubleSize
//Precondition: orderRecord was successfully
//Postcondition: 
//Decription: doubles the size (capacity) of STR

void doubleSize(orderRecord*& STR, int  count, int& size)
{
	size = 2 * size;
	orderRecord* temp = new orderRecord[size];
	for (int i = 0; i < count; i++)
	{
		temp[i] = STR[i];
	}

	delete[]STR;
	STR = new orderRecord[size];

	for (int i = 0; i < count; i++)
	{
		STR[i] = temp[i];
	}
	
}

//Name: process
//Precondition: Variables of input function were initialized successfully from data file record (orderRecord)
//Postcondition: Variables are validated to perform calculations
//Decription: calculate the net cost, tax rate, order tax and total cost for every order record in STR.

void process(orderRecord* STR, int count)
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

//Name: print
//Precondition: Variables of input and process functions were initialized successfully from data file record (orderRecord)
//Postcondition: Variables are readed to be storage in new text file 
//Decription: prints every field of every orderRecord in STR formatted to the screen.

void print(const orderRecord * STR, const int  count)
{
	
	ofstream out;
	out.open("nursery_results20.txt", fstream::app);
	static int run = 1;

	// Magic formula to obtain numerical values with a decimal place of 2
	out.setf(ios::showpoint);
	out.setf(ios::fixed);
	out.precision(2);

	for (int i = 0; i < count; i++)
	{
		// Transfer data into new text file in an organize way
		out << setw(15) << left << STR[i].pName;
		out << setw(10) << left << STR[i].cName;
		out << setw(7) << right << STR[i].plantCost;
		out << setw(6) << right << STR[i].quantity;
		out << setw(8) << right << STR[i].netCost;

		out.precision(3); // Decimal precision of 3
		out << setw(6) << right << STR[i].taxRate;

		out.precision(2); // Decimal precision of 2
		out << setw(7) << right << STR[i].purchaseTax;
		out << setw(7) << right << STR[i].discount;
		out << setw(9) << right << STR[i].totalCost << endl;
		
	}
		out << "****************************\n";
		out << "*********end of run " << run << "****" << endl;
		out << "*******************************\n";
	
	
	run++;
	out.close();
}

//Name: destroySTR
//Precondition: Other functions were called successfully 
//Postcondition: de-allocates memory of array 
//Decription: de-allocates all memory allocated to STR.  This should be the last function to be called before the program
//            is exited.

void destroySTR(orderRecord* STR, int& count, int& size)
{
	count = 0;
	size = 0;
	delete[] STR; // De-allocate all memory allocated to STR.
	
}


int main()
{
	int count = 0; //intializating count
	int size = 1;
	orderRecord* STR = new orderRecord[size];//declaring the dynamic array

	cout << "**********************************************************************\n";
	cout << "Test 1: Testing initialize, doubleSize, process, isFull and print " << endl;
	initialize(STR, count, size);
	process(STR, count);
	print(STR, count);
	cout << "End of Test 1" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 2:
	//void add(orderRecord * & STR, int & count, int & size);
	//The input to the test should be the following to generate the same results as the
	//same results I provided:  pName = rose, cName = dade, plantCost = 2, quantity = 2
	cout << "Test 2: Testing add, doubleSize, process, isFull, and print " << endl;
	add(STR, count, size);
	print(STR, count);
	cout << "End of Test 2" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 3:
    //void remove(orderRecord * STR, int & count, string key);
	cout << "Test 3: Testing remove, isEmpty, search and print " << endl;
	cout << "Removing rose\n";
	remove(STR, count, "rose");
	print(STR, count);
	cout << "Removing owl\n";
	remove(STR, count, "owl");
	print(STR, count);
	cout << "End of Test 3" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	////Test 4:
	//void add(orderRecord * & STR, int & count, int & size);
	//The input to the test should be the following to generate the same results as the
	////same results I provided:  pName = rose, cName = dade, plantCost = 2, quantity = 2
    cout << "Test 4: Testing add, doubleSize, process, isFull, and print " << endl;
	add(STR, count, size);
	print(STR, count);
	cout << "End of Test 4" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	////void destroySTR(orderRecord  * STR, int & count, int & size);*/
	cout << "Test 5: destroySTR and print " << endl;
	destroySTR(STR, count, size);
	cout << "size = " << size << endl;
	cout << "count = " << count << endl;
	cout << "End of Test 5" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	return 0;
}
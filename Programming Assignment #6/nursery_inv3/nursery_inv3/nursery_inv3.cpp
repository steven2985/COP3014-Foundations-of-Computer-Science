/*
Steven Fernandez   Total Points:  20
Due Date:          06/09/20
Course:            C0P3014
Assignment:        Programming Assignment 6
Professor:         Dr. Lofton Bullard

Description:       Program that process customers' purchase orders for a nursery. Read data store in a data file into a static array,
                   then process each purchase order record in the array, and finally print the array of purchase order record to a datafile.
*/

#include<iostream> // Library por input/output
#include<string>   // Library for characters
#include<fstream>  // Library to perform file i/o
#include<iomanip>  // Library that provides parametric manipulator
using namespace std;

const int CAPACITY = 100; //declaring capacity as a constant
class orderRecord
{
public:
	string pName;      // String variables for the names stored inside the file record
	string cName;
	double plantCost;  // Double variables for the different numerical amounts locate inside file record
	int quantity;      // Integer variable for quantity 
	double purchaseTax;
	double netCost;
	double taxRate;
	double discount;
	double totalCost;
};

// Functions Prototypes: input, process, output, and countInventory

void input(orderRecord STR[], int&);
void process(orderRecord STR[], const int);
void output(const orderRecord STR[], const int);
double countInventory(const orderRecord STR[], const int);

// Function Implementation 
/*
Name: Input
Precondition: File record was successfully opened
Postcondition: Data inside the text file is readed
Description: Check for data in the file record to validate their condition.	
*/

void input(orderRecord STR[], int& count)
{
	ifstream in; // Declaring an input file stream
	in.open("nursery_stock.txt"); // Opening the input file stream

	while (!in.eof() && count < CAPACITY)
	{
		in >> STR[count].pName;
		in >> STR[count].cName;
		in >> STR[count].plantCost;
		in >> STR[count].quantity;
		count++;
	}
	in.close(); // Closing the input file stream

}

// Function Implementation 

/*
Name: Process
Precondition: Variables of input function were initialized successfully from data file record (orderRecord)
Postcondition: Variables are validated to perform calculations
Description: Performed calculations of the purchase
*/

void process(orderRecord STR[], const int count)
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

// Function Implementation 

/*
Name: Output
Precondition: Variables of input and process functions were initialized successfully from data file record (orderRecord)
Postcondition: Variables are readed to be storage in new text file 
Description: Transfer data with proper calculations and order to new text file
*/

void output(const orderRecord STR[], const int count)
{
	ofstream out; // Declaring an output file stream
	out.open("nursery_run_results.txt"); // // Opening the output file stream

	// Magic formula to obtain numerical values with a decimal place of 2
	out.setf(ios::showpoint);
	out.setf(ios::fixed);
	out.precision(2);

	for (int i = 0  ; i < count; i++)
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
	out.close(); // Closing the output file stream
}

// Function Implementation 

/*
Name: countInventory
Precondition: Variables of input, process, and output functions were initialized successfully from data file record (orderRecord)
Postcondition: Variables are validated to perform calculation of total cost
Description: Calculating the average of total cost
*/

double countInventory(const orderRecord STR[], const int count)
{
	// Calculate average of totalCost
	double average = 0;

	for (int i = 0; i < count; i++)
	{
		average += (STR[i].totalCost / count);
	}

	return average;

}


int main()
{

	orderRecord STR[CAPACITY];
	int count = 0;

	ifstream in;  // Declaring an input file stream
	in.open("nursery_stock.txt"); // Opening the input file stream


	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		input(STR, count);
		process(STR, count);
		output(STR, count);
	}

	// Magic formula to obtain decimal precision of 2 
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);

	// Display a message to the user with the average total cost of order 
	cout << "Average Total Order Cost = " << countInventory(STR, count) << endl;

	in.close(); // Always close opened files

	return 0; // Finish program
}


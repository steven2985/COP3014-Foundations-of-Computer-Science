/*
Steven Fernandez   Total Points:  20
Due Date:          06/14/20
Course:            C0P3014
Assignment:        Programming Assignment 3
Professor:         Dr. Lofton Bullard

Description:       Program that process customers purchases order(s) on Ebay.
                   Process the data from the file record then perform calculations and finally display.
*/

#include <iostream> // Library por input/output
#include <string>   // Library for characters
#include <fstream>  // Library to perform file i/o
#include <iomanip>  // Library that provides parametric manipulators
using namespace std;


// Prototypes for functions: input, process, and output

void input(ifstream&, string&, string&, double&, double&, int&);
void process(const double, const double, const int, double&, double&, double&, double&);
void output(const string&, const string&, const int, const double, const int, const double, const double, const double, const double);

//Function Implementation

/*
Name: input
Precondition: text file was successfully opened
 Example: the variables (formal parameters) have not been initialized
Postcondition: Data inside the text file is readed
 Example: the variables (formal parameters) have been initiliazed
Description: Check for data in the text file to validate their condition.
 Example: Get input (values of cellNumber, itemNumber, quantity, price, and processingPlant)
 from text file "ebay_purchase_data.txt"
*/

void input(ifstream& in, string& cellNumber, string& itemNumber, double& quantity, double& price, int& processingPlant)
{
	in >> cellNumber;
	in >> itemNumber;
	in >> quantity;
	in >> price;
	in >> processingPlant;

}

//Function Implementation

/*Name: process
Precondition : Variables of input function was initialized successfully from data text file "ebay_purchase_data.txt"
Example: Data inside the text file record was validated
Potscondition: Variables are validated to perform calculations
Example: Calculate the tax rate of the purchase
Description: Performed calculations of the purchase
Example: Get input (values of cellNumber, itemNumber, quantity, price, and processingPlant)
 from text file "ebay_purchase_data.txt"
*/

void process(const double quantity, const double price, const int processingPlant, double& taxRate, double& orderTax, double& netCost, double& totalCost)
{
	// Calculations will be performed here 

	// Calculate tax rate of an order
	if (processingPlant <= 0)
		taxRate = 0;
	else if (processingPlant >= 1 && processingPlant <= 100)
		taxRate = .06;
	else if (processingPlant >= 101 && processingPlant <= 200)
		taxRate = .07;
	else if (processingPlant >= 201 && processingPlant <= 250)
		taxRate = .08;
	else if (processingPlant >= 251 && processingPlant <= 400)
		taxRate = .09;
	else if (processingPlant > 400)
		taxRate = .12;

	// Calculate tax of an order
	orderTax = quantity * price * taxRate;

	// Calculate netcost of an order 
	netCost = quantity * price;

	// Calculate total cost of an order 
	totalCost = netCost + orderTax;

}

//Function Implementation

/*Name: output
Precondition : Variables of input and process functions were initialized successfully from data text file "ebay_purchase_data.txt"
Example : The different records were readed and calculated with success
Postcondition : Variables are readed to be display
Example : Different values are displayed in order
Description : Display data with proper calculations and order
Example : Get output (values of cellNumber, itemNumber, quantity, price, processingPlant, taxRate, orderTax, netCost, and totalCost)
 from text file "ebay_purchase_data.txt"
*/

void output(const string& cellNumber, const string& itemNumber, const int quantity, const double price, const int processingPlant, const double taxRate, const double orderTax, const double netCost, const double totalCost)
{

	// Magic formula to obtain numerical values with a decimal place of 2
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	// Display data in an organize way 
	cout << setw(15) << left << cellNumber;
	cout << setw(10) << right << itemNumber;
	cout << setw(10) << right << quantity;
	cout << setw(10) << right << price;
	cout << setw(10) << right << processingPlant;
	cout << setw(10) << right << taxRate;
	cout << setw(10) << right << orderTax;
	cout << setw(10) << right << netCost;
	cout << setw(10) << right << totalCost << endl;
}


int main()
{
	string cellNumber;   // String variables for the names stored inside the file record
	string itemNumber;
	double quantity;     // Double variables for the different numerical amounts locate inside file record
	double price;
	int processingPlant; // Int variable 
	double taxRate;      // Double variables for the different numerical amounts when performing calculations
	double orderTax;
	double netCost;
	double totalCost;

	ifstream in;    // Declaring an input file stream
	in.open("ebay_purchase_data.txt"); // Opening the input file stream

	if (in.fail()) // If programs fails to open it will displays this message to the user 
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{

		 input(in, cellNumber, itemNumber, quantity, price, processingPlant);
		 process(quantity, price, processingPlant, taxRate, orderTax, netCost, totalCost);
		 output(cellNumber, itemNumber, quantity, price, processingPlant, taxRate, orderTax, netCost, totalCost);

		}
	}

	in.close(); // Always close opened files

	return 0; // Finish program
}
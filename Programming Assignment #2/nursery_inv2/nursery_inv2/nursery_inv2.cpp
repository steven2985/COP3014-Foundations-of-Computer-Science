/*
Steven Fernandez   Total Points:  20
Due Date:          06/07/20
Course:            C0P3014
Assignment:        Programming Assignment 2
Professor:         Dr. Lofton Bullard

Description:       Program that process customers' purchase orders for a nursery from a data file record.
                   Process the data from the file record then perform calculations and finally display.
*/

#include<iostream> // Library por input/output
#include<string>   // Library for characters
#include<fstream>  // Library to perform file i/o
#include<iomanip>  // Library that provides parametric manipulators
using namespace std;


//Declaration of a order record

class orderRecord
{
public:
	string pName;    // String variables for the names stored inside the file record
	string cName;
	double plantCost; // Double variables for the different numerical amounts locate inside file record
	double quantity;
	double purchaseTax;
	double netCost;
	double discount;
	double totalCost;
};

// Prototypes for your functions: input, output, and process
void input(ifstream&, orderRecord&);
void output(const orderRecord&);
void process(orderRecord&);

// Function Implementations
/*
Name: input
Precondition: File record was successfully opened
 Example: the variables (formal parameters) have not been initialized
Postcondition: Data inside the text file is readed
 Example: the variables (formal parameters) have been initiliazed
Description: Check for data in the file record to validate their condition.
 Example: Get input (values of plant name, county name, plant cost, and quantity)
 from data file order record (p_record)
*/

void input(ifstream& in, orderRecord& planRecord)
{
	in >> planRecord.pName;
	in >> planRecord.cName; 
	in >> planRecord.plantCost;
	in >> planRecord.quantity;
}

/*
Name: output
Precondition: Variables of input and process functions were initialized successfully from data file record (p_record)
 Example: The different records were readed and calculated with success
Postcondition: Variables are readed to be display
 Example: Different values are displayed in order
Description: Display data with proper calculations and order
 Example: Get output (values of plant name, county name, plant cost, and quantity)
 from data file order record (p_record)
*/

void output(const orderRecord& plantRecord)
{
	// Magic formula to obtain numerical values with a decimal place of 2
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	// Display data in an organize way 
	cout << setw(15) << left << plantRecord.pName
		<< setw(10) << right << plantRecord.cName
		<< setw(10) << right << plantRecord.plantCost
		<< setw(10) << right << plantRecord.quantity
		<< setw(10) << right << plantRecord.netCost
		<< setw(10) << right << plantRecord.purchaseTax
		<< setw(10) << right << plantRecord.discount
		<< setw(10) << right << plantRecord.totalCost << endl;

}

/*Name: process
Precondition : Variables of input function were initialized successfully from data file record (p_record)
Example: Data inside the file record was validated 
Potscondition: Variables are validated to perform calculations
Example: Calculate the dicount of the purchase
Description: Performed calculations of the purchase
Example: Get input (values of plant name, county name, plant cost, and quantity)
 from data file order record (p_record) to perform calculations
*/

void process(orderRecord& plantRecord)
{
	// Calculations will be performed here

	// Calculating the netcost
	plantRecord.netCost = plantRecord.quantity * plantRecord.plantCost;

	// Calculating the discount
	if (plantRecord.quantity <= 0)
		plantRecord.discount = 0;
	else if (plantRecord.quantity >= 1 && plantRecord.quantity <= 5)
		plantRecord.discount = .01 * plantRecord.netCost;
	else if (plantRecord.quantity >= 6 && plantRecord.quantity <= 11)
		plantRecord.discount = .03 * plantRecord.netCost;
	else if (plantRecord.quantity >= 12 && plantRecord.quantity <= 20)
		plantRecord.discount = .05 * plantRecord.netCost;
	else if (plantRecord.quantity >= 21 && plantRecord.quantity <= 50)
		plantRecord.discount = .08 * plantRecord.netCost;
	else if (plantRecord.quantity > 50)
		plantRecord.discount = .12 * plantRecord.netCost;

	// Calculating purchase tax 
	if (plantRecord.cName == "dade")
		plantRecord.purchaseTax = plantRecord.netCost * .065;
	else if (plantRecord.cName == "broward")
		plantRecord.purchaseTax = plantRecord.netCost * .06;
	else if (plantRecord.cName == "palm")
		plantRecord.purchaseTax = plantRecord.netCost * .07;

	// Calculating the total cost of purchase
	plantRecord.totalCost = plantRecord.netCost + plantRecord.purchaseTax - plantRecord.discount;

}

int main()
{
	orderRecord purchaseRecord;
	string pName, cName;
	double netCost;
	int quantity;

	ifstream in; // Declaring an input file stream
	in.open("nursery_stock.txt"); // Opening the input file stream
	
	if (in.fail()) // If programs fails to open it will displays this message to the user 
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{
			input(in, purchaseRecord);
			process(purchaseRecord);
			output(purchaseRecord);
		}
	}

	in.close(); // Always close opened files

	return 0; // Close program
}
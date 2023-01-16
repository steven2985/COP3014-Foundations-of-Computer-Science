/*
Steven Fernandez   Total Points:  10
Due Date:          06/28/20
Course:            C0P3014
Assignment:        Programming Assignment 5
Professor:         Dr. Lofton Bullard

Description:       Program that process customers' purchase orders for a nursery. Calculate tax, discount and total cost of the purchase
				   then print the results on a different file called sells_results.
*/

#include<iostream> // Library por input/output
#include<string>   // Library for characters
#include<fstream>  // Library to perform file i/o
#include<iomanip>  // Library that provides parametric manipulator
using namespace std;


//Declaration of a order record

class orderRecord
{
public:
	string pName;     // String variables for the names stored inside the file record
	string cName; 
	int quantity;     // Integer variable for quantity
	double plantCost; // Double variables for the different numerical amounts locate inside file record
	double purchaseTax;
	double netCost;
	double discount;
	double totalCost;
	double taxRate;
};

// Prototypes for your functions: input, process, and output
void input(ifstream&, orderRecord&);
void process(orderRecord&);
void output(ofstream&, const orderRecord);

// Function Implementations
/*
Name: input
Precondition: File record was successfully opened
 Example: the variables (formal parameters) have not been initialized
Postcondition: Data inside the text file is readed
 Example: the variables (formal parameters) have been initiliazed
Description: Check for data in the file record to validate their condition.
 Example: Get input (values of plant name, county name, plant cost, and quantity)
 from data file order record (plantRecord)
*/

void input(ifstream& in, orderRecord& planRecord)
{
	in >> planRecord.pName;
	in >> planRecord.cName;
	in >> planRecord.plantCost;
	in >> planRecord.quantity;
}

/*Name: process
Precondition : Variables of input function were initialized successfully from data file record (plantRecord)
Example: Data inside the file record was validated
Potscondition: Variables are validated to perform calculations
Example: Calculate the dicount of the purchase
Description: Performed calculations of the purchase
Example: Get input (values of plant name, county name, plant cost, and quantity)
 from data file order record (plantRecord) to perform calculations
*/

void process(orderRecord& plantRecord)
{
	// Calculations will be performed here

	// Calculating the netcost
	plantRecord.netCost = plantRecord.quantity * plantRecord.plantCost;

	// Calculating the discount
	if (plantRecord.quantity == 0)
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

	// Obtaining tax rate
	if (plantRecord.cName == "dade")
		plantRecord.taxRate = .065;
	else if (plantRecord.cName == "broward")
		plantRecord.taxRate = .06;
	else if (plantRecord.cName == "palm")
		plantRecord.taxRate = .07;

	// Calculating purchase tax 
	if (plantRecord.cName == "dade")
		plantRecord.purchaseTax = plantRecord.netCost * plantRecord.taxRate;
	else if (plantRecord.cName == "broward")
		plantRecord.purchaseTax = plantRecord.netCost * plantRecord.taxRate;
	else if (plantRecord.cName == "palm")
		plantRecord.purchaseTax = plantRecord.netCost * plantRecord.taxRate;

	// Calculating the total cost of purchase
	plantRecord.totalCost = plantRecord.netCost + plantRecord.purchaseTax - plantRecord.discount;

}


/*
Name: output
Precondition: Variables of input and process functions were initialized successfully from data file record (plantRecord)
 Example: The different records were readed and calculated with success
Postcondition: Variables are readed to be display
 Example: Different values are displayed in order
Description: print data with proper calculations and order into new text file
 Example: Get output (values of plant name, county name, plant cost, and quantity)
 from data file order record (plantRecord) to print into file order record (customerOrder)
*/

void output(ofstream& out, const orderRecord customerOrder)
{
	// Magic formula to obtain numerical values with a decimal place of 2
	out.setf(ios::showpoint);
	out.setf(ios::fixed);
	out.precision(2);

	// Print data in an organize way
	out << setw(15) << left << customerOrder.pName
		<< setw(10) << left << customerOrder.cName
		<< setw(7)  << right << customerOrder.plantCost
	    << setw(6)  << right << customerOrder.quantity
	    << setw(8)  << right << customerOrder.netCost;
	out.precision(3); // Setting 3 decimal points for tax rate
	out << setw(6)  << right << customerOrder.taxRate;
	out.precision(2); // setting 2 decimal points for remaining values 
    out<< setw(7)   << right << customerOrder.purchaseTax
		<< setw(7)  << right << customerOrder.discount
		<< setw(9)  << right << customerOrder.totalCost << endl;

}


int main()
{
	orderRecord purchaseRecord;
	string pName, cName;
	double netCost;
	int quantity;

	ifstream in; // Declaring an input file stream
	in.open("nursery_stock.txt"); // Opening the input file stream

	//ofstream out; // Declaring an output file stream
	//out.open("sells_results.txt"); // Opening the output file stream

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
			output(out, purchaseRecord);
		}
	}

	in.close(); // Always close opened files
	//out.close();

	return 0; // Close program
}
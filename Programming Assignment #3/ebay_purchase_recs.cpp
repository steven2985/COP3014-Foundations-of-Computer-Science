//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name:                                 Z#:
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:                      Due Time:
Total Points: 20
Assignment #: ebay_purchase_recs.cpp

Description:

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
#include <iomanip>
using namespace std;


//Prototypes for your functions: input, output, and process will go here

void input(ifstream&, string&, string&, double&, double&, int&);
void process(const double, const double, const int, double&, double&, double&, double&);
void output(const string&, const string&, const int, const double, const int, const double, const double, const double, const double);

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:  
// Example:Get input (values of cell_number, item_number, quantity, price, processing_plant ) 
//from data file.

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream& in, string& cell_number, string& item_number, double& quantity, double& price, int& processing_plant)// example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{

	// add statement(s) to read variables from datafile .
	//variables: cell_number,item_number, quantity, price and processing_plant)
	
}

///*************************************************************************************
//Name:  process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

void process(const double quantity, const double price, const int processing_plant, double& tax_rate, double& order_tax, double& net_cost, double& total_cost)
{

	//put your code here to process/calculate the tax_rate, order_tax, net_cost, and total_cost
	
}

///*************************************************************************************
//Name:  output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************


void output(const string& cell_number, const string& item_number, const int quantity, const double price, const int processing_plant, const double tax_rate, const double order_tax, const double net_cost, const double total_cost)
{

	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/
	//NOTE:
	//setw(12) put a variable in a field with a width of 12
	//right will right justify a variable
	//left will left justify a variable
	// example:  cout << setw(12) << left << cell_number
	//<< setw(8) << right << item_number;

    //put your code here to print the variables

}


//Here is your driver to test the program
int main()
{
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;

	ifstream in;    //declaring an input file stream
	in.open("ebay_purchase_data.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{   
		//while (!in.eof())
		//{

		//	input(in, cell_number, item_number, quantity, price, processing_plant);
		//	process(quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
		//	output(cell_number, item_number, quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
		//}
	}

	in.close();
	
	return 0;
}
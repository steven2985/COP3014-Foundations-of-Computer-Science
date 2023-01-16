

//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name:                                 Z#:
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:                      Total Points: 20
Assignment#:Assignment#2  (nursery_inv.cpp)

Description:

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
#include <iomanip>
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/
class order_record
{
public:
	string pname;
	string cname;
	double plant_cost;
	double quantity;
	double purchase_tax;
	double net_cost;
	double discount;
	double total_cost;
};


//Prototypes for your functions: input, output, and process will go here

void input(ifstream&, order_record&);
void output(const order_record&);
void process(order_record&);

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:  
// Example:Get input (values of plant name, county name, plant cost, quantity ) 
//from data file order record (p_record).

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream& in, order_record& plant_record) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	in >> plant_record.pname;
	//add more code to read the rest of the fields (county name, plant cost, quantity) into the 
	//order record, plant_record.
}

///*************************************************************************************
//Name:  output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

void output(const order_record& plant_record)
{
	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/


	//cout << plant_record.pname << "\t";
	//add more code to print all the fields in the order record


}

///*************************************************************************************
//Name:  process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

//Note: there is one 1 input/output parameter
void process(order_record & plant_record)
{

	//put your code here to process/calculate the net cost, purchase tax, discount, and total cost
	//for the plant_record

}

//Here is your driver to test the program
int main()
{

	order_record purchase_record;
	string pname, cname;
	double cost;
	int quantity;

	ifstream in;    //declaring an input file stream
	in.open("nursery_stock.txt"); //opening the input file stream 

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{   //the following while loop processes one order record at a time
		while (!in.eof())
		{
			input(in, purchase_record);
			//process(purchase_record);
			//output(purchase_record);
		}
	}

	in.close(); //always close opened files.

	return 0;
}



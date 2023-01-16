 /*****************************************************************
    Name:                        Z-number
	Course:
	Professor: Dr.Lofton Bullard
	Due Date : 
	Total Points :    
	Assignment# : 

	Description :

	*************************************************************/

//Include the following
#include <iostream>
#include <string>
#include <fstream>	//you must include this library if you wish to do file i/o
#include <iomanip>
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/

const int CAPACITY = 100;//declaring capacity as a constant
class order_record
{
public:
	string pname;
	string cname;
	double plant_cost;
	double quantity;
	double purchase_tax;
	double net_cost;
	double tax_rate;
	double discount;
	double total_cost;
};

//Prototypes for your functions: input, output, process, and count_inventory will go here

//void input(order_record STR[],int &count); //sample prototype for input
//you add other prototypes

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:	Describe what the function does (purpose).

//*************************************************************************************



///*************************************************************************************
//Name:  process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:	Describe what the function does (purpose).
//*************************************************************************************

///*************************************************************************************
//Name:  output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:	Describe what the function does (purpose).
//*************************************************************************************


///*************************************************************************************
//Name:  count_inventory
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:	Describe what the function does (purpose).
//*************************************************************************************


//Here is your driver to test the program
//Here is your driver to test the program
int main()
{

	order_record STR[CAPACITY];
	int count = 0;

	if (in.fail())

	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		/*input(STR, count);
		process(STR, count);
		output(STR, count);*/
	}

	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	//cout << "Average Total Order Cost = " << count_inventory(STR, count) << endl;

	return 0;
}

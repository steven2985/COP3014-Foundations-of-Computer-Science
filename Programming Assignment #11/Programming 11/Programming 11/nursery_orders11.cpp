/*
Steven Fernandez   Total Points:  20
Due Date:          06/31/20
Course:            C0P3014
Assignment:        Programming Assignment 11
Professor:         Dr. Lofton Bullard

Description:       Program that
				   1. Separate class code into a declaration (header) and implementation components;
                   2. Implement a copy constructor;
                   3. Use the preprocessor directives #ifdef, #define, and #endif;
*/

#include <iostream>
#include <fstream>
#include <string>
#include "order_class.h"
using namespace std;

int main()
{
	orderClass myOrders;//declaring order_class object myOrders; the default constructor is called automically.
	cout << "**********************************************************************\n";
	//Test 1:
	cout << "Test 1: Testing default construcor, doubleSize, process, isFull and operator<< " << endl;
	myOrders.process();
	cout << myOrders;
	cout << "End of Test 1" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 2:
	//void add();
	cout << "Test 2: Testing add, doubleSize, process, isFull, and operator<< " << endl;
	myOrders.add();//test case: pname = rose, cname = dade, plant cost = 1, quantity = 1 
	cout << myOrders;
	cout << "End of Test 2" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 3:
	//operator-(string key);
	cout << "Test 3: Testing operator-, isEmpty, search and opertor<< " << endl;
	cout << "Removing rose\n";
	myOrders - "rose";
	cout << myOrders;
	cout << "Removing bergenia and yarrow\n";
	myOrders - "bergenia" - "yarrow";
	cout << myOrders;
	cout << "Removing rose ---AGAIN--- SHOULD GET MESSAGE\n";
	myOrders - "rose";
	cout << myOrders;
	cout << "End of Test 3" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 4:
	//copy constructor
	cout << "Test4: Testing copy constructor\n\n";
	orderClass yourOrders = myOrders;
	cout << yourOrders << endl;
	cout << "End of Test 4" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 5:
	//destructor will be invoked when object myOrders goes out of scope
	cout << "Test 4: Destructor called" << endl;
	cout << "End of Test 5" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	return 0;
}
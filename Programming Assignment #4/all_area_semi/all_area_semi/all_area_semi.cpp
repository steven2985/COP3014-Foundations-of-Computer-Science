/*
Steven Fernandez   Total Points:  10
Due Date:          06/23/20
Course:            C0P3014
Assignment:        Programming Assignment 4
Professor:         Dr. Lofton Bullard

Description:       Program that computes the area of an arbitraty triangle, if sides of triangle are not valid display invalid message
                   if sides are valid calculate area and semiperimeter and then display values and give the option for another calculation.
*/

#include<iostream> // Library for input/output 
#include<iomanip>  // Library that provides parametric manipulators
#include<string>   // Library for characters
using namespace std;

// Prototypes for functions: Compute

void Compute(double, double, double, double&, double&);

// Function Implementation

/*Name: Compute
Precondition: Triangle values were received
Example: Numbers for all three sides of the triangle were given
Postcondition: Triangle values are readed and calculations are perfomed 
Example: Area and semiperimeter of the triangle are calculate
Description: Obtain area and semiperimeter of triangle 
Example: Calculating area and semiperimeter of triangle with the sides given
*/


void Compute(double side1, double side2, double side3, double & area, double & semiPerimeter)
{
	// Perform calculations here 

	// Formula to calculate semiperimeter
	semiPerimeter = ((side1 + side2 + side3) / 2); 

	// Formula to calculate area
	area = sqrt(semiPerimeter * ((semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3))); 
}


int main()
{
	// Magic Formula to obtain a precision of 2 decimals on calculations
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	string userResponse = "y";
	double side1, side2, side3, area=0, semiPerimeter=0; // Set sides as doubles to avoid using static_cast when performing calculations

	while (userResponse == "y" || userResponse == "Y") // Code to obtain user's information
	{
		cout << "Enter side a of the triangle: ";
		cin >> side1;
		cout << "Enter side b of the triangle: ";
		cin >> side2;
		cout << "Enter side c of the triangle: ";
		cin >> side3;

		// Call function to obtain calculations
		Compute(side1, side2, side3, area, semiPerimeter);

		if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
			cout << "\nInvalid sides (a + b) !> c\n";
		else
		{
			cout << "\nSemi: " << semiPerimeter << endl;
			cout << "Area: " <<  area << endl;

		}

	    // Give customer the option to perform another calculation
		cout << "\nWould you like to perform another calculation enter Y or y for yes: ";
		cin >> userResponse;
		cout << endl;
	}

	return 0; // Close program
}
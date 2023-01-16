/*
Steven Fernandez   Total Points:  10
Due Date:          05/31/20
Course:            C0P3014
Assignment:        Programming Assignment 1
Professor:         Dr. Lofton Bullard
  
Description:       Program that calculates the tax, cost, discocunt, and total cost of a purchase
                   then display this data to the customer and finally ask the customer for another 
                   calculation if no then close the program.
*/

// Libraries
#include<iostream>  // Standard library for i/o
#include<iomanip>  // Parametric Manipulators
#include<string>  // String Types

using namespace std;

int main()
{
    // Magic Formula to obtain a precision of 2 decimals on prices
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    string userResponse = "y"; // User positive response for second calcualtion

    string pName;            // String that holds plan name
    string cName;            // String that hold county name
    double plantCost;        // double that holds plant cost
    int quantity;            // int that holds the number of plants purchased
    double purchaseTax = 0;  // double that holds the purchase tax
    double netCost = 0;      // double that holds the net cost of the purchase
    double discount = 0;     // double that holds the discount of the purchase
    double totalCost = 0;    // double that holds the total cost of the purchase
    

    while (userResponse == "y" || userResponse == "Y") // Code to obtain user's information
    {
        // Prompt user for purchase information
        cout << "Enter the plant name: ";
        cin >> pName;
        cout << "Enter the County name: ";
        cin >> cName;
        cout << "Enter the plant cost: ";
        cin >> plantCost;
        cout << "Enter the quantity: ";
        cin >> quantity;
        cout << endl;

        // Performing Calculations

        // Calculating Discount
        netCost = quantity * plantCost;
        if (quantity <= 0)
            discount = 0;
        else if (quantity >= 1 && quantity <= 5)
            discount = .01 * netCost;
        else if (quantity >= 6 && quantity <=11)
            discount = .03 * netCost;
        else if (quantity >= 12 && quantity <= 20)
            discount = .05 * netCost;
        else if (quantity >= 21 && quantity <= 50)
            discount = .08 * netCost;
        else if (quantity > 50)
            discount = .12 * netCost;

        // Calcualting Taxes
        if (cName == "dade")
            purchaseTax = netCost * .065;
        else if (cName == "broward")
            purchaseTax = netCost * .06;
        else if (cName == "palm")
            purchaseTax = netCost * .07;
        
        // Calculating the total cost
        totalCost = netCost + purchaseTax - discount;

        // Print results
        cout << endl << endl;
        cout << "Plant Name:\t\t" << pName << endl;
        cout << "County Name:\t\t" << cName << endl; 
        cout << "Plant Cost:\t\t" << plantCost << endl;
        cout << "Quantity of Plants:\t" << quantity << endl;
        cout << "Net Cost of Purchase:\t" << netCost << endl;
        cout << "Purchase Tax:\t\t" << purchaseTax << endl;
        cout << "Discount on Purchase:\t" << "-" << discount << endl;
        cout << "Total Cost of Purchase:\t" << totalCost << endl << endl;

        // Give the customer the option to perform another calculation
        cout << "Would you like to do another calculation (Y or N): " << endl;
        cin >> userResponse;

    }
    
    return 0;
}
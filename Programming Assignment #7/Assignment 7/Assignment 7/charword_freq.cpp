/*
Steven Fernandez   Total Points:  20
Due Date:          06/14/20
Course:            C0P3014
Assignment:        Programming Assignment 7
Professor:         Dr. Lofton Bullard

Description:       Program that defines a word to be any string of letters that is delimited at each end by either whitespace, 
                   a period, a comma, or the beginning or end of a line.
*/

#include<iostream> // Library por input/output
#include<string>   // Library for characters
#include<fstream>  // Library to perform file i/o
#include<cctype>   // Library for character handling functions

using namespace std;

// Functions Prototypes

void words(string);
void frequency(string);

// Function Implementation

/*Name: words
Precondition : File record was successfully opened
Postcondition : Data inside the text file is readed
Description : Check file to check how many words are in it 
*/

void words(string letters)
{
	int count = 0;

	for (int i = 0; i < letters.length(); i++)
	{
		if (isalpha(letters[i]) && (letters[i+1] == '.' || letters[i+1] == ',' || letters[i+1] == ' ')) // Condition for special characters
		{
			count++;
		}
	}
	cout << count << " words" << endl; // Tell how many words are in the file 
}

// Function Implementation 

/*Name: frequency
Precondition : File record was successfully opened
Postcondition : Data inside the text file is readed
Description : Counts the letters on the text file to give quantity
*/

void frequency(string letters)
{
	int arr[26] = {}; // Array of 26 like the alphabet 

	for (int i = 0; i < letters.length(); i++)
	{
		if (isalpha(letters[i]))
		{
			char lowerChar = tolower(letters[i]); // Get all letters to lowercase to simplify work
			arr[lowerChar-'a']++; // Finding the lowercase letter with ASCII decimal value
		}
	}

	for (int i = 0; i < 26; i++)
	{

		if (arr[i] != 0)
		{
			char point = i + 'a' ; // Find letter with ASCII decimal value
			cout << arr[i] << " " << point << endl; // Display number of letters
		}
	}
	
}


int main()
{
    ifstream in; // Declaring an input file stream
    in.open("word_data.txt"); // Opening the input file stream

	string s;

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		getline(in, s);   // Calling Functions 
		words(s);
		frequency(s);
	}

	in.close(); // Always close opened files
    return 0; // Finish Program

}
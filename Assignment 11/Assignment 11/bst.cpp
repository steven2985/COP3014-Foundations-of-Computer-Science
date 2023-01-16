#include "bst.h"

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: bst
//Precondition: bst not yet initialized
//Postcondition: bst initialized with values from data file
//Description: stores the data file into initial bst
///////////////////////////////////////////////////////////////////////////////////////////////

bst::bst()
{
	root = 0;

	string currentItem, stringForPopulation, currentLine;
	double currentPopulation;

	ifstream countyFile;
	countyFile.open("county_data.txt");

	if (countyFile.fail())
	{
		cout << "error opening the input file\n";
	}
	else
	{
		while (!countyFile.eof())
		{
			getline(countyFile, currentLine);

			for (int i = 0; i < currentLine.length(); i++) // Looks through every character in the line from left to right
			{
				if (isalpha(currentLine[i]) || currentLine[i] == '.')
				{
					currentItem += currentLine[i];
				}
				else if (currentLine[i] == ' ' && isalpha(currentLine[i + 1]))
				{
					currentItem += currentLine[i];
				}
				else if (isdigit(currentLine[i]))
				{
					stringForPopulation += currentLine[i];
				}
			}
			currentPopulation = stod(stringForPopulation);

			cout << fixed << setprecision(0) << setw(10);
			cout << left << setw(20) << currentItem << "\t"; //output parsed data
			cout << right << setw(10) << currentPopulation << endl;

			insert(currentItem, currentPopulation);

			stringForPopulation = "";
			currentItem = "";
		}

		cout << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~bst
//Precondition: bst initialized with values
//Postcondition: bst memory deallocated
//Description: de-allocates dynamic memory allocation
///////////////////////////////////////////////////////////////////////////////////////////////

bst::~bst()
{
	empty_tree();
	cout << "The Destructor called" << endl;	//output destructor call
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: empty
//Precondition: bst declared and/or initialized
//Postcondition: returns whether or not root is null
//Description: determines if bst is null
///////////////////////////////////////////////////////////////////////////////////////////////

bool bst::empty()
{
	return (root == 0); //returns if root is null(bst is empty)
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert 
//Precondition: bst declared
//Postcondition: new node inserted into bst
//Description: inserts a new node into bst
///////////////////////////////////////////////////////////////////////////////////////////////

void bst::insert(const string& item, const double& population)
{		//auxillary function

	insert(root, item, population);	//calls class function
}

void bst::insert(treenode*& loc_ptr, const string& item, const double& population)
{
	if (loc_ptr == 0)
	{
		loc_ptr = new treenode;
		loc_ptr->lchild = loc_ptr->rchild = 0;
		loc_ptr->county_name = item;
		loc_ptr->population_size = population;
	}
	else if (loc_ptr->county_name > item)
	{
		insert(loc_ptr->lchild, item, population);
	}
	else if (loc_ptr->county_name < item)
	{
		insert(loc_ptr->rchild, item, population);
	}
	else
	{
		cout << "the item is already in the tree\n";
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: search_tree
//Precondition: bst initialized with values
//Postcondition: bst searched for input argument
//Description: returns pointer to node containing input argument
///////////////////////////////////////////////////////////////////////////////////////////////

treenode* bst::search_tree(string item)
{ 	//auxillary function
	return search_tree(root, item);
}

treenode* bst::search_tree(treenode* loc_ptr, string item)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->county_name == item)
		{
			return loc_ptr;
		}
		else if (loc_ptr->county_name > item)
		{
			return search_tree(loc_ptr->lchild, item);
		}
		else
		{
			return search_tree(loc_ptr->rchild, item);
		}
	}
	else
	{
		return loc_ptr;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: del_name
//Precondition: bst initialized with values
//Postcondition: input argument removed from bst
//Description: removed node containing input argument(if it exists)
///////////////////////////////////////////////////////////////////////////////////////////////

void bst::del_name(string item)
{	//auxillary function

	del_name(root, item);
}

void bst::del_name(treenode*& loc_ptr, string item)
{
	if (loc_ptr == 0)
	{
		cout << "item not in the tree\n";
	}
	else if (loc_ptr->county_name > item)
	{
		del_name(loc_ptr->lchild, item);
	}
	else if (loc_ptr->county_name < item)
	{
		del_name(loc_ptr->rchild, item);
	}
	else
	{
		treenode* ptr;
		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->county_name = ptr->county_name;
			del_name(loc_ptr->rchild, ptr->county_name);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: inorder_succ
//Precondition: bst initialized with values
//Postcondition: gets node that is successor to node input
//Description: returns a pointer to the inorder successor, based on county name. 
///////////////////////////////////////////////////////////////////////////////////////////////

treenode* bst::inorder_succ(treenode* loc_ptr)
{
	treenode* ptr = loc_ptr->rchild;
	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}
	return ptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print_tree
//Precondition: bst initialized with values
//Postcondition: prints each county record
//Description: prints each county record to the screen sorted by county name
///////////////////////////////////////////////////////////////////////////////////////////////

void bst::print_tree()
{
	print_tree(root);
}

void bst::print_tree(treenode*& loc_ptr)
{
	if (loc_ptr != 0)
	{
		print_tree(loc_ptr->lchild);
		cout << loc_ptr->county_name << endl;
		print_tree(loc_ptr->rchild);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print_tree
//Precondition: bst initialized with values
//Postcondition: prints each county record
//Description: prints each county record to the screen sorted by county name
///////////////////////////////////////////////////////////////////////////////////////////////

void bst::sorted_info()
{	//auxillary function

	ofstream out;	//declare stream

	out.open("county_info.txt"); //bind file to stream
	if (out.fail())
	{	//if fails
		cout << "Opening the output file has failed. Try again." << endl;
		return;	//exit
	}

	out << fixed; //fixed notation
	out.precision(0); //no precision

	sorted_info(out, root);
	out.close();	//close stream
}

void bst::sorted_info(ofstream& out, treenode*& loc_ptr)
{
	if (loc_ptr != 0)
	{
		sorted_info(out, loc_ptr->lchild);
		out << left << setw(20) << loc_ptr->county_name << "\t";
		out << right << setw(9) << loc_ptr->population_size << endl;
		sorted_info(out, loc_ptr->rchild);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: empty_tree
//Precondition: bst initialized with values
//Postcondition: bst memory deallocated
//Description: de-allocates dynamic memory allocation
///////////////////////////////////////////////////////////////////////////////////////////////

void bst::empty_tree()
{
	while (root != 0)
	{
		del_name(root->county_name);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: county_ranges
//Precondition: bst initialized with values
//Postcondition: outputs counties within range
//Description: prints all the county names to the screen that lie between min_name and max_name, inclusive. 
///////////////////////////////////////////////////////////////////////////////////////////////

void bst::county_ranges(const string& min_name, const string& max_name)
{
	county_ranges(root, min_name, max_name);
}
void bst::county_ranges(treenode*& loc_ptr, const string& min_name, const string& max_name)
{
	if (loc_ptr != 0)
	{
		county_ranges(loc_ptr->lchild, min_name, max_name);
		if (loc_ptr->county_name >= min_name && loc_ptr->county_name <= max_name)
		{
			cout << loc_ptr->county_name << endl;
		}
		county_ranges(loc_ptr->rchild, min_name, max_name);
	}
}
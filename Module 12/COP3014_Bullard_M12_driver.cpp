#include <iostream>
#include <string>
#include "array_class.h"
#include "array_class.h"
using namespace std;

void Fun2(array_class call_by_value)
{

}

array_class & Fun3()
{
	array_class TheirClass;

	return TheirClass;
}

int main()
{
	array_class myClass;

	cout<<myClass<<myClass<<myClass<<myClass<<endl;  
	//operator<<(cout,myClass);
	/*
	cout<<myClass;
	cout<<myClass;
	cout<<myClass;
	cout<<myClass;
	cout<<endl;
	*/

	//cout<<myClass;
	myClass + 20 + -100 +-999 + 444 + 1111 + -22 + 47;

	cout<<endl<<endl<<myClass;

	array_class YourClass = myClass;

	cout<<endl<<endl<<YourClass<<endl<<"   "<<&YourClass<< "   "<<&myClass<<endl;
	//Fun2(myClass);
	//Fun3();

	/*if (myClass*30 !=-1)
		cout<<"20 is in the array\n";*/

	array_class C;

	C + -1000 + -2000 + -3000+ 9999;

	cout<<endl<<endl<<C<<endl;

	myClass = C;

	cout<<endl<<endl<<myClass<<endl;

	return 0;
}
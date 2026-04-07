

#include <iostream>
//using namespace std;
	
	//usign caluse
	//using namespace std; not used in industry

int main()
{
	std::cout<<"Welcome Back!\n"; //Cout is output
	int num1; //declaring a variable
	int num2 = 10; //initializing a variable
	
	// \n is new line also you can use std::endl it creates a new line and stops any output buffer

	
	std::cout << "Enter a number: \n";
	std::cin >> num1;// >> num2; // you can have two input back to back like this
	std::cout << "Your number " << num1 << " is cool" << std::endl; // << acts acts like a concact
	//std::cout<< "Your number " << num2 << " is cool" << std::endl; // << acts acts like a concact
	
	
	
	//Data Types
	
	//char
	//flaot
	//int
	//double
	//long
	//long long
	//long double - same as double
	//short
	//bool
	
	bool hungry = true;
	std::cout << "In Am I Hungry? " << hungry << std::endl;// prints out 1 for true
	
	int a,b,c,d;
	a=b=c=d=0; // d gets assigned first beacuse d = 0 , c = d = 0, ect
	
	//Associativity
	
	//+
	//-
	//-------------
	//*
	// /
	// %
	
	//= is the assignment operator
	
	if(!hungry)
		std::cout << "In I Am \"not\" hungry \n";
	else
		std::cout << "In I am Hungry \n";
	
	
	//   
	// Lvalue == value
	// Can onlt be a sinlgle variable "a number: ";

	return 0;
}


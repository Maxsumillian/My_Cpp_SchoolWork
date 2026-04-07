#include <iostream>


//int calcValues(int num1, int num2); // prototype
int calcValues(int num1 = 0, int num2 = 1, int num3 = 1); // prototype of overload
// default values are powerful // all default values to the left require default values if one is added
//deafults are added to the first function that apears hence its shows abover main
int add(int x = 0,int y = 0);
float add(float x = 0,float y = 0);
void askInitials(char *firstPtr,char *lastPtr);
void askInitialsRef(char& first,char& last);

std::string add(std::string one, std::string two = "");// we can return a whole class/object 

int main(){
	
	int num1 = 5, num2 = 10, num3 = 2;
	int answers = calcValues(num1,num2, num3); //call(arguments))
	std::cout << "\n" << answers;
	
	answers = calcValues(num1,num2);
	std::cout << "\n" << answers;
	answers = calcValues(num1);
	std::cout << "\n" << answers;
	answers = calcValues();
	std::cout << "\n" << answers;
	float num4 = 2.1, num5 = 3.6;
	std::cout << "\nAdding: " << add(num1,num2);
	std::cout << "\n" << add(num4,num5);// cannot declare a variables in a print line;
	
	std::string first = "Max", last = "Yang";// declaring a string
	std::cout << "\nAdding: "<< add(first,last);
	
	//std::cout<<"\n" + first + " " + last; 
	
	char firstInitial, lastInitial;
	
	//askInitials(&firstInitial,&lastInitial);// & to send address
	//std::cout<<"\nYour Initals are" << askInitials(&firstInitial, &lastInitial);
	//std::cout<<"\nYour Initals are \"" << firstInitial<< "\" and \"" << lastInitial << "\"";
	
	askInitialsRef(firstInitial, lastInitial);
	std::cout<<"\nYour Initals are \"" << firstInitial<< "\" and \"" << lastInitial << "\"";
	
	std::cout<<"\nAdd "<< add(firstInitial, lastInitial);

}

//
//int calcValues(int num1, int num2){  //returndatatype function head(parameters) then funtion body 
//	return num1 * num2;
//}// coudl also do a overload

int calcValues(int num1, int num2, int num3){  // funciton
	return num1 * num2 * num3;
	
}

int add(int x, int y){
	return x + y;
}


float add(float x,float y){
	return x + y;
}


std::string add(std::string one, std::string two){
	return one + " " + two;
}

void askInitials(char *firstPtr,char *lastPtr){// pointers are good to return more than one datatype
	char first, last;
	std::cout<<"\nEnter your first Inital: ";
	std::cin>>first;
	std::cout<<"\nEnter your Last Inital:";
	std::cin>>last;
	
	*firstPtr = first;
	*lastPtr = last;
	
}



void askInitialsRef(char& first,char& last){// refrences here
	
	std::cout<<"\nEnter your first Inital: ";
	std::cin>>first;
	std::cout<<"\nEnter your Last Inital:";
	std::cin>>last;
	
	
}



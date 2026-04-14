#include <iostream>
#include "Date.h"
#include "Employee.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//======NOTES====

// Seperate compliation

//myProgram.cpp <--- source file
//myProg.o <-- object file
//myPro.exe

// when you compile we go from cource to the object file to compile 
// it doesnt just creat teh exe file unles its a singl efile
// Linking - then merges everything and goes into the exe

//beacseu of UNC and the school server you have to manually go to the file loaction the long way to save your files 

int main() {
	
//	Date birth(7,10,2000);
//	
//	birth.display();
	
	Employee Manager(11,21,2002,1,1,2027);
	
	Manager.getBirth().display();
	Manager.getHire().display();
	
	Manager.setBirth(2,2,2002);
	Manager.getBirth().display();
	
	
	return 0;
}

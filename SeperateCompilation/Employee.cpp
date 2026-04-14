#include "Employee.h"

Employee::Employee(int birthMonth, int birthDay,int birthYear,int hireMonth, int hireDay,int hireYear)
		: birth(birthMonth,birthDay,birthYear), hire(hireMonth, hireDay, hireYear){
	
};

Date Employee::getBirth(){
	return Employee::birth;
}
Date Employee::getHire(){
	return hire;// guess you dont need the score because its already in the scope
}


void Employee::setBirth(int birthMonth, int birthDay,int birthYear){
	Employee::birth = Date(birthMonth,birthDay,birthYear);//remeber when setting liek this i need to call the Class(arguments)
}

void Employee::setHire(int birthMonth, int birthDay,int birthYear){
	this->hire = Date(birthMonth,birthDay,birthYear);// guess you dont need the score because its already in the scope
}
// may be redundent if i am able to change the date in the date class but i may be wrong

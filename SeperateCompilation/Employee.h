#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Date.h"

class Employee
{
	
	//friend int main(); never make main a freind too exposed and 
	
	private:
		Date birth;
		Date hire;
		std::string name;
	public:
		Employee(int birthMonth, int birthDay,int birthYear,int hireMonth, int hireDay,int hireYear);
		
		Date getBirth();
		Date getHire();
		
		void setBirth(int birthMonth, int birthDay,int birthYear);
		void setHire(int birthMonth, int birthDay,int birthYear);
};

#endif

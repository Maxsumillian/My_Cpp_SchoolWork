#include "Date.h"
#include <iostream>

Date::Date(int month, int day, int year){
	Date::month = month;
	Date::day = day;
	Date::year = year;
}

void Date::display(){
	std::cout<<"\n"<<Date::month<<"/"<<Date::day<<"/"<<Date::year;
}

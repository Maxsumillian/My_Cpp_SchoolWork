#include "Rectangle.h"
#include <iostream>

void Rectangle::setData(int lenght, int width){
	this->lenght = lenght; // can use this or 
	Rectangle::width = width;// can use scope operator
}

void Rectangle::show(){
	counter++;
	std::cout<<"\nNum of Counter: "<<counter<<"\nDimensions: "<<lenght<<" x "<< width;
}

int Rectangle::compute(){
//	counter++;
	return lenght * width;
};

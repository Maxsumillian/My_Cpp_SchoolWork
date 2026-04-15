#include "Rectangle.h"
#include <iostream>

void Rectangle::setData(int lenght, int width){
	this->lenght = lenght; // can use this or 
	Rectangle::width = width;// can use scope operator
}

void Rectangle::show(){
	std::cout<<"Dimensions: "<<lenght<<" x "<< width;
}

int Rectangle::compute(){
	return lenght * width;
}

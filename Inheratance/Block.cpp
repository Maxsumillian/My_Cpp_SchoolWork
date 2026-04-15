#include "Block.h"
#include <iostream>



void Block::setData(int lenght, int width, int height){
	//if teh parents data is private you use the ublic variables to accsess or mutate them and you can and or change as well is useful if you want the parents varibels to be private
	Rectangle::setData(lenght,width);// doing this also set the variables even though we are calling the parent function // works with priavte data
//	Rectangle::lenght = lenght;// if we made the varibles protected then the data will be private for all other classes extecpt those that inherant from thje class.
//	Rectangle::width = width;
	Block::height = height;
	
}


void Block::show(){
//	std::cout<<"Dimensions: "<<lenght<<" x "<< width<< " x "<< height;
	Rectangle::show();///
//	std::cout<< "\nNumber of counter: "<<counter;// static vairbles are only for the class it self
	std::cout<<" x "<< height;
}

//static variabels are inherticance if not private but each inherited class has its onw instance of it being updated top down
	
int Block::compute(){
//	return lenght * width * height;
	return Rectangle::compute() * height;
//	return height;
};

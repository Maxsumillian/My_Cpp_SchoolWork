#include <iostream>

//#include "Rectangle.h"/// wont need ebacuse we havea child that has the rectangle 
#include "Block.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	
	Rectangle rect, square;

	rect.setData(10,11);
	rect.show();
	std::cout<<"\nArea: "<<rect.compute();
	
	std::cout<<"\n";
	square.setData(10,10);
	square.show();
	std::cout<<"\nArea: "<<square.compute();

	
	std::cout<<"\n";
	Block block;
	block.setData(10,11,12);
	block.show();
	std::cout<<"\nVolume: "<<block.compute();
	
	return 0;
}

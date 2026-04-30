#include <iostream>


int add(int x, int y);

int add(float x, float y){
	return x + y;
};
std::string add(std::string x, std::string y){
	return x + y;
};

int main(){
	std::string first="kim", last="Mosc";
	int a = 5, b = 10;
	float x = 2.8, y = 3.7;
	std::cout<<"\nInts: "<<add(a,b); 
	std::cout<<"\nFloats: "<<add(x,y); 
	std::cout<<"\nInts: "<<add(a,b); 
	
};

int add(int x, int y){
	return x + y;
};


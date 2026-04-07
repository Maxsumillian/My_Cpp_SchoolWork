#include <iostream>




void myFunction();// prototype used to declare the funciton so it can be used in the main 

int main(){
	
	int number = 5;
	
	for (int x = 0 ; x < 5; x++)
		myFunction();
	
	{
	// this is a block	
	int number = 22;
	
	number++;
	std::cout<<"\nmy number is "<<number;
		
	}
	
	number++;
	std::cout<<"\nmy number is "<<number;
		
	
	
	return 0;
}

void myFunction()
{
	int number = 0;
	
	std::cout<<" "<<number;
	
	number++;
}



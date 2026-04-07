# include <iostream>
# include <limits>
#include <iomanip>

int main()
{
	float number = 234.5678;
	
	{// this is a block
		
	float number2 = 12.34;
	
	std::cout << "in" << number << "\n";
		
	}
	
	std::cout << "in" << number << "\n";
	
	float age;
	std::cout<<"Enter your age: ";
	std::cin>>age;
	
	std::cout<<"You are "<< age <<" years old\n";
	
	while( std::cin.fail() || age <= 0)
	{
		std::cin.clear();//this turns the fail off so it doesnt repeat
		
		//wrong innifecient method
		//std::cin.ignore(10000,'\n');// this clears the input buffer because it still tries to tke in all the characters and fails
		//ignores the first 5 charcetrs and or if you enter
		
		//this is the scalable version
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//use this beacuse of hackers its a safty feature so when it clears the buffer there can be nothing left over 
		
		std::cout<<"invalid Try again\n";
		
		std::cin>>age;
		
	}
	
	/*
	{
		
	float pi=3.14159265359;
	
	std::cout<<"\n"<<pi;
	
	std::cout<<"\n"<<std::setw(10)<<pi;
	
	std::cout<<"\n"<<pi;
	
	std::cout<<"\n"<<std::setprecision(2)<<pi;// tunrs the whoel number into 2 digitd with precision
	std::cout<<"\n"<<std::setprecision(2)<<std::fixed<<pi; //fixed meanas two decimal 
	//also effects all outputs after it gets turned on
	
	std::cout<<"\n"<<pi;
		
	}
	*/
	
	std::string name;
	name = "ethics";
	
	
	char initial;
	std::cout<<"\n"<<"Enter your initial: ";
	std::cin>>initial;
	std::cout<<"\n"<<"Enter your name: ";
	std::cin.ignore(1000,'\n');//we need to get rid of hte input "enter" // '1000' for ease of use but use "std::numeric_limits<std::streamsize>::max()" is more secure and better
	
	//std::cin>>name;//stops when it see's a space
	
	std::getline(std::cin,name);
	
	std::cout<<"\nYou are "<<name<<" with the initial "<<initial;
	
	/*
	if (age >= 18)
		std::cout<<"\nAdult";
	else
		std::cout<<"\nChild";
	*/
	
	// Conditinal operator ? :
	//called a ternary operator has three operands
	//binary + = - / % etc. has two
	//uniary like ! ++ -- has one
	
	std::cout<<(age>=18)?"\nAdult":"\nChild"; //returns 0 or 1 // this bdoesnt work due to order of operand 
	std::cout<<((age>=18)?"\nAdult":"\nChild"); //fixed
	(age>=18)?std::cout<<"\nAdult":std::cout<<"\nChild"; // also works
	
//	bool answer;
	//if (age >= 18)
	//	answer = true;
	//else
	//	anser = false;
		
		
	bool answer = (age>=18);
	//all examples of things that work
	(age>=18)?answer = true:answer = false;
	answer = (age>=18)?true:false; 
	//bool answer = (age>=18);
	
	std::cout<<answer;
	
}

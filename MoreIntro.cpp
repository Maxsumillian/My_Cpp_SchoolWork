# include <iostream>
#include <cmath>

#include <iomanip>

int main()
{
	
	
	std::cout<<std::setprecision(20)<<std::fixed;
	
	int num1=4,num2=9;
	float answer = num1/num2;
	std::cout<<answer;
	
	answer=static_cast<float>(num1)/num2;//standard in c++
	std::cout<<"\n"<<answer;
	
	
	//asnwer = (float)num1/num2;//acceptable but not the standard
	std::cout<<"\n"<<answer;
	
	
	//answer = num1*1.0/num2;// also works by transforming num1 into a float
	std::cout<<"\n"<<answer;
	
	float amount = 60.00-56.06;
	
	std::cout<<"\n"<<amount;
	if(amount == 3.94)
		std::cout<<"\nYAY!";
	else
		std::cout<<"\nNOT EQUAL";
	
	
	if(fabs(amount-3.94) < .005)
		std::cout<<"\nYAY NOW!";
	else
		std::cout<<"\nERROR";
		
		/*
	switch(inital)
	{
		case 'k':
			{
			}
			break;
		case 75:
			{
			}
			break;
	}

	
	while(){}
	}
	
	do{}while();
	}
	
	for(){}
	}
	*/
	
}

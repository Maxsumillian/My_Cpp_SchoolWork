#include <iostream>
#include <limits>
#include <iomanip>

int main() 
{
    int testScore;
    
    std::cout<<"Enter a test score between 0 - 100: ";
    std::cin>>testScore;
    
    
    bool inRange = (testScore <= 100 && testScore >= 0);

    
    while(std::cin.fail() || !inRange) // while int fails and not in range
    {
    	if (std::cin.fail())// if the number isnot a number then fails
        	std::cout<<"\nYour grade must be numeric";
        else// if it fails while being a number that means its out of scope
        	std::cout<<"\nInvalid grade! Must be between 0 and 100";
        	
    	
    	std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//clears selection and "uses" all input from input buffer
		
    	
        	
    	std::cout<<"\nEnter a test score between 0 - 100: ";
    		
		std::cin>>testScore;
		inRange = (testScore <= 100 && testScore >=0);
    }
    
    
    if (testScore >= 90) 
        std::cout<<"You received an A";
    else if (testScore >= 80) 
        std::cout<<"You received a B";
    else if (testScore >= 70) 
        std::cout<<"You received a C";
    else if (testScore >= 60) 
        std::cout<<"You received a D";
    else  
        std::cout<<"You received an E";
    
        
    
    
    if (testScore >= 60)
        std::cout<<"\nYou passed!"<<std::endl;
    else
        std::cout<<"\nYou failed."<<std::endl;

    return 0;
}

/*
#include <iostream>
# include <limits>
#include <iomanip>

int main() 
{
    int testScore;
    
    std::cout<<"Enter a test score between 0 - 100: ";
    std::cin>>testScore;
    
    
    bool inRange = (testScore <= 100 && testScore >= 0);

    
    while(std::cin.fail() || !inRange)
    {
    	std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    	if (inRange)
        	std::cout<<"\nYour grade must be numeric";
        else
        	std::cout<<"\nInvalid grade! Must be between 0 and 100";
        	
        	
    	std::cout<<"\nEnter a test score between 0 - 100: ";
    		
		std::cin>>testScore;
		inRange = (testScore <= 100 && testScore >=0);
    }
    
    
    if (testScore >= 90) 
        std::cout<<"You received an A";
    else if (testScore >= 80) 
        std::cout<<"You received a B";
    else if (testScore >= 70) 
        std::cout<<"You received a C";
    else if (testScore >= 60) 
        std::cout<<"You received a D";
    else  
        std::cout<<"You received an E";
    
        
    
    
    if (testScore >= 60)
        std::cout<<"\nYou passed!"<<std::endl;
    else
        std::cout<<"\nYou failed."<<std::endl;

    return 0;
}

*/


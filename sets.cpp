#include <iostream>
#include <set>




int main()
{
	//a set is a container that takes the same type of data
	std::set<std::string> setOfNumbers;
	
	
	setOfNumbers.insert("first");
	setOfNumbers.insert("second");
	setOfNumbers.insert("third");
	setOfNumbers.insert("fourth");// since aplhpabetically fourht is second the set stores it second
	
	
	std::cout<<"\nSet Size: "<<setOfNumbers.size();
	
	
 
//	for(int x = 0; x < setOfNumbers.size(); x++)
//	{
//		
//	}
	
	//iterators are pointers that 
	std::set<std::string>::iterator it;	
	//above is the same as "int x" "[Datatype] [varibleName]"
	
	for (it = setOfNumbers.begin() ; it != setOfNumbers.end(); it++)
	{
		std::cout<<"\n"<< *it; // the pointer is returning the vairable inside the iterator
		std::cout<<" | Location in Memory: "<< &it;
		std::cout<<" | Size: "<< setOfNumbers.size();
		//prints by order
		//set put thigns in order
	}
	
	
	it = setOfNumbers.find("second");// looks for "second"
	if(it != setOfNumbers.end())//if not at the end then it found it
	{
		std::cout<<"\nFound: \""<<*it<<"\"";
	} else
	{
		std::cout<<"\nNot Found";
	}
	
	
	
	
	
	return 0;	
}

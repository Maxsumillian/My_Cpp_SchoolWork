// vectors

#include <iostream>
#include <vector>

int main()
{
	int tmep[5];// array
	
	std::vector<int> temps;// vector
	
	
//	temps[0] = 55;// ccompies but crashes because it doesnt have a first spot yet
		std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
		
	temps.push_back(1);// to add somthing to a vector we have to pushBack
	

	
	//std::cout<<"\n"<<temps[0];
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	temps.push_back(2);
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	temps.push_back(3);
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	temps.push_back(4);
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	temps.push_back(5);
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	temps.push_back(6);
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	temps.push_back(7);
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	temps.push_back(8);
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	temps.push_back(9);
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	temps.push_back(10);
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	temps[4] = 55;// able to change vectors like this 
	
	temps.pop_back(); // removes the latest back
	
	std::cout<<"\n Values in the vector :";
	for (int x = 0; x < temps.size(); x++)
	{
		std::cout<<" "<<temps[x];
	}
	
	std::cout<<"\n Size: " << temps.size()<<" Capacity: "<<temps.capacity();
	
	std::cout<<"\nRange Based For loop / Enhanced For Loop\n";
	for (int oneTemp : temps)// enhanced For loop
		std::cout<<" "<<oneTemp;
		//oneTemp is temporary it doesnt change the values in the vector
		
	
	std::cout<<"\nRange Based For loop / Enhanced For Loop\n";
	for (int oneTemp : temps)// enhanced For loop
	{
		oneTemp *= 10;
		std::cout<<" "<<oneTemp;
	}
		
		
	std::cout<<"\nRange Based For loop / Enhanced For Loop\n";
	for (int oneTemp : temps)// enhanced For loop
	{
		std::cout<<" "<<oneTemp;
	}	
	
	std::cout<<"\nRange Based For loop / Enhanced For Loop\n";
	for (int& oneTemp : temps)// enhanced For loop
	{// to actually change the real value we use a refrecne/ pointer it doesnt initialize a new variable it points to athe addresss of the original
		oneTemp *= 10;
		std::cout<<" "<<oneTemp;
	}
	std::cout<<"\nRange Based For loop / Enhanced For Loop\n";
	for (int oneTemp : temps)// enhanced For loop
		std::cout<<" "<<oneTemp;
	
	// Capacity scales off of memory while size is exact how much.
	
	return 0;
}






// Data strucure NOTES:

//Linear

// ----------STACK-------------
// a vector is a Stack data structure push adds and pop removes the top of the stack
// Uses LIFO
//Last in First Out

// ----------Queue-------------
// Uses FIFO
// First in First Out

// ----------DeQueue-----------
// allows able to grap and remove from both front and back

// ----------Linked list--------

//-----------Array------------

// Non-Linear









































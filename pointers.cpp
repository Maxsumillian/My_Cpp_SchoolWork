#include <iostream>


class Shoes
{
	public:
		std::string color;
		std::string style;
		float shoeSize;	// try not to use just size or type or any other key words used in thr language
		
		Shoes(std::string color, std::string style, float shoeSize)
		:color(color), style(style), shoeSize(shoeSize)
		{
			std::cout<<"\nCreating the "<<this->color<<" shoes!";
		}
		
		//destructor called at the end of the program 
		// since memeory is in a stack that means that when it gets dealocated it removes the last to first
		~Shoes()
		{
			std::cout<<"\nRemoving the "<<this->color<<" shoes!";
		}
		
		//creating a copy constructor class(class[address] variable)
		Shoes(Shoes& sendingShoes)
		{
			this->color = sendingShoes.color;
			this->style = sendingShoes.style;
			this->shoeSize = sendingShoes.shoeSize;
			std::cout<<"\nCopying the "<<this->color<<" shoes!";
		}
		
};


void displayShoes(Shoes onePair);
void displayShoesPointer(Shoes* onePair);

int main()
{
	
	
	
	Shoes myShoes("red", "tennis", 6.0);//memory gets pushed into memory
	
	{
		Shoes yourShoes("blue", "running", 7.5);	
	}//blue gets removed as soon as its created because its out of scope 
	
	Shoes theirShoes("white", "platforms", 8.0);
	
	
	
//	displayShoes(myShoes);// creates a copy and uses that copy to dooperations then deallocates the memory
	displayShoesPointer(&myShoes);// doesnt create a copy beacuse it uses the actaul varible in memeory instead of copying it
	
	
	// new operator always returns an addresss
	Shoes *shoePtr = new Shoes("green", "heels", 8.0);//creates an address for shoes and creates a dynmaic memory will not be lost when out of scope creates a memory leak
	// when you dynamically create an address for somthign it doesnt go in the stack it goes in the "heap"
	
	displayShoesPointer(shoePtr);
	
	delete shoePtr;// this will dealocate the address you defined in the heap
	
	
	
	
		
	return 0;
}// when the variable gets out of its scope it calls the destructor and pops the stored data


void displayShoes(Shoes onePair){//uses a copy constructor when doing this // this is a object
	std::cout<<"\n Shoes: "<<onePair.color<<" "<<onePair.style;
}// also removes sheos here too because the temp value onePair gets dealocated



void displayShoesPointer(Shoes* onePair){// this is an address so we need the arrow this pointer "->"
	std::cout<<"\n Shoes: "<<(*onePair).color<<" "<<onePair->style<<" "<<onePair->shoeSize;
}

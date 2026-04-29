#include <iostream>


class Pet
{
	public:
		std::string name;
		int age;
		virtual void print()// virtual checks for polymorpism and on run time if in children use childrens funcitons first
		{
			std::cout<<"\nName: "<< name;
			std::cout<<"\nAge: "<< age;
			
		}
		Pet()
		{
			name = "Unknown";
			age = 0;
		}
};


class Dog : public Pet
{
	public:
		std::string breed;
		
		void print()
		{
			Pet::print();
//			std::cout<<"\nName: "<< name;
//			std::cout<<"\nAge: "<< age;
			std::cout<<"\nBreed: "<< breed;
		}
		
};

int main()
{
	Dog vDog;
	Pet vPet;
	vDog.name = "Titus";
	vDog.age = 5;
	vDog.breed = "Malamute";
	vDog.print();
	
	vPet.print();//prints nothing/garbage because it hasnt been initalized
	//possible it send the other data to garbage
	vPet = vDog;// this is called truncating for numbers but for obejcts its called slicing
	vPet.print();
	
//	vDog = vPet;// this does not work this way
	
	//create two pointers
	Pet *myPet;
	Dog * myDog;
	
	myPet = &vPet;
	myDog = &vDog;
	
//	myDog = &vPet;
	myPet = &vDog;//this is allowed
	
//	myDog = Dog cDog;// this does not work	
	myDog = new Dog; //creates a new dog somewhere in memory and returns the address
	//ablity to creat a new object with a pointer you use the "new" command 
	
	myDog->name="EKKO";
	myDog->age=3;
	myDog->breed="Mutt";
	myDog->print();//if the variables are privateyouwoudl still us ethe arrrow to get it because we have an address
	
	myPet = myDog;// when using virtual and pointers we are able to complete polymorpishm // beacuse we are storing and address we arnt slicing the data so using a virtual we can keep the data
	myPet->print();
	
	
	
}

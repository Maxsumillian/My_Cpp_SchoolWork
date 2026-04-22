#include <iostream>


class Pet
{
	public:
		std::string name;
		int age;
		void print()
		{
			std::cout<<"\nName Only: "<< name;
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
			std::cout<<"\nName: "<< name;
			std::cout<<"\nAge: "<< age;
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
	
	
}

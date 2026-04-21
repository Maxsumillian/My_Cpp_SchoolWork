#include <iostream>


class Animal
{
	public:
		void says()
		{
			std::cout<<"\nNothing";
		}
};

// child of Animal
class Dog : public Animal
{
	public:
		void says()
		{
			std::cout<<"\nWoof Woof";
		}
};


class Cat : public Animal
{
	public:
		void says()
		{
			std::cout<<"\nMeow Meow";
		}
};

void saySomthing(Animal a);

int main(){
	
	Animal oneAnimal;
	Dog myDog;
	Cat yourCat;
	
	oneAnimal.says();
	myDog.says();
	yourCat.says();
	
	saySomthing(oneAnimal);
	saySomthing(myDog);
	saySomthing(yourCat);
	
	
	
	
	return 0;
};


void saySomthing(Animal a)
{
	a.says();
};


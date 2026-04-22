#include <iostream>


class Animal
{
	private:
		int age;
	public:
//		void says()
//		{
//			std::cout<<"\nNothing";
//		}
		// add virtual here to do polymorphism
		// this is dynamic binding
//		virtual void says()
//		{
//			std::cout<<"\nNothing";
//		}
		
		virtual void says() = 0;// this is called abstract so we cannot create an animal but we can use it
		
		virtual void setAge(int a) {
			age = a;
		}
		virtual int getAge() {
			return age;
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

void saySomthing(Animal *a);
//void saySomthing(Animal a);
//void saySomthing(Dog a);
//void saySomthing(Cat a);

int main(){
	
//	std::Anima
	
	
//	Animal oneAnimal;
	Dog myDog;
	Cat yourCat;
	
//	oneAnimal.says();
//	myDog.says();
//	yourCat.says();

//	saySomthing(&oneAnimal);
	saySomthing(&myDog);
	saySomthing(&yourCat);
	
	
	
	
	return 0;
};
// right now its static and assums we are sending an animal
//to fix this we are going to makae t virtual
void saySomthing(Animal *a)
{
	int age;
	a->says();
	std::cout<<"\nEnter age : ";
	std::cin>>age;
	a->setAge(age);
	std::cout<<"Animal Age is "<<a->getAge();
};

//void saySomthing(Animal a)
//{
//	a.says();
//};

//void saySomthing(Dog a)
//{
//	a.says();
//};
//
//void saySomthing(Cat a)
//{
//	a.says();
//};



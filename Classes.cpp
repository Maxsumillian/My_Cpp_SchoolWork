#include <iostream>


////creates the struct here
//struct Pet
//{
//	std::string type;
//	std::string name;
//	int age;
//};


//creates class
class Pet
{	
	private://everythign that is private [Data is always private]
	
		std::string type = "N/A";// this is a default value
		std::string name = "NULL";
		int age = 0;
		
	public://defines whats public in the class
	
	//constructor function 
		Pet()//default constructpr
		{	
		
		}
		
		Pet(std::string t)
		{
			type = t;
		}
		
		Pet(std::string t, std::string n)
		{
			type = t;
			name = n;
		}
		
		Pet(std::string t, std::string n, int a)
		{
			type = t;
			name = n;
			age = a;
		}
		
		
	
	//Mutators and Accessors
		//Mutators(Set Functions)
		void setType(std::string type)	{this-> type = type;}// this is a pointer that points to class variable address to use
		void setName(std::string t)		{name = t;}
		void setAge	(int ageInput)		{age = ageInput;}
	
		//Accessors(Get Funcitons)
		std::string getType()			{return type;}
		std::string getName()			{return name;}
		int 		getAge()			{return age;}
		
	// Utility functions
		void DisplayPet()
		{
			std::cout << "\n" << type << " " << name << " is " << age;
		}
	
		std::string toString()
		{
			return "\n" + type + " " + name + " is " + std::to_string(age);
		}
		
		
};//end Pet Class


int main()
{
//	Pet myPet(); // this is wrong becaues its tyring to do a funciton call but it doesnt need it so it breaks
	Pet myPet;// these are objects of a class.
	Pet yourPet;// when you create an object, its called Instantiation(Create an "instance" of)
	Pet theirPet("Chicken", "Chuck",1);// using a construcor
	
	
	//test
	Pet a, b("Bird"), c("Snake", "Slither"), d("turtle","carl",3);
	
	//private data unaccesable
//	myPet.type = "Dog";
//	myPet.name = "Strider";
//	myPet.age = 5;

	myPet.setType("Dog");
	myPet.setName("Strider");
	myPet.setAge(5);
	
	yourPet.setType("Pet ROCK");
	yourPet.setName("rocky");
	yourPet.setAge(3);
	
	//missing () for funciton calls
	//std::cout<<"\nMy "<<myPet.type<<" "<<myPet.name<<" is "<<myPet.age;
	
	std::cout << "\nMy " << myPet.getType() << " " << myPet.getName() << " is " << myPet.getAge();
	std::cout << "\nYour " << yourPet.getType() << " " << yourPet.getName() << " is " << yourPet.getAge();
	std::cout << "\nTheir " << theirPet.getType() << " " << theirPet.getName() << " is " << theirPet.getAge();
	
	
	
	std::cout << "\na " << a.getType() << " " << a.getName() << " is " << a.getAge();
	std::cout << "\nb " << b.getType() << " " << b.getName() << " is " << b.getAge();
	std::cout << "\nc " << c.getType() << " " << c.getName() << " is " << c.getAge();
	std::cout << "\nd " << d.getType() << " " << d.getName() << " is " << d.getAge();
	
	myPet.DisplayPet();
	std::cout << myPet.toString();


}

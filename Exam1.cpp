#include <iostream>
#include <string>
#include <vector>
#include <limits>



class Habitat{
	private:
		std::string habitat;
		std::string climate;
		int temperature;
	public:
		Habitat(std::string habitat, std::string climate, int temperature)
		:habitat(habitat), climate(climate), temperature(temperature)
		{
		}
		
		std::string getHabitat(){return habitat;}
		std::string getClimate(){return climate;}
		int getTemperature(){return temperature;}
		
		std::string getString(){
			return habitat + " - " + climate + " - " + std::to_string(temperature) + "F";// figure out how to convert int ot string
		}
	
	
};

class ZooAnimal{
	
	friend std::ostream& operator<<(std::ostream& o, ZooAnimal animal);
	
	private:
		std::string name;//
		std::string species;
		int age;//
		Habitat habitat;//
		std::string category;//mammal bird reptile
		bool hasFur;
		bool canFly;
		bool isColdBlood;
		std::string favoriteFood;
		float wingspan;
		std::string skinType; //scales, smooth
	public:
		ZooAnimal(std::string name, std::string species, int age, Habitat habitat, std::string category)
		:habitat(habitat)
		{
			this->name = name;
			this-> age = age;
//			this->habitat = habitat;
			this->species = species;
			this->category = category;
			hasFur = false;
			canFly = false;
			isColdBlood = false;
			favoriteFood = "Unknown";
			wingspan = 0;
			skinType = "Unknown";
		}
		
		ZooAnimal()
		:habitat("Unknown","Unknown",0)
		{
			
			name = "Unknown";
			age = 0;
//			habitat = Habitat("Unknown","Unknown",0);
			species = "Unknown";
			category = "Unknown";
			hasFur = false;
			canFly = false;
			isColdBlood = false;
			favoriteFood = "Unknown";
			wingspan = 0;
			skinType = "Unknown";
		}
		
		std::string getName(){return name;}
		std::string getCategory(){return category;}
		std::string getSpecies(){return species;}
		
		std::string feed(){
			if(category == "Mammal")
				return "The Zookeeper feeds " + name + " the mammal diet of " + favoriteFood + ".";// meat may be a variable
			if(category == "Bird")
				return "The Zookeeper feeds " + name + " seeds and fruit";
			if(category == "Reptile")
				return "The Zookeeper feeds " + name + " in the reptile habitat.";
				
				
			return "No feed";
		}
		
		void display(){
			std::cout<<"\n=== " + category + " ===";
			std::cout<<"\n";
			std::cout<<"\nName: "<<name;
			std::cout<<"\nSpecies:"<<species;
			std::cout<<"\nAge:"<<age;
			std::cout<<"\nHabitat:"<<habitat.getString();
			
			std::string trueOrFalse;
			
				
			if(category == "Mammal")
			{
				if(hasFur)
					trueOrFalse = "true";
				else
					trueOrFalse = "true";
					
				std::cout<<"\nHas Fur: "<<  trueOrFalse;
				std::cout<<"\nFavorite food: "<<favoriteFood;
					
			}
							
			if(category == "Bird")
			{
				if(canFly)
					trueOrFalse = "true";
				else
					trueOrFalse = "true";
					
				std::cout<<"\nCan Fly: "<<  trueOrFalse;
				std::cout<<"\nWingSpan: "<<wingspan;
					
			}
			if(category == "Reptile")
			{
				if(isColdBlood)
					trueOrFalse = "true";
				else
					trueOrFalse = "true";
					
				std::cout<<"\nCold Blooded: "<<  trueOrFalse;
				std::cout<<"\nSkin Type: "<<skinType;
					
			}
			
		}// end of dipsplay
		
		//this overloads the = sign to take in a string 
		void operator=(std::string category){ //compares a string[category] to a string and returns this
			if(category == "Mammal")
			{
				std::cout<<"\nDoes the animal have fur (1 for true, 0 for false): ";
				std::cin>>hasFur;
				std::cout<<"\nEnter their favorite food: ";
				std::cin>>favoriteFood;
			}
							
			if(category == "Bird")
			{	
				std::cout<<"\nCan the animal fly (1 for true, 0 for false): ";
				std::cin>>canFly;
				std::cout<<"\nEnter wingspan: ";
				std::cin>>wingspan;
			}
			if(category == "Reptile")
			{
				std::cout<<"\ns the animal Cold blooded (1 for true, 0 for false): ";
				std::cin>>isColdBlood;
				std::cout<<"\nEnter skin type: ";
				std::cin>>skinType;
			}
		}
		
		
	
};

std::ostream& operator<<(std::ostream& o, ZooAnimal animal)
{
	animal.display();
	o<<"\nCategory: "<<animal.category<<"\n"<<animal.feed();
}

//std::ostream& operator<<(std::ostream& o, ZooAnimal animal)
//{
//	//animal.display();
//	
//	o<<"\nAnimal: "<<animal.name<< " "<< animal.species << " the "<< animal.category <<"\n"<<animal.feed();
//}
//		
//		

void enterAnimalData(std::vector<ZooAnimal> animalList){
	
	for(ZooAnimal animal: animalList)
	{
		std::cout<< "\nAnimal: " << animal.getName() << " "<< animal.getSpecies() << " the "<< animal.getCategory();
		animal=animal.getCategory();
		
	}
	
//	for (int oneTemp : temps)// enhanced For loop
//	{
//		oneTemp *= 10;
//		std::cout<<" "<<oneTemp;
//	}
//	
}
//
void countAnimals(std::vector<ZooAnimal> animalList){
	
	
	
	std::cout<<"NUmber of " ;
}


int main(){
	
	Habitat savannah("Savannah Zone", "Warm and grassy", 85),
			rainforest("Rainforest Dome", "Humid and tropical", 78),
			aviary("Aviary", "Flying enclosure", 72),
			desert("Desert Habitat", "Hot and dry", 95);
	
	std::vector<ZooAnimal> animals;
	
	ZooAnimal 	animal1("Leo", "Lion", 5, savannah, "Mammal"),
			    animal2("Ella", "Elephant", 12, savannah, "Mammal"),
			    animal3("Rio", "Macaw", 3, aviary, "Bird"),
			    animal4("Ozzy", "Owl", 4, rainforest, "Bird"),
			    animal5("Sly", "Snake", 6, desert, "Reptile"),
			    animal6("Tank", "Turtle", 40, rainforest, "Reptile");
			    
	
	animals.push_back(animal1);
	animals.push_back(animal2);
	animals.push_back(animal3);
	animals.push_back(animal4);
	animals.push_back(animal5);
	animals.push_back(animal6);
	
	enterAnimalData(animals);
	
	int choice;
	std::cout<<"\nEnter a category to count (1-Mammal, 2-Bird, 3-Reptile): ";
	std::cin>>choice;
	
	
	bool inRange = (choice <= 3 && choice >= 1);

    while(std::cin.fail() || !inRange) // while int fails and not in range
    {
    	if (std::cin.fail())// if the number isnot a number then fails
    	std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//clears selection and "uses" all input from input buffer
    	std::cout<<"\nEnter a category to count (1-Mammal, 2-Bird, 3-Reptile): ";
    		
		std::cin>>choice;
		inRange = (choice <= 3 && choice >=1);
    }
    
    
//    =============================//unfinishhed 
//    if(choice == 1)
//    {
//    	for (int x = 0; x < animals.size(); x++)
//		{
//			if(animals[x].getCategory == "Mammal")//unfinishhed 
//				std::cout<<animals[x];
//		}
//	}
//	if(choice == 2)
//    {
//    	for (int x = 0; x < animals.size(); x++)
//		{
//			if(animals[x].getCategory == "Bird")
//				std::cout<<animals[x];
//		}
//	
//	}
//	if(choice == 3)
//    {
//    	for (int x = 0; x < animals.size(); x++)
//		{
//			if(animals[x].getCategory == "Reptile")
//				std::cout<<animals[x];
//		}
//	
//	}

}

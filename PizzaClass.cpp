#include <iostream>
//#include <string>


//im adding this comment as a test for pushign on git
class Pizza
{
	private:
		std::string pizzaSize;
		int numToppings;
		std::string pizzaType;// round, square, deepdish, chicago, newYork, Detroit
		double price;
		
	public:
		//Condtructors
//		Pizza(){}
		
//		pizza(std::string pizzaSize){	
//			this.pizzaSize = pizzaSize;
//		}
//		
//		pizza(std::string pizzaSize, int numToppings){
//			this.pizzaSize = pizzaSize;
//			this.numToppings = numToppings;
//		}
		
		
		//modular way to create a default constructor defalt values in the arguments
		Pizza(std::string pizzaSize = "Extra Large", int numToppings = 1, std::string pizzaType = "round")
		{
			this->pizzaSize = pizzaSize;
			this->numToppings = numToppings;
			this->pizzaType = pizzaType;
			price = 0;
		}
		
//		pizza(std::string pizzaSize, int numToppings, std::string pizzaType, double price){
//			
//			this.pizzaSize = pizzaSize;
//			this.numToppings = numToppings;
//			this.pizzaType = pizzaType
//			this.price = price;
//			
//		}

		//Utility Functions
		
		std::string getDesciprion()
		{
			std::string word = " toppings";
			
			if (numToppings == 1)
				word = " topping";
			
			return pizzaSize + " " + pizzaType + " pizza with " + std::to_string(numToppings) + word;
		}
		
};



Pizza createPizza();

void displayPizza(Pizza onePizza);

int main(){
	
	Pizza pizza1("Large",4,"ThinCrust");
	Pizza pizza2("Medium",3);
	Pizza pizza3("small");
	Pizza pizza4;
	Pizza pizza5;
	
	std::cout<<"\n"<<pizza1.getDesciprion();
	std::cout<<"\n"<<pizza2.getDesciprion();
	std::cout<<"\n"<<pizza3.getDesciprion();
	std::cout<<"\n"<<pizza4.getDesciprion();
	
	Pizza onePizza = createPizza();
	
	displayPizza(onePizza);
	
};


Pizza createPizza()
{
	std::string pizzaSize;
	int numToppings;
	std::string pizzaType;
	
	std::cout<<"\nWhat size pizza would you like? ";
	std::cin>>pizzaSize;
	
	std::cout<<"\nHow many pizza toppings would you like? ";
	std::cin>>numToppings;
	std::cin.ignore();
	
	std::cout<<"\nWhat type of pizza would you like? ";
	std::getline(std::cin, pizzaType);
	
	
	Pizza onePizza(pizzaSize,numToppings, pizzaType);
	
	return onePizza;
};


void displayPizza(Pizza onePizza)
{
	
	std::cout<<"\n"<<onePizza.getDesciprion();
};

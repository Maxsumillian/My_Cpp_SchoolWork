#include <iostream>
#include <map>



class Pizza {
	private:
		int toppings;
	public:
		Pizza() {toppings = 5;}
		int getToppings(){return toppings;}
		
};







int main(){
	
	Pizza aPizza;
	
	std::map<int,Pizza> order;
	
	order.insert(std::make_pair(111,aPizza));
	
	for(std::map<int,Pizza>::iterator it = order.begin(); it != order.end(); it++)
	{
//		std::cout << "\n" << it->first << " - " << it->second;
	}
	
	
	
	
	
}

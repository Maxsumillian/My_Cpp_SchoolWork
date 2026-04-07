
#include <iostream>



class RetailItem
{
		
	private:
		std::string description;
		int unitsOnHand;
		double price;
		int reorderQuantity; //holds the lowest qunatity of units before the store has to order more
		
	public:
		//thsi default Item handels overloaded too
		RetailItem(std::string description = "",int unitsOnHand = 0,double price = 0,int reorderQuantity = 0)
		{
			this->description = description;
			this->unitsOnHand = unitsOnHand;
			this->price = price;
			this->reorderQuantity = reorderQuantity;
		}
		
		void setDescription(std::string descirption)
		{
			this->description = descirption;
		}
		
		void setUnitsOnHand(int unitsOnHand)
		{
			this->unitsOnHand = unitsOnHand;
		}
		
		void setPrice(double price)
		{
			this->price = price;
		}
		
		void setReorderQuantity(int reorderQuantity)
		{
			this->reorderQuantity = reorderQuantity;
		}
		
		
		std::string getDescription(){return description;}
		int getunitsOnHand(){return unitsOnHand;}
		double getPrice(){return price;}
		int getReorderQuantity(){return reorderQuantity;}
		
};

int main()
{
	
	RetailItem testItem5;
	RetailItem testItem;
	RetailItem testItem2("somthing");
	RetailItem testItem3("somthing again", 3);
	RetailItem testItem4("somthign again again", 2, 10);
	
	

}

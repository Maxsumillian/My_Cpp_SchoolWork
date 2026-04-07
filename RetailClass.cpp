
#include <iostream>
# include <limits>



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
		int getUnitsOnHand(){return unitsOnHand;}
		double getPrice(){return price;}
		int getReorderQuantity(){return reorderQuantity;}
		
};

RetailItem createItem() {
	std::string description;
	int unitsOnHand;
	double price;
	int reorderQuantity;

	std::cout << "What Item are you adding ";
	std::getline(std::cin,description);
	std::cout << "How many do you currently have in stock? ";
	std::cin >> unitsOnHand;
	std::cout << "How much do i sell it for? ";
	std::cin >> price;
	std::cout << "how many left before i need to order more? ";
	std::cin >> reorderQuantity;

	RetailItem addedItem(description,unitsOnHand,price,reorderQuantity);

	return addedItem;
}




void addInventoryItem(RetailItem arr[], RetailItem value)
{
	static int size = 0;      // current number of elements
	int capacity = 20;       // maximum capacity

	if (size < capacity) {
		arr[size] = value; // store value after first element
		size++;              // increment size
	} else {
		std::cout << "Array is full!\n";
	}
}


void displayInventoryItems(RetailItem inventory[])
{
	for (int i = 0; i < 20; i++)
		std::cout << i << ": " << inventory[i].getDescription() <<" | stock: "<<inventory[i].getUnitsOnHand()<<" | $"<<inventory[i].getPrice()<< std::endl;
}



int checkItemInInventory(RetailItem inventory[], std::string itemName)
{
	for (int i = 0; i < 20; i++)
		{
			if (inventory[i].getDescription() == itemName)
				return i;//if found returns the index
		}
	return -1;//returns -1 if none
}


void displayItemsToReorder(RetailItem inventory[])
{
	std::cout << "\nItems to restock:\n";
	for (int i = 0; i < 20; i++)
		if (inventory[i].getUnitsOnHand() <= inventory[i].getUnitsOnHand() && inventory[i].getDescription() != "")
			std::cout << i << ": " << inventory[i].getDescription() <<" | stock: "<<inventory[i].getUnitsOnHand()<<" | $"<<inventory[i].getPrice()<< std::endl;
}


//returns true or false based on if it sucseffully completed its task if it fails then the funciton calling it understands and can run accordenly
bool updateItemInInventory(RetailItem inventory[], std::string itemName)
{
		// because i decided to return a index i can use it for muiltiple uses here as a check and to instantly get the index
	int index = checkItemInInventory(inventory, itemName);
	if (index == -1)
		return false;


	int inputChoice;
	while (true) {
		std::cout << "\nWhat woudl you like to change?";
		std::cout << "\n0) to exit";
		std::cout << "\n1) Item Description";
		std::cout << "\n2) Units on Hand";
		std::cout << "\n3) Item Price";
		std::cout << "\n4) update minimum requirment for restock";
		std::cin >> inputChoice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (inputChoice == 0) {
			return false;
		}

		if (inputChoice == 1) {
			std::string newName;
			std::cout << "\nEnter item name: ";
			std::getline(std::cin,newName);
			inventory[index].setDescription(newName);
			break;
		}
		else if (inputChoice == 2) {
			int itemQuantity;
			std::cout << "\nEnter item quantity: ";
			std::cin >> itemQuantity;
			inventory[index].setUnitsOnHand(itemQuantity);
			break;
		}
		else if (inputChoice == 3) {
			double price;
			std::cout << "\nEnter item price: ";
			std::cin >> price;
			inventory[index].setPrice(price);
			break;
		}
		else if (inputChoice == 4) {
			int reorderQuantity;
			std::cout << "\nEnter new minimum requirment for restock: ";
			std::cin >> reorderQuantity;
			inventory[index].setReorderQuantity(reorderQuantity);
			break;
		}
		else {
			std::cout << "\nPlease Try Again: ";
		}
	}

	return true;
}

// i should make a toolbox of scalable input with built in input validation
int displayMenu() {
	int inputChoice;
	while (true) {
		std::cout << "\nSelect your options";
		std::cout << "\n0) exit program";
		std::cout << "\n1) display Inventory";
		std::cout << "\n2) add Item to inventory";
		std::cout << "\n3) Search Inventory";
		std::cout << "\n4) display Items to ReOrder";
		std::cout << "\n5) Update Item in Inventory";
		std::cin >> inputChoice;
		if (!std::cin.fail() && inputChoice <= 5 && inputChoice >= 0) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a number.\n";
	}
	return inputChoice;
}

void menu(RetailItem inventory[]) {
	bool running = true;
	while (running) {
		int choice = displayMenu(); // returns 0–5

		switch (choice) {
			case 0: // Exit program
				std::cout << "Exiting program...\n";
				running = false;
				break;

			case 1: // Display Inventory
				displayInventoryItems(inventory);
				break;

			case 2: { // Add Item to Inventory
				RetailItem newItem = createItem();
				addInventoryItem(inventory, newItem);
				break;
			}

			case 3: { // Search Inventory
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear leftover newline
				std::string searchName;
				std::cout << "Enter item name to search: ";
				std::getline(std::cin, searchName);

				int index = checkItemInInventory(inventory, searchName);
				if (index != -1) {
					std::cout << "Found: " << inventory[index].getDescription()
							  << " | Stock: " << inventory[index].getUnitsOnHand()
							  << " | Price: $" << inventory[index].getPrice() << "\n";
				} else {
					std::cout << "Item not found.\n";
				}
				break;
			}

			case 4: // Display Items to Reorder
				displayItemsToReorder(inventory);
				break;

			case 5: { // Update Item in Inventory
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear leftover newline
				std::string updateName;
				std::cout << "Enter item name to update: ";
				std::getline(std::cin, updateName);

				if (!updateItemInInventory(inventory, updateName))
					std::cout << "Update failed or cancelled.\n";
				break;
			}

			default:
				// This should never happen because displayMenu already validates input
				std::cout << "Invalid choice. Try again.\n";
				break;
		}
	}


}

int main()
{

	// RetailItem testItem1("Apple");
	// RetailItem testItem2("Bed", 3);
	// RetailItem testItem3("Car", 2, 10);


	// std::cout<<testItem3.getUnitsOnHand();



	RetailItem inventory[20];

	// addInventoryItem(inventory, testItem1);
	// addInventoryItem(inventory, testItem2);
	// addInventoryItem(inventory, testItem3);
	//
	// // int index = 1;
	// // for (RetailItem item : inventory)
	// // {
	// // 	std::cout << index <<" descirption: "<< item.getDescription() << std::endl;
	// // 	index++;
	// // }
	//
	// displayInventoryItems(inventory);
	//
	// std::cout<<"\n"<<checkItemInInventory(inventory, "Apple");
	// std::cout<<"\n"<<checkItemInInventory(inventory, "Appleq");
	//
	// displayItemsToReorder(inventory);
	//
	//
	// RetailItem newItem;
	// newItem = createItem();
	//
	//
	// addInventoryItem(inventory, newItem);
	// displayInventoryItems(inventory);
	//
	// updateItemInInventory(inventory, "Apple");
	// displayInventoryItems(inventory);

	menu(inventory);

}

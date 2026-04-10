#include <iostream>
#include <limits>
#include <string>

const int MAX_INVENTORY = 20;

class RetailItem
{
private:
	std::string description;
	int unitsOnHand;
	double price;
	int reorderQuantity; // holds the lowest quantity of units before the store has to order more

public:
	// this constructor works as both the default and overloaded constructor
	RetailItem(std::string description = "", int unitsOnHand = 0, double price = 0, int reorderQuantity = 0)
	{
		this->description = description;
		this->unitsOnHand = unitsOnHand;
		this->price = price;
		this->reorderQuantity = reorderQuantity;
	}

	void setDescription(std::string description)
	{
		this->description = description;
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

	std::string getDescription() const { return description; }
	int getUnitsOnHand() const { return unitsOnHand; }
	double getPrice() const { return price; }
	int getReorderQuantity() const { return reorderQuantity; }
};

// I should make a toolbox of scalable input with built-in input validation
void clearInputBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getValidatedInt(std::string prompt)
{
	int value;
	while (true)
	{
		std::cout << prompt;
		std::cin >> value;

		if (!std::cin.fail())
		{
			clearInputBuffer();
			return value;
		}

		clearInputBuffer();
		std::cout << "Invalid input. Please enter a whole number.\n";
	}
}

double getValidatedDouble(std::string prompt)
{
	double value;
	while (true)
	{
		std::cout << prompt;
		std::cin >> value;

		if (!std::cin.fail())
		{
			clearInputBuffer();
			return value;
		}

		clearInputBuffer();
		std::cout << "Invalid input. Please enter a valid decimal number.\n";
	}
}

std::string getValidatedString(std::string prompt)
{
	std::string value;
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, value);

		if (!value.empty())
			return value;

		std::cout << "Input cannot be empty. Please try again.\n";
	}
}

RetailItem createItem()
{
	std::string description = getValidatedString("What item are you adding? ");
	int unitsOnHand = getValidatedInt("How many do you currently have in stock? ");
	double price = getValidatedDouble("How much do you sell it for? ");
	int reorderQuantity = getValidatedInt("How many left before you need to order more? ");

	RetailItem addedItem(description, unitsOnHand, price, reorderQuantity);
	return addedItem;
}

bool addInventoryItem(RetailItem inventory[], int& inventorySize, RetailItem value)
{
	if (inventorySize < MAX_INVENTORY)
	{
		inventory[inventorySize] = value;
		inventorySize++;
		return true;
	}
	else
	{
		std::cout << "Inventory is full!\n";
		return false;
	}
}

void displayInventoryItems(RetailItem inventory[], int inventorySize)
{
	if (inventorySize == 0)
	{
		std::cout << "\nInventory is empty.\n";
		return;
	}

	std::cout << "\n--- Inventory ---\n";
	for (int i = 0; i < inventorySize; i++)
	{
		std::cout << i << ": "
				  << inventory[i].getDescription()
				  << " | Stock: " << inventory[i].getUnitsOnHand()
				  << " | $" << inventory[i].getPrice()
				  << " | Reorder At: " << inventory[i].getReorderQuantity()
				  << std::endl;
	}
}

int checkItemInInventory(RetailItem inventory[], int inventorySize, std::string itemName)
{
	for (int i = 0; i < inventorySize; i++)
	{
		if (inventory[i].getDescription() == itemName)
			return i;
	}
	return -1;

	// I thought I had a little hack by returning the index and -1 as "nothing"
	// and honestly that actually is a legit useful pattern
}

void displayItemsToReorder(RetailItem inventory[], int inventorySize)
{
	bool foundItemsToReorder = false;
	std::cout << "\n--- Items to Restock ---\n";

	for (int i = 0; i < inventorySize; i++)
	{
		if (inventory[i].getUnitsOnHand() <= inventory[i].getReorderQuantity())
		{
			std::cout << i << ": "
					  << inventory[i].getDescription()
					  << " | Stock: " << inventory[i].getUnitsOnHand()
					  << " | $" << inventory[i].getPrice()
					  << " | Reorder At: " << inventory[i].getReorderQuantity()
					  << std::endl;

			foundItemsToReorder = true;
		}
	}

	if (!foundItemsToReorder)
		std::cout << "No items currently need to be reordered.\n";
}

// returns true or false based on whether it successfully completed its task;
// if it fails, then the function calling it understands and can respond accordingly
bool updateItemInInventory(RetailItem inventory[], int inventorySize, std::string itemName)
{
	// because I decided to return an index, I can use it for multiple purposes here:
	// as a check and to instantly get the index
	int index = checkItemInInventory(inventory, inventorySize, itemName);

	if (index == -1)
		return false;

	int inputChoice;
	while (true)
	{
		std::cout << "\nWhat would you like to change?";
		std::cout << "\n0) Exit";
		std::cout << "\n1) Item Description";
		std::cout << "\n2) Units on Hand";
		std::cout << "\n3) Item Price";
		std::cout << "\n4) Update minimum requirement for restock\n";

		inputChoice = getValidatedInt("Enter choice: ");

		if (inputChoice == 0)
			return false;

		if (inputChoice == 1)
		{
			std::string newName = getValidatedString("Enter new item name: ");
			inventory[index].setDescription(newName);
			break;
		}
		else if (inputChoice == 2)
		{
			int itemQuantity = getValidatedInt("Enter new item quantity: ");
			inventory[index].setUnitsOnHand(itemQuantity);
			break;
		}
		else if (inputChoice == 3)
		{
			double price = getValidatedDouble("Enter new item price: ");
			inventory[index].setPrice(price);
			break;
		}
		else if (inputChoice == 4)
		{
			int reorderQuantity = getValidatedInt("Enter new minimum requirement for restock: ");
			inventory[index].setReorderQuantity(reorderQuantity);
			break;
		}
		else
		{
			std::cout << "Please try again.\n";
		}
	}

	return true;
}

int displayMenu()
{
	int inputChoice;
	while (true)
	{
		std::cout << "\n========== Inventory Menu ==========";
		std::cout << "\n0) Exit Program";
		std::cout << "\n1) Display Inventory";
		std::cout << "\n2) Add Item to Inventory";
		std::cout << "\n3) Search Inventory";
		std::cout << "\n4) Display Items to ReOrder";
		std::cout << "\n5) Update Item in Inventory";
		std::cout << "\n====================================\n";

		std::cin >> inputChoice;

		if (!std::cin.fail() && inputChoice <= 5 && inputChoice >= 0)
		{
			clearInputBuffer();
			break;
		}

		clearInputBuffer();
		std::cout << "Invalid input. Please enter a number from 0 to 5.\n";
	}
	return inputChoice;
}

void menu(RetailItem inventory[], int& inventorySize)
{
	bool running = true;

	while (running)
	{
		int choice = displayMenu();

		switch (choice)
		{
			case 0:
				std::cout << "Exiting program...\n";
				running = false;
				break;

			case 1:
				displayInventoryItems(inventory, inventorySize);
				break;

			case 2:
			{
				RetailItem newItem = createItem();
				if (addInventoryItem(inventory, inventorySize, newItem))
					std::cout << "Item added successfully.\n";
				break;
			}

			case 3:
			{
				if (inventorySize == 0)
				{
					std::cout << "\nInventory is empty.\n";
					break;
				}

				std::string searchName = getValidatedString("Enter item name to search: ");
				int index = checkItemInInventory(inventory, inventorySize, searchName);

				if (index != -1)
				{
					std::cout << "\nFound: "
							  << inventory[index].getDescription()
							  << " | Stock: " << inventory[index].getUnitsOnHand()
							  << " | Price: $" << inventory[index].getPrice()
							  << " | Reorder At: " << inventory[index].getReorderQuantity()
							  << "\n";
				}
				else
				{
					std::cout << "Item not found.\n";
				}
				break;
			}

			case 4:
				displayItemsToReorder(inventory, inventorySize);
				break;

			case 5:
			{
				if (inventorySize == 0)
				{
					std::cout << "\nInventory is empty.\n";
					break;
				}

				std::string updateName = getValidatedString("Enter item name to update: ");

				if (!updateItemInInventory(inventory, inventorySize, updateName))
					std::cout << "Update failed, cancelled, or item not found.\n";
				else
					std::cout << "Item updated successfully.\n";

				break;
			}

			default:
				std::cout << "Invalid choice. Try again.\n";
				break;
		}
	}
}

int main()
{
	RetailItem inventory[MAX_INVENTORY];
	int inventorySize = 0;

	// RetailItem testItem1("Apple");
	// RetailItem testItem2("Bed", 3);
	// RetailItem testItem3("Car", 2, 10);

	// addInventoryItem(inventory, inventorySize, testItem1);
	// addInventoryItem(inventory, inventorySize, testItem2);
	// addInventoryItem(inventory, inventorySize, testItem3);

	menu(inventory, inventorySize);

	return 0;
}
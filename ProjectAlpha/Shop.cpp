#include "stdafx.h"
#include "Shop.h"


Shop::Shop()
{
}

//Function that takes in the type/name of the store, the ID of all the items it sells, and the list of item info
void Shop::shopGUI(std::string store_type, int *stock, Item *item_info)
{
	int size = sizeof(stock);
	int counter = 0;
	int item_id = 0;

	system("CLS");
	std::cout << "-------------------------------\n";
	std::cout << "Welcome to " << store_type << "\n";
	std::cout << "-------------------------------\n";

	do
	{
		item_id = stock[counter];
		std::cout << "| " << counter + 1 << ". " << std::left << std::setw(12) << item_info[item_id].name << ": "
			<< std::left << std::setw(20) << item_info[item_id].description << " |\n";
		counter++;
	} while (counter < size);
}


Shop::~Shop()
{
}

#include "stdafx.h"
#include "Shop.h"


Shop::Shop()
{
}

//Function that takes in the type/name of the store, the ID of all the items it sells, and the list of item info
void Shop::weaponShopGUI(std::string store_type, int *stock, Weapon *item_info)
{
	int size = 2;
	int counter = 0;
	int item_id = 0;
	store_inventory = stock;

	counter = 0;
	do
	{
		system("CLS");
		std::cout << "-------------------------------\n";
		std::cout << "Welcome to " << store_type << "\n";
		std::cout << "-------------------------------\n";

		item_id = store_inventory[counter];
		std::cout << "| " << counter + 1 << ". " << std::left << std::setw(12) << item_info[item_id].name << " "
			<< "Cost: " << std::left << std::setw(3) << item_info[item_id].cost << " |\n";
		counter++;
	} while (counter < size);
}

void Shop::purchaseWeapon(int selection)
{

}

Shop::~Shop()
{
}

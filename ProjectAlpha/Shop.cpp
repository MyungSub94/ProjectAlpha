#include "stdafx.h"
#include "Shop.h"


Shop::Shop()
{
}

//Function that takes in the type/name of the store, the ID of all the items it sells, and the list of item info
void Shop::shopGUI(std::string store_type, int *stock, Item *item_info)
{
	int size = sizeof(stock);

	system("CLS");
	std::cout << "-------------------------------\n";
	std::cout << "Welcome to " << store_type << "\n";
	std::cout << "-------------------------------\n";

	do
	{

	}while()
}


Shop::~Shop()
{
}

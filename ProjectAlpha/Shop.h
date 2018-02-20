#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#include "Item.h"

class Shop
{
public:
	Shop();
	
	void shopGUI(std::string store_type, int *stock, Item *item_info);				//Builds GUI for shops

	virtual ~Shop();
};


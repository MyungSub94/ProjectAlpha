#pragma once
#include <iostream>
#include <iomanip>
#include <string>

#include "Weapon.h"

class Shop
{
public:
	Shop();
	
	void weaponShopGUI(std::string store_type, int *stock, Weapon *item_info);				//Builds GUI for shops
	void purchaseWeapon(int selection);						//Function that actually purchases the weapon the player wants
	Item *item_list = new Item[10];
	int *store_inventory = new int[10];

	virtual ~Shop();
};


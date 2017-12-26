#pragma once
#include "Item.h"
#include <string>

class Armor:public Item
{
public:
	Armor();

	int id;				//Id value for armor items
	int modifier;		//Modifier for things like affinity or specific resistances
	int phys_value;		//Value that reduces physical damage
	int mag_value;		//Vaue that reduces magical damage

	Armor(std::string a_name, std::string descr, int a_id, int mod, int phys, int mag, int price);

	virtual ~Armor();
};


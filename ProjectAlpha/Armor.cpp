#include "stdafx.h"
#include "Armor.h"


Armor::Armor()
{
}


Armor::Armor(std::string a_name, std::string descr, int a_id, int mod, int phys, int mag, int price)
{
	name = a_name;
	description = descr;
	id = a_id;
	modifier = mod;
	phys_value = phys;
	mag_value = mag;
	cost = price;
}

Armor::~Armor()
{
}

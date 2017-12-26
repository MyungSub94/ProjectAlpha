#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::Weapon(std::string w_name, std::string descr, int w_id, int base, int mod, int price)
{
	name = w_name;
	description = descr;
	id = w_id;
	base_damage = base;
	modifiers = mod;
	cost = price;
}

Weapon::~Weapon()
{
}

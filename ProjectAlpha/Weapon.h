#pragma once
#include "Item.h"

class Weapon:public Item
{
public:
	Weapon();

	int base_damage;			//Damage the weapon adds to the player/monster
	int modifiers;				//Gives weapons special properties(weapon affinity, bonus crit) A TODO FOR FUTURE IMPLEMENTATION

	Weapon(std::string w_name, std::string descr, int w_id, int base, int mod, int price);

	virtual ~Weapon();
};


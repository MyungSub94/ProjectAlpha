#pragma once
#include <string.h>
#include "Actor.h"
#include "Spell.h"

class PlayerActor:public Actor
{
public:
	PlayerActor();

	int health;
	int mana;
	int* spell_list = new int[10];
	equipment equip;

	//Creator for the player character
	PlayerActor(std::string p_name, int p_health, int p_mana, stats p_stats, equipment p_equipment);

	~PlayerActor();
};


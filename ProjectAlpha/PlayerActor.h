#pragma once
#include <string.h>
#include "Actor.h"
#include "Spell.h"

class PlayerActor:protected Actor
{
public:
	PlayerActor();


	int exp;		//Experience character has
	int health;		//Health of character
	int mana;		//Mana of character
	
	std::string getName();

	//Creator for the player character
	PlayerActor(std::string p_name, int lvl, int p_health, int p_mana, stats p_stats, equipment p_equipment, int *spells);
	void displayPlayerStats();
	void playerLevelUp();

	~PlayerActor();

private:
	int max_health;				//Max health player has
	int max_mana;				//Max mana player has
	equipment equip;			//Equipment the player has
	int level;					//Level of character
	int* spell_list = new int[10];			//Stores the list of integers that map to the proper spell in the master spell list
};


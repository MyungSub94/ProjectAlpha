#pragma once
#include "Actor.h"

#include <string.h>

class EnemyActor:public Actor
{
public:
	EnemyActor();

	int id;					//The ID of the enemy that will appear. Find way to implement groups of enemies
	int* spell_list =  new int[5];	//Holds list of spell ids for enemy units (could also contain 0 mana attacks for flavor)
	int exp;				//How much exp an enemy gives
	int gold;				//How much gold an enemy gives
	int health;				//Enemy health used in combat
	int mana;				//Enemy mana pool used in combat
	stats c_stats;			//Temp stats that can be altered. Used for damage calculations in combat
	int getMaxHealth();				//Outputs maximum health of enemy
	int getMaxMana();				//Ouputs maximum mana of enemy
	
	std::string getEName();			//Outputs the name of the enemy

	EnemyActor(std::string e_name, int e_id, int hp, int mp, stats e_stat, int *e_spell_list, int experience, int given_gold);

	virtual ~EnemyActor();

private:

	int max_health;
	int max_mana;
};


#pragma once
#include "Actor.h"

#include <string.h>

class EnemyActor:public Actor
{
public:
	EnemyActor();

	int id;					//The ID of the enemy that will appear. Find way to implement groups of enemies
	int* spell_list =  new int[5];	//Holds list of spell ids for enemy units (could also contain 0 mana attacks for flavor)
	int exp;
	int health;
	int mana;
	stats c_stats;
	int getMaxHealth();
	int getMaxMana();

	std::string getEName();

	EnemyActor(std::string e_name, int e_id, int hp, int mp, stats e_stat, int *e_spell_list, int experience);

	virtual ~EnemyActor();

private:

	int max_health;
	int max_mana;
};


#pragma once
#include "Actor.h"

#include <string>

class EnemyActor:public Actor
{
public:
	EnemyActor();

	int id;					//The ID of the enemy that will appear. Find way to implement groups of enemies
	int* spell_list =  new int[5];	//Holds list of spell ids for enemy units (could also contain 0 mana attacks for flavor)
	int exp;

	EnemyActor(std::string e_name, int e_id, stats e_stat, int *e_spell_list, int experience);

	virtual ~EnemyActor();
};


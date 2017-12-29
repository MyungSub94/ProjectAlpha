#pragma once
#include "Actor.h"

#include <string>

class EnemyActor:public Actor
{
public:
	EnemyActor();

	int id;					//The ID of the enemy that will appear. Find way to implement groups of enemies
	int* spell_list =  new int[5];	//Holds list of spell ids for enemy units (could also contain 0 mana attacks for flavor)

	//Really figure out how to make groups since I'm making them all be individual objects
	//Create a EnemyPod class which can hold an array of enemies. Use EnemyPod to fight and EnemyActor
	//to populate the actual data needed for combat
	EnemyActor(std::string e_name, int e_id, stats e_stat, int *e_spell_list);

	virtual ~EnemyActor();
};


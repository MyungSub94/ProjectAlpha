#pragma once
#include <string>
#include "Weapon.h"
#include "Armor.h"

struct ACTOR_STATS				//Stats for PlayerActors and EnemyActor
{
	int strength;				//Determines physical spell damage and basic attack damage
	int proficiency;			//Determine crit chance, hit rate, and dodge(?)
	int aptitude;				//Determines all magic damage stuff. Hit rate(?) and damage
	int constitution;			//Determines health/defense.
	int fortitude;				//Determines magica defense and immunity to status effects(?). May remove this stat
};
typedef struct ACTOR_STATS stats;

struct ACTOR_EQUIPMENT
{
	Weapon weapon;
	Armor armor;
	Item inventory[15];					//Holds 15 items. TODO Find way to replace/move around items in inventory
};
typedef struct ACTOR_EQUIPMENT equipment;

class Actor
{
public:
	Actor();

	std::string getName();

	virtual ~Actor();

protected:						//Pass to both player and enemy characters
	std::string name;				//Holds name of actor
	stats stat;						//Holds stats of actor
};


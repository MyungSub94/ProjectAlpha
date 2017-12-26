#pragma once
#include <string>

struct ACTOR_STATS				//Stats for PlayerActors and EnemyActor
{
	int strength;				//Determines physical spell damage and basic attack damage
	int proficiency;			//Determine crit change, hit rate, and dodge(?)
	int aptitude;				//Determines all magic damage stuff. Hit rate(?) and damage
	int constitution;			//Determines health/defense.
	int fortitude;				//Determines magica defense and immunity to status effects(?). May remove this stat
};
typedef struct ACTOR_STATS stats;

class Actor
{
public:
	Actor();

	std::string name;
	stats stat;
	
	virtual ~Actor();
};


#pragma once
#include "Actor.h"
#include "Spell.h"

class PlayerActor:public Actor
{
public:
	PlayerActor();

	stats playerStats;
	int* spell_list = new int[10];

	~PlayerActor();
};


#pragma once

#include <string.h>
#include <iostream>
#include <iomanip>

//Class that will handle the player being the town
//Will allow access to stores, talking to NPC, and going out to the dungeon
class Town
{
public:
	Town();

	void townGUI();					//Give option for players to take in the down

	virtual ~Town();
};


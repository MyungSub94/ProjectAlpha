#pragma once

#ifndef TOWN_H
#define TOWN_H

#include <string.h>
#include <iostream>
#include <iomanip>

#include "GAME_INFO.h"							//Inherits all the game information from this class
#include "Shop.h"								//Import object to create shops in the town
#include "BattleSequence.h"						//TEMP FOR TESTING TOWN THIS WILL BE IN A DUNGEON CLASS SOON

//Class that will handle the player being the town
//Will allow access to stores, talking to NPC, and going out to the dungeon
//Inherits from GAME_INFO to get global arrays of all the game information
//This also allows it to feedback into the core gameloop of adjusting values per encounter
class Town:public GAME_INFO
{
public:
	Town();
	Town(int id);

	Shop store;

	void townGUI();					//Give option for players to take in the down

	virtual ~Town();

private:
	//Holds the master list of all items/monster/spells in the game
	Item *items;	
	Weapon *weapons = new Weapon[2];
	Armor *armors;
	EnemyActor *enemy_list = new EnemyActor[4];
	EnemyPod *pod_list = new EnemyPod[3];
	Spell *spell_list = new Spell[10];

	BattleSequence battles;			//TEMP CALL TO TEST IF THE SYSTEM IMPORT INTO THE GAMEINFO/TOWN SYSTEM WORKS
	PlayerActor player;				//Holds player information when in town
	int town_id;					//Holds ID of town. Not needed for this game but good to carry around in case I revist this
};


#endif // !TOWN_H
#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "PlayerActor.h"				//Class for player character
#include "EnemyPod.h"					//Class that contains a single or group of enemies that player will fight
#include "BattleSequence.h"				//Class that handles the combat

/*
This class will handle all the information that the program will need.
Imported directly from the old ProjectAlpha.cpp
Passes directly to the Town class along with the core gameloop
It also will update accordingly to whatever situation the town is in
(this probably means I'll have to pass something else to this. Reminder to build another class to handle game systems/formulas in the background
*/

class GAME_INFO
{
public:
	GAME_INFO();
	GAME_INFO(int func);

	~GAME_INFO();

	PlayerActor player;										//Holds the player
	EnemyActor *ENEMY_LIST = new EnemyActor[4];				//Create array to hold enemies in 
	EnemyPod *POD_LIST = new EnemyPod[3];					//Creates the pods that the enemies can occur in
	Item *ITEM_LIST = new Item[10];							//Create array to hold all item information
	Spell *SPELL_LIST = new Spell[10];						//Create array to hold all spell information
	Armor *ARMOR_LIST = new Armor[2];						//Create array to hold all armor information
	Weapon *WEAPON_LIST = new Weapon[4];					//Create array to hold all weapon information

protected:
	void buildPlayer(PlayerActor &character);					//Builds player
	void buildEnemies(EnemyActor *enemy_list);					//Builds list of enemies
	void buildPod(EnemyPod *pod_list, EnemyActor *enemy_list);			//Builds the groups that enemies come in
	void buildSpells(Spell *spell_list);								//Builds all the spells for the game
	void buildWeapons(Weapon *weapon_list);								//Builds weapons for the game
};


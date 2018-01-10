// ProjectAlpha.cpp : Defines the entry point for the console application.
//Test commit

#include "stdafx.h"
#include <array>			//To get size of array
#include <string.h>
#include <stdlib.h>
#include <iostream>

#include "PlayerActor.h"				//Class for player character
#include "EnemyPod.h"					//Class that contains a single or group of enemies that player will fight
#include "BattleSequence.h"

void buildPlayer(PlayerActor &character);
void buildEnemies(EnemyActor *enemy_list);
void buildPod(EnemyPod *pod_list, EnemyActor *enemy_list);


int main()
{
	PlayerActor player;
	EnemyActor *ENEMY_LIST = new EnemyActor[4];				//Create array to hold enemies in
	EnemyPod *POD_LIST = new EnemyPod[3];
	
	buildPlayer(player);
	buildEnemies(ENEMY_LIST);
	buildPod(POD_LIST, ENEMY_LIST);

	BattleSequence battle = BattleSequence(&player, POD_LIST[1], ENEMY_LIST);
	battle.runBattle();

	delete[] ENEMY_LIST;
	delete[] POD_LIST;

    return 0;
}

void buildPlayer(PlayerActor &character)
{
	stats player_stats = { 8, 8, 8, 8, 8 };
	equipment player_equipment;

	Armor player_armor;
	Weapon player_weapon;

	player_armor = Armor("Basic Armor", "First armor", 0, 0, 10, 10, 0);
	player_weapon = Weapon("Basic Weapon", "First weapon", 0, 7, 1, 0);

	player_equipment.armor = player_armor;
	player_equipment.weapon = player_weapon;

	int *spells_list = new int[15];
	spells_list = { 0 };

	character = PlayerActor("Player", 1, 100, 100, player_stats, player_equipment, spells_list);

	return;
}

void buildEnemies(EnemyActor *enemy_list)
{
	stats enemy_stat = { 1, 1, 1, 1, 1 };
	std::string enemy_name[4] = { "Slime", "Bee", "Wolf", "Bear" };
	int spell_list[5] = { 201, 201 , 202, 203, 204};
	int experience_given = 1;
	int health = 10;
	int mana = 0;

	//LOOPING FOR REAL BASIC STAT STUFF. LAZY TO IMPLEMENT ANYTHING FANCIER THAN THIS
	for (int i = 0; i < 4; i++)
	{
		enemy_list[i] = EnemyActor(enemy_name[i], i, health, mana, enemy_stat, spell_list, experience_given);
		enemy_stat.strength *= 2;
		enemy_stat.aptitude *= 2;
		enemy_stat.constitution *= 2;
		enemy_stat.fortitude *= 2;
		enemy_stat.proficiency *= 2;
		experience_given *= 2;
		health *= 2;
	}
}

void buildPod(EnemyPod *pod_list, EnemyActor *enemy_list)
{
	int *id_list = new int[3];
	int size = 0;

	id_list[0] = 0;
	id_list[1] = 0;
	id_list[2] = 0;
	size = 3;			//Manually set size
	pod_list[0] = EnemyPod(0, id_list, size);

	id_list = new int[3];
	id_list[0] = 1;
	id_list[1] = 0;
	id_list[2] = 2;
	pod_list[1] = EnemyPod(1, id_list, size);

	id_list = new int[3];
	id_list[0] = 0;
	id_list[1] = 3;
	id_list[2] = 0;
	pod_list[2] = EnemyPod(2, id_list, size);
}

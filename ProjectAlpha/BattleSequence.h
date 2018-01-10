#pragma once
#pragma warning(disable: 4996)
#include "PlayerActor.h"
#include "EnemyPod.h"

#include <string>			//For printing and reading strings
//#include <stdlib.h>	
#include <iostream>			//Cout/Cin stuff
#include <cstdlib>			//For random number generation
#include <ctime>			//To seed random number generator
#include <iomanip>			//Formatting cout
#include <Windows.h>		//For sleep function

//Class that will handle the battle sequences when they take place
//Creates a temporary object that takes in an enemy pod and player actor
//Randomly generate the pod from outside the battle and call into the battle
//Only borrow from old code. Build a much more streamlined system in how combat will occur
//Always find a way to return to the overworld/explore screen once battle is over
class BattleSequence
{
public:
	BattleSequence();

	//BattleSequence calls the player, the pod of enemies, and the array of EnemyActors that contain enemy information
	BattleSequence(PlayerActor *player_actor, EnemyPod enemy, EnemyActor *list);				//Determines who will be in battle
	void runBattle();						//Runs the battle sequence
	virtual ~BattleSequence();

private:
	PlayerActor *player;				//Receives a pointer to the player. Since its a pointer any changes will be permanent.
	EnemyPod pod;				//Will be filled with information of a specific enemy pod
	EnemyActor *enemy_list;			//Contains pointer to the array that holds all the information on the enemies
	EnemyActor *curr_enemies;				//Creates a list of EnemyActor to use in combat. Remove once battle is over

	int ATTACK_HIT = 85;			//Chance of a basic attack hitting
	int BASE_CRIT = 10;				//Chance of critting

	void buildEnemies();
	void informationScreen();				//Builds the basic info in a battle sequence
	void battleMenuGUI();					//Display GUI and control of options in battle
	int enemySelect();
	void playerAttack(int choice);					//Action for player attacking
	void enemyPhase();					//Function that determines enemy move
};


#pragma once
#pragma warning(disable: 4996)
#include "PlayerActor.h"
#include "EnemyPod.h"

#include <string>			//For printing and reading strings
#include <iostream>			//Cout/Cin stuff
#include <cstdlib>			//For random number generation
#include <ctime>			//To seed random number generator
#include <iomanip>			//Formatting cout
#include <Windows.h>		//For sleep function

//Class that will handle the battle sequences when they take place
//Creates a temporary object that takes in an enemy pod and player actor
//TODO add a system that allows for affinities and statuses. Work on after getting a working game
class BattleSequence
{
public:
	BattleSequence();

	//BattleSequence calls the player, the pod of enemies, and the array of EnemyActors that contain enemy information
	BattleSequence(PlayerActor *player_actor, EnemyPod enemy, EnemyActor *list, Spell *s_list);				//Determines who will be in battle
	EnemyPod pod;				//Will be filled with information of a specific enemy pod. Must be changeable so that random consecutive encounters are smoother
	void runBattle();						//Runs the battle sequence
	virtual ~BattleSequence();

private:
	PlayerActor *player;				//Receives a pointer to the player. Since its a pointer any changes will be permanent.

	EnemyActor *enemy_list;			//Contains pointer to the array that holds all the information on the enemies
	EnemyActor *curr_enemies;				//Creates a list of EnemyActor to use in combat. Remove once battle is over
	Spell *spell_list;						//Holds information on all the spells to use in battle

	int ATTACK_HIT = 85;			//Chance of a basic attack hitting
	int BASE_CRIT = 10;				//Chance of critting

	void buildEnemies();
	void informationScreen();				//Builds the basic info in a battle sequence
	void battleMenuGUI();					//Display GUI and control of options in battle
	int enemySelect();
	void playerAttack(int choice);					//Action for player attacking
	double damageVariance();						//Creates damage variance for spells and attacks
	int playerChooseSpell();						//Lets player choose a spell. Returns the spell index of the spell to cast
	int castSpell(int spell_id);					//Handles spell casts. Calls other functions to handle the math
	int physicalSpellcast(int spell_id);			//Casts for physical spells
	int magicalSpellcast(int spell_id);				//Casts for magical spell
	int healingSpellcast(int spell_id);				//Casts for healing spells
	void playerGuard();
	void enemyPhase();					//Function that determines enemy move
	void endPhase(bool &battle_flag);			//Function that handles all ending checks: reset combat stats if needed, check who won, if battle ends etc
};
#include "stdafx.h"
#include "BattleSequence.h"


BattleSequence::BattleSequence()
{
}

BattleSequence::BattleSequence(PlayerActor *player_actor, EnemyPod *enemy)
{
	player = player_actor;
	enemies = enemy;
}

void BattleSequence::runBattle()
{
	informationScreen();
	return;
}


BattleSequence::~BattleSequence()
{
}

void BattleSequence::informationScreen()
{
	int set_size = (*enemies).size;
	int counter = 0;

	printf("---------------------------------\n");

	std::cout << "| " << player->getName() << std::endl;

	/*
	while (counter < set_size)
	{
		printf(" | %s", enemies[counter].getName);
	}*/
}

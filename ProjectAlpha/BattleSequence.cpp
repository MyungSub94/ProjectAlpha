#include "stdafx.h"
#include "BattleSequence.h"


BattleSequence::BattleSequence()
{
}

BattleSequence::BattleSequence(PlayerActor *player_actor, EnemyPod enemy, EnemyActor *list)
{
	player = player_actor;
	pod = enemy;
	enemy_list = list;
}

void BattleSequence::runBattle()
{
	buildEnemies();
	battleMenuGUI();
	return;
}

void BattleSequence::buildEnemies()
{
	int size = pod.set_size;
	int counter = 0;

	curr_enemies = new EnemyActor[size + 1];		//Build array of how big the pod is

	while (counter < size)
	{
		//Create a new enemy that copies the values from the pod
		curr_enemies[counter] = EnemyActor(enemy_list[pod.set_id[counter]].getEName(),
			enemy_list[pod.set_id[counter]].id,
			enemy_list[pod.set_id[counter]].getMaxHealth(),
			enemy_list[pod.set_id[counter]].getMaxMana(),
			enemy_list[pod.set_id[counter]].c_stats,
			enemy_list[pod.set_id[counter]].spell_list,
			enemy_list[pod.set_id[counter]].exp);

		counter++;
	}

	return;
}

void BattleSequence::informationScreen()
{
	int size = pod.set_size;
	int counter = 0;

	printf("---------------------------------------------------------\n");

	std::cout << "| " << std::setw(11) << player->getName();

	//Loops through all the enemies. Converts string into a char array and ouputs them
	while (counter < size)
	{
		std::cout << " | " << std::setw(11) << curr_enemies[counter].getEName();
		counter++;
	}

	printf(" |\n");
	printf("| HP: %3d/%3d", player->health, player->getMaxHealth());
	counter = 0;
	while (counter < size)
	{
		printf(" | HP: %3d/%3d", curr_enemies[counter].health, curr_enemies[counter].getMaxHealth());
		counter++;
	}

	printf(" |\n");
	printf("| MP: %3d/%3d", player->mana, player->getMaxMana());
	counter = 0;
	while (counter < size)
	{
		printf(" | MP: %3d/%3d", curr_enemies[counter].mana, curr_enemies[counter].getMaxMana());
		counter++;
	}
	printf(" |\n");
	printf("---------------------------------------------------------\n");

	return;
}

void BattleSequence::battleMenuGUI()
{
	int selection = 0;
	int enemy_choice = 0;

	do
	{
		informationScreen();
		printf("| %-9s |\n| %-9s |\n| %-9s |\n| %-9s |\n| %-9s |\n", "1.Attack", "2.Items", "3.Spells", "4.Defend", "5.Escape");
		std::cin >> selection;

		switch (selection)
		{
		case 1:					//Creating a basic attack
			enemy_choice = enemySelect();
			playerAttack(enemy_choice);
			break;
		case 5:					//Running from combat
			selection = 6;
			std::cout << "You succesfully escaped!\n";
			Sleep(1900);
			return;
		default:				//Default is a fail case even if input is a number
			std::cin.clear();				//Sanitize the input then continue looping
			std::cin.ignore(1);
			break;
		}

		system("CLS");
	} while (std::cin.fail() || selection > 5 || selection < 1);

	enemyPhase();

	return;
}

int BattleSequence::enemySelect()
{
	int size = pod.set_size;
	int counter = 0;
	int selection = 0;

	system("CLS");
	informationScreen();

	printf("Choose an enemy\n");
	while (counter < size)
	{
		std::cout << "| "  << counter + 1 << ". " << std::left << std::setw(11) << curr_enemies[counter].getEName() << " |\n";
		counter++;
	}

	std::cin >> selection;

	if (curr_enemies[counter].health == 0)
	{

	}

	return selection;
}

void BattleSequence::playerAttack(int choice)
{
	int damage_roll = 0;
	int hit_chance = 0;
	int random_hit = 0;				//Random modifier to check if a hit lands
	double variance = 0;			//Adds variance to the attack rolls

	system("CLS");
	informationScreen();


	srand(time(NULL));
	random_hit = rand();
	hit_chance = ((player->c_stats.proficiency / 2) + random_hit);

	choice--;			//Decrement choice to get index of the enemy

	if (hit_chance > (ATTACK_HIT - (enemy_list[pod.set_id[choice]].c_stats.proficiency / 2)))
	{
		damage_roll = (player->c_stats.strength + (player->c_stats.proficiency / 2) + player->equip.weapon.base_damage);
		damage_roll = damage_roll - enemy_list[pod.set_id[choice]].c_stats.constitution;

		variance = rand() % 6;
		variance = (variance / 10) + 0.5;
		damage_roll = damage_roll * variance;

		std::cout << "Hit " << enemy_list[pod.set_id[choice]].getEName() << " for " << damage_roll << " damage!\n";

		enemy_list[pod.set_id[choice]].health -= damage_roll;
		Sleep(1850);
	}
	else
	{
		printf("Attack missed!\n");
		Sleep(1850);
	}

	return;
}

void BattleSequence::enemyPhase()
{
	//TODO make a basic AI system for enemies. If have difficulty, make hardest difficulty calculate all damage and use highest one

	int damage_roll = 0;
	int size = pod.set_size;
	int counter = 0;
	
	do
	{
		std::cout << curr_enemies[counter].getEName() << " strikes for " << damage_roll << " damage!\n";
		Sleep(1500);
		counter++;
	}while(counter < size);
}

BattleSequence::~BattleSequence()
{
}

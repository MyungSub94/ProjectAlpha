#include "stdafx.h"
#include "BattleSequence.h"


BattleSequence::BattleSequence()
{
}

BattleSequence::BattleSequence(PlayerActor *player_actor, EnemyPod enemy, EnemyActor *list, Spell *s_list)
{
	player = player_actor;
	pod = enemy;
	enemy_list = list;
	spell_list = s_list;
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
	bool battle_flag = true;

	do				//Loops through the battle until the enemy is defeated or player is defeated
	{
		do				//Loops through player choice and loops until a functional button is pressed
		{
			system("CLS");
			informationScreen();
			printf("| %-9s |\n| %-9s |\n| %-9s |\n| %-9s |\n| %-9s |\n", "1.Attack", "2.Items", "3.Spells", "4.Defend", "5.Escape");
			std::cin >> selection;

			switch (selection)
			{
			case 1:					//Creating a basic attack
				enemy_choice = enemySelect();
				playerAttack(enemy_choice);
				break;
			case 2:

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
		endPhase(battle_flag);
	} while (battle_flag);
	return;
}

int BattleSequence::enemySelect()
{
	int size = pod.set_size;
	int counter = 0;
	int selection = 0;

	do
	{	
		system("CLS");
		informationScreen();

		printf("Choose an enemy\n");
		while (counter < size)
		{
			std::cout << "| "  << counter + 1 << ". " << std::left << std::setw(11) << curr_enemies[counter].getEName() << " |\n";
			counter++;
		}

		std::cin >> selection;
		if (curr_enemies[selection - 1].health == 0)			//Case if unit is dead
		{
			std::cout << "That unit is dead\n";
			Sleep(1500);
			selection = 0;
			counter = 0;
		}

	} while (std::cin.fail() || selection > size || selection < 1);

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
	random_hit = rand() % 100;
	hit_chance = ((player->c_stats.proficiency / 2) + random_hit);

	choice--;			//Decrement choice to get index of the enemy

	if (hit_chance < (ATTACK_HIT - (curr_enemies[choice].c_stats.proficiency / 2)))
	{
		damage_roll = (player->c_stats.strength + (player->c_stats.proficiency / 2) + player->equip.weapon.base_damage);
		damage_roll = damage_roll - curr_enemies[choice].c_stats.constitution;

		//Set variance so that attacks can hit from .7 - 1.2
		variance = (rand() % 6) + 1;
		variance = (variance / 10) + 0.6;
		damage_roll = damage_roll * variance;			//Calculate final damage

		std::cout << "Hit " << curr_enemies[choice].getEName() << " for " << damage_roll << " damage!\n";

		curr_enemies[choice].health -= damage_roll;
		if (curr_enemies[choice].health < 0)
		{
			curr_enemies[choice].health = 0;
		}
		Sleep(1850);
	}
	else
	{
		printf("Attack missed!\n");
		Sleep(1850);
	}

	return;
}

int BattleSequence::playerChooseSpell()
{
	int choice = 0;
	int num_spells = 0;			//Holds how many spells the player has. For sake of sanitizing bad inputs
	int counter = 0;
	int spell_index = 0;

	system("CLS");
	informationScreen();

	do
	{
		spell_index = player->spell_book[counter];
		std::cout << counter + 1 << ". " << spell_list[spell_index].name;
		counter++;
	} while ((player->spell_book[counter + 1] != 0) || (counter < spell_list->MAX_PLAYER_SPELL));				//Break if the next spell is 

	return choice;
}

void BattleSequence::enemyPhase()
{
	//TODO make a basic AI system for enemies
	//If there is difficulty, make hardest difficulty calculate all damage and use highest one

	int rand_hit = 0;
	int hit_chance = 0;
	int damage_roll = 0;
	int size = pod.set_size;
	int counter = 0;
	double hit_variance = 0;

	system("CLS");
	informationScreen();
	srand(time(NULL));

	do
	{
		if (curr_enemies[counter].health > 0)			//Check to see if enemy is alive
		{
			rand_hit = rand() % 100;				//Roll for hit chance
			hit_chance = (curr_enemies[counter].c_stats.proficiency / 2) + rand_hit;			//Calculate hit hance

			if (hit_chance < (ATTACK_HIT - (player->c_stats.proficiency / 2)))			//Check if it hits
			{
				hit_variance = (rand() % 6) + 1;
				hit_variance = (hit_variance / 10) + 0.6;			//Set a attack variance from .7 - 1.2

				//Temporary holder modifier for enemies to do damage while I figure out their attack system
				damage_roll = ((curr_enemies[counter].c_stats.strength * 5) + (curr_enemies[counter].c_stats.proficiency * 2))
					- (player->c_stats.constitution + player->equip.armor.phys_value);
				damage_roll = damage_roll * hit_variance;

				if (damage_roll < 1)				//Case if enemies do no damage
				{
					std::cout << curr_enemies[counter].getEName() << " dealt no damage! \n";
				}
				else
				{
					player->health = player->health - damage_roll;
					std::cout << curr_enemies[counter].getEName() << " strikes for " << damage_roll << " damage!\n";
				}

				Sleep(1500);
			}
			else				//Attack misses
			{
				std::cout << curr_enemies[counter].getEName() << " missed!\n";

				Sleep(1500);
			}
		}

		counter++;
	}while(counter < size);
}

void BattleSequence::endPhase(bool &battle_flag)
{
	int counter = 0;
	int size = pod.set_size;
	int death_counter = 0;
	int experience = 0;

	//Checking for dead enemies. Then set their health to 0
	while (counter < size)
	{
		if (!(curr_enemies[counter].health > 0))
		{
			death_counter++;
		}

		counter++;
	}

	if (death_counter == size)
	{
		std::cout << "The battle is won!\n";
		std::cout << "You earned " << pod.gold << " gold!\n";
		player->gold += pod.gold;
		std::cout << "You earned " << pod.experience << " exp!\n";
		player->exp += pod.experience;

		Sleep(1800);

		battle_flag = false;
	}

	return;
}

BattleSequence::~BattleSequence()
{
}

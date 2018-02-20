#include "stdafx.h"
#include "town.h"



Town::Town()
{

}

//Create a town object that will take in all item/weapon/armor information
Town::Town(int id)
{
	//Importing all the game data into the town
	buildWeapons(weapons);
	buildEnemies(enemy_list);
	buildPod(pod_list, enemy_list);
	buildPlayer(player);
	buildSpells(spell_list);
	town_id = id;						//Set id of the town
}

//Builds the GUI of the town that lets the player navigate to the various parts of the town
void Town::townGUI()
{
	int selection = 0;
	int *list = new int[2];
	list[0] = 0;
	list[1] = 1;

	do
	{
		system("CLS");
		std::cout << "---------------------------\n";
		std::cout << "| 1. " << std::left << std::setw(20) << "go to dungeon" << " |\n";
		std::cout << "| 2. " << std::left << std::setw(20) << "visit item shop" << " |\n";
		std::cout << "| 3. " << std::left << std::setw(20) << "visit weapon shop" << " |\n";
		std::cout << "| 4. " << std::left << std::setw(20) << "visit armor shop" << " |\n";
		std::cout << "| 5. " << std::left << std::setw(20) << "visit inn" << " |\n";
		std::cout << "---------------------------\n";

		std::cin >> selection;
		switch (selection)
		{
		case 1:						//Sends player to the dungeon. TEST CASE SENDS RIGHT TO A BATTLE
			battles = BattleSequence(&player, pod_list[0], enemy_list, spell_list);
			battles.runBattle();
			battles = BattleSequence(&player, pod_list[1], enemy_list, spell_list);
			battles.runBattle();
			return;
		case 3:
			store.shopGUI("Weapon Store", list, weapons);
			break;
		default:
			break;
		}
	} while (std::cin.fail() || selection > 5 || selection < 1);

}


Town::~Town()
{
}

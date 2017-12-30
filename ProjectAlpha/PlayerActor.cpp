#include "stdafx.h"
#include "PlayerActor.h"
#include <iostream>
#include <stdlib.h>


PlayerActor::PlayerActor()
{
}

//Constructor call to build a player character
PlayerActor::PlayerActor(std::string p_name, int lvl, int p_health, int p_mana, stats p_stats, equipment p_equipment, int *spells)
{
	name = p_name;
	level = lvl;
	exp = 0;
	stat = p_stats;
	health = p_health;
	mana = p_mana;
	equip = p_equipment;
	spell_list = spells;
}

//Displays all the stats of the player character
void PlayerActor::displayPlayerStats()
{
	std::cout << "1. Strength: " << stat.strength << std::endl;
	std::cout << "2. Proficiency: " << stat.proficiency << std::endl;
	std::cout << "3. Aptitude: " << stat.aptitude << std::endl;
	std::cout << "4. Constitution: " << stat.constitution << std::endl;
	std::cout << "5. Fortitude: " << stat.fortitude << std::endl;

	return;
}

void PlayerActor::playerLevelUp()
{
	level++;
	std::cout << name << "leveled up to " << level << "!\n";

	int stat_points = 4;			//Give 4 stats to use up
	int selection = 0;
	char confirm_select = ' ';
	bool confirm_points = false;
	stats prev_stats = stat;			//Holds the previous stats for if the player wants to reset

	do
	{
		//GUI for leveling up the player character
		std::cout << stat_points << "/4 points left" << std::endl;
		displayPlayerStats();

		std::cin >> selection;

		//Switch statement that controls which stats will increase
		switch (selection)
		{
		case 1: stat.strength++;
			stat_points--;
			break;
		case 2: stat.proficiency++;
			stat_points--;
			break;
		case 3: stat.aptitude++;
			stat_points--;
			break;
		case 4: stat.constitution++;
			stat_points--;
			break;
		case 5: stat.fortitude;
			stat_points--;
			break;
		default: std::cin.clear();
			std::cin.ignore(1);
			break;
		}
		system("CLS");

		//Get confirmation to keep stats or not
		if (stat_points == 0)
		{
			displayPlayerStats();
			std::cout << std::endl << "Are these the stats you want? (Y for yes  N for no)" << std::endl;
			std::cin >> confirm_select;
			confirm_select = toupper(confirm_select);

			if (confirm_select == 'Y')
			{
				confirm_points = true;
			}
			else
			{
				stat_points = 4;
				stat = prev_stats;
				confirm_points = false;
			}

			system("CLS");
		}

	//Continue loop if: Stat points left, player has not confirmed points, selection too large, selection too small, or invalid selection
	} while (stat_points > 0 || !confirm_points || selection > 5 || selection < 1 || std::cin.fail());

	return;
}

PlayerActor::~PlayerActor()
{

}

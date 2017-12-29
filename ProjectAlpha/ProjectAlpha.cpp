// ProjectAlpha.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <string.h>
#include "Actor.h"
#include "PlayerActor.h"
#include "Item.h"

void buildPlayer(Actor &character);


int main()
{
    return 0;
}

void buildPlayer(Actor &character)
{
	stats player_stats = { 10, 10, 10, 10, 10 };
	equipment player_equipment;

	Armor player_armor;
	Weapon player_weapon;

	player_armor = Armor("Basic Armor", "First armor", 0, 0, 15, 15, 0);
	player_weapon = Weapon("Basic Weapon", "First weapon", 0, 10, 1, 0);

	player_equipment.armor = player_armor;
	player_equipment.weapon = player_weapon;

	character = PlayerActor("Player", 100, 100, player_stats, player_equipment);

	return;
}


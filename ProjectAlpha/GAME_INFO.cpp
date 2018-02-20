#include "stdafx.h"
#include "GAME_INFO.h"

GAME_INFO::GAME_INFO()
{

}

GAME_INFO::GAME_INFO(int func)
{
	buildPlayer(player);
	buildEnemies(ENEMY_LIST);
	buildPod(POD_LIST, ENEMY_LIST);
	buildSpells(SPELL_LIST);
	buildWeapons(WEAPON_LIST);
}


GAME_INFO::~GAME_INFO()
{
}

//Function call to build the player character
//Take in user input for final build
void GAME_INFO::buildPlayer(PlayerActor &character)
{
	stats player_stats = { 8, 8, 8, 8, 8 };
	equipment player_equipment;

	Armor player_armor;
	Weapon player_weapon;

	player_armor = Armor("Basic Armor", "First armor", 0, 0, 5, 5, 0);
	player_weapon = Weapon("Basic Weapon", "First weapon", 0, 7, 1, 0);

	player_equipment.armor = player_armor;
	player_equipment.weapon = player_weapon;

	int *spells_list = new int[10];
	spells_list[0] = 1;
	spells_list[1] = 2;
	spells_list[2] = 4;
	spells_list[3] = 5;
	spells_list[4] = 7;
	for (int i = 5; i < 10; i++)
	{
		spells_list[i] = 0;
	}

	character = PlayerActor("Player", 1, 100, 100, player_stats, player_equipment, spells_list);

	return;
}

//Builds list of enemies
//Make a more interesting system but realistically I'm only have 6-8 monsters
void GAME_INFO::buildEnemies(EnemyActor *enemy_list)
{
	stats enemy_stat = { 1, 1, 1, 1, 1 };
	std::string enemy_name[4] = { "Slime", "Bee", "Wolf", "Bear" };
	int spell_list[5] = { 201, 201 , 202, 203, 204};
	int experience_given = 5;
	int health = 10;
	int mana = 0;
	int gold_given = 3;

	//LOOPING FOR REAL BASIC STAT STUFF. LAZY TO IMPLEMENT ANYTHING FANCIER THAN THIS
	for (int i = 0; i < 4; i++)
	{
		enemy_list[i] = EnemyActor(enemy_name[i], i, health, mana, enemy_stat, spell_list, experience_given, gold_given);
		enemy_stat.strength *= 2;
		enemy_stat.aptitude *= 2;
		enemy_stat.constitution *= 2;
		enemy_stat.fortitude *= 2;
		enemy_stat.proficiency *= 2;
		experience_given *= 2;
		health *= 2;
		gold_given *= 2;
	}
}

//Builds pods of enemies
//Each pod will have 1-3 enemies in them. This determines the groupings of each random encounter
void GAME_INFO::buildPod(EnemyPod *pod_list, EnemyActor *enemy_list)
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

//Function that builds all the spells in the game
//Make interesting spells but fully functional at the moment
void GAME_INFO::buildSpells(Spell *spell_list)
{
	spell_list[1] = Spell(1, "Fireball", "Does fire damage to 1 enemy", 0.5, 24, 10, false, MAGICAL);
	spell_list[2] = Spell(2, "Flamestrike", "Does fire damage to all enemies", 0.4, 18, 15, true, MAGICAL);
	spell_list[3] = Spell(3, "Dire Thunder", "THE REINHARDT", 2.0, 10, 20, false, MAGICAL);
	spell_list[4] = Spell(4, "Power Strike", "Deals one massive damage", 0.8, 10, 10, false, PHYSICAL);
	spell_list[5] = Spell(5, "Arcing Sweep", "Deal slight damage to all enemies", 0.5, 10, 15, true, PHYSICAL);
	spell_list[6] = Spell(6, "Burst Strike", "Deals massive damage to all foes", 0.8, 14, 85, true, PHYSICAL);
	spell_list[7] = Spell(7, "Lesser Heal", "Heals for a small bit of health", 0.5, 15, 10, false, HEAL);
}

//Build weapons to add into the game
//Add more interesting effects once game fully works
void GAME_INFO::buildWeapons(Weapon *weapon_list)
{
	weapon_list[0] = Weapon("Iron Dagger", "A very simple weapon. Low damage", 0, 5, 1, 10);
	weapon_list[1] = Weapon("Spear", "A heavy two handed weapon with long reach", 1, 15, 2, 50);
}

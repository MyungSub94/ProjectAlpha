#include "stdafx.h"
#include "EnemyActor.h"


EnemyActor::EnemyActor()
{
}


std::string EnemyActor::getEName()
{return name;}

//TODO test if this can pass arrays correctly. The pointer should hold the address to the memory that holds the array of spells
EnemyActor::EnemyActor(std::string e_name, int e_id, int hp, int mp, stats e_stat, int *e_spell_list, int experience, int given_gold)		
{
	name = e_name;
	id = e_id;
	health = hp;
	max_health = hp;
	mana = mp;
	max_mana = mp;
	stat = e_stat;
	c_stats = e_stat;
	spell_list = e_spell_list;
	exp = experience;
	gold = given_gold;
}

EnemyActor::~EnemyActor()
{
}

int EnemyActor::getMaxHealth()
{return max_health;}

int EnemyActor::getMaxMana()
{return max_mana;}

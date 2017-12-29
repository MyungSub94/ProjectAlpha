#include "stdafx.h"
#include "EnemyActor.h"


EnemyActor::EnemyActor()
{
}


//TODO test if this can pass arrays correctly. The pointer should hold the address to the memory that holds the array of spells
EnemyActor::EnemyActor(std::string e_name, int e_id, stats e_stat, int *e_spell_list)		
{
	name = e_name;
	id = e_id;
	stat = e_stat;
	spell_list = e_spell_list;
}

EnemyActor::~EnemyActor()
{
}

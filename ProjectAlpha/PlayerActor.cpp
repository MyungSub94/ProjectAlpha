#include "stdafx.h"
#include "PlayerActor.h"


PlayerActor::PlayerActor()
{
}


PlayerActor::PlayerActor(std::string p_name, int p_health, int p_mana, stats p_stats, equipment p_equipment)
{
	name = p_name;
	stat = p_stats;
	health = p_health;
	mana = p_mana;
	equip = p_equipment;
}

PlayerActor::~PlayerActor()
{
}

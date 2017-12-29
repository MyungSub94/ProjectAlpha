#include "stdafx.h"
#include "Spell.h"

Spell::Spell()
{
}

//Creates a spell with all the iformation needed
//Find a good-ish way to insert all spells in the game without having to hardcode every thing into the game
Spell::Spell(int id, std::string s_name, std::string descr, double mod, int base, int s_cost, spell_class sc)
{
	spell_id = id;
	name = s_name;
	description = descr;
	modifier = mod;
	base_damage = base;
	cost = s_cost;
	s_class = sc;
}

Spell::~Spell()
{
}

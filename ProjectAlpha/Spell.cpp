#include "stdafx.h"
#include "Spell.h"

Spell::Spell()
{
}


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

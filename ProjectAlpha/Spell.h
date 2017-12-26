#pragma once
#include <string>

enum type : int { PHYICAL = 0, MAGICAL = 0, HEAL = 2, UTILITY = 3 };		//Work on getting Utility spells to work
typedef enum type spell_class;

class Spell
{
public:
	Spell();

	int spell_id;			//Determines what the spell to cast will be
	std::string name;		//Name of spell
	std::string description;		//Description for the spell
	double modifier;				//Modifier for spell damage (adds to multiplier)
	int base_damage;				//Base damage (or buff) of a spell
	int cost;				//Mana cost of a spell
	spell_class s_class;				//The type of spell that this spell is

	Spell(int id, std::string s_name, std::string descr, double mod, int base, int s_cost, spell_class sc);
	//Spells will be cast from the actor class by selecting an index integer from the caster
	//That index will part of the cast spell function call to determine the effects
	//This may not work as intended and need more work later


	virtual ~Spell();
};


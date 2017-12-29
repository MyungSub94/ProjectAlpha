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
	//Spell ID will be stored in an array of ints stored in an actor class
	//It will contain an integer value that refers to a specific spell_id
	//All spells are stored in a premade set of spells each with a unique spell ID
	//Cast spell will have a switch statement that will determine the effect of the spell using s_class

	virtual ~Spell();
};


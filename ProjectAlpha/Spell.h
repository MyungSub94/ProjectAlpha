#pragma once
#include <string>

enum type : int { PHYSICAL = 0, MAGICAL = 1, HEAL = 2, UTILITY = 3 };		//Work on getting Utility spells to work
typedef enum type spell_class;

class Spell
{
public:
	Spell();

	int spell_id;			//Determines what the spell to cast will be. These are the ints stored in the actors' spell list
	std::string name;		//Name of spell
	std::string description;		//Description for the spell
	int cost;				//Mana cost of a spell
	bool aoe;				//Determines if the spell hits all or none
	spell_class s_class;				//The type of spell that this spell is

	int MAX_PLAYER_SPELL = 15;				//The maximum spells that a player has

	Spell(int id, std::string s_name, std::string descr, double mod, int base, int s_cost, bool area, spell_class sc);
	//Spells will be cast from the actor class by selecting an index integer from the caster
	//Spell ID will be stored in an array of ints stored in an actor class
	//It will contain an integer value that refers to a specific spell_id
	//All spells are stored in a premade set of spells each with a unique spell ID
	//Cast spell will have a switch statement that will determine the effect of the spell using s_class

	virtual ~Spell();

private:
	double modifier;				//Modifier for spell damage (adds to multiplier)
	int base_damage;				//Base damage (or buff) of a spell
};


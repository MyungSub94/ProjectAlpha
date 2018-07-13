#include "stdafx.h"
#include "BattleSequence.h"


BattleSequence::BattleSequence()
{
}

BattleSequence::BattleSequence(PlayerActor *player_actor, EnemyPod enemy, EnemyActor *list, Spell *s_list)
{
player = player_actor;
pod = enemy;
enemy_list = list;
spell_list = s_list;
srand(time(NULL));			//Seeding random number generator
}

void BattleSequence::runBattle()
{
buildEnemies();
battleMenuGUI();
return;
}

///-----------------------------------------------------------
/// Function that builds the enemies from a given list of ids from the pod info
///-----------------------------------------------------------
void BattleSequence::buildEnemies()
{
int size = pod.set_size;
int counter = 0;
int pod_id = 0;

curr_enemies = new EnemyActor[size + 1];		//Build array of how big the pod is

while (counter < size)
{
	//Create a new enemy that copies the values from the pod
	pod_id = pod.set_id[counter];
	curr_enemies[counter] = EnemyActor(enemy_list[pod_id].getEName(),
									   enemy_list[pod_id].id,
									   enemy_list[pod_id].getMaxHealth(),
									   enemy_list[pod_id].getMaxMana(),
									   enemy_list[pod_id].c_stats,
									   enemy_list[pod_id].spell_list,
									   enemy_list[pod_id].exp,
									   enemy_list[pod_id].gold);
	counter++;
}

return;
}

///-----------------------------------------------------------
/// Function that displays names, hp, mp of every actor in the battle
///-----------------------------------------------------------
void BattleSequence::informationScreen()
{
int size = pod.set_size;
int counter = 0;

printf("---------------------------------------------------------\n");

std::cout << "| " << std::setw(11) << player->getName();

//Loops through all the enemies and prints their names in order
while (counter < size)
{
	std::cout << " | " << std::setw(11) << curr_enemies[counter].getEName();
	counter++;
}

//Prints health values of player then all the corresponding monsters
printf(" |\n");
printf("| HP: %3d/%3d", player->health, player->getMaxHealth());
counter = 0;
while (counter < size)
{
	printf(" | HP: %3d/%3d", curr_enemies[counter].health, curr_enemies[counter].getMaxHealth());
	counter++;
}

//Prints mana of player then all the corresponding monsters
printf(" |\n");
printf("| MP: %3d/%3d", player->mana, player->getMaxMana());
counter = 0;
while (counter < size)
{
	printf(" | MP: %3d/%3d", curr_enemies[counter].mana, curr_enemies[counter].getMaxMana());
	counter++;
}
printf(" |\n");
printf("---------------------------------------------------------\n");

return;
}

///-----------------------------------------------------------
/// Builds the GUI player uses for battle
/// It also handles the functions that executes the differnt parts of battle
///-----------------------------------------------------------
void BattleSequence::battleMenuGUI()
{
int selection = 0;
int enemy_choice = 0;
int spell_choice = 0;
int spell_return = 0;
bool battle_flag = true;

do				//Loops through the battle until the enemy is defeated or player is defeated
{
	do				//Loops through player choice and loops until a functional button is pressed
	{
		system("CLS");
		informationScreen();
		printf("| %-9s |\n| %-9s |\n| %-9s |\n| %-9s |\n| %-9s |\n", "1.Attack", "2.Items", "3.Spells", "4.Defend", "5.Escape");
		std::cin >> selection;

		switch (selection)
		{
		case 1:					//Basic attack
			enemy_choice = enemySelect();
			if (enemy_choice > 0)				//To check if the player wants to return to a previous page
				playerAttack(enemy_choice);
			else
				selection = 0;						//Return from the selection
			break;
		case 3:					//Spell
			spell_choice = playerChooseSpell();
			if (spell_choice > 0)				//Return case from selecting a spell
				spell_return = castSpell(spell_choice);
				if (spell_return < 0)
					selection = 0;					//Return from selection
			else
				selection = 0;
			Sleep(1400);
			break;
		case 4:						//For raising guard. Doubles defensive stats, fortitude and consistution
			playerGuard();
			break;

		case 5:					//Running from combat. Send a false flag to end phase to get the proper amount of exp/gold
			selection = 6;				//To break the inner loop
			battle_flag = false;
			endPhase(battle_flag);
			Sleep(1800);
			return;
		default:				//Default is a fail case even if input is a number
			std::cin.clear();				//Sanitize the input then continue looping
			std::cin.ignore(1);
			break;
		}

		system("CLS");
	} while (std::cin.fail() || selection > 5 || selection < 1);

	enemyPhase();
	endPhase(battle_flag);
} while (battle_flag);
return;
}

///-----------------------------------------------------------
/// Builds a quick GUI of enemies.
/// Alert player if a target is untargetable. Nothing fancy to remove dead enemies YET
///-----------------------------------------------------------
int BattleSequence::enemySelect()
{
	int size = pod.set_size;
	int counter = 0;
	int selection = 0;

	do
	{	
		system("CLS");
		informationScreen();

		printf("Choose an enemy\n");
		while (counter < size)				//Loops to display enemies
		{
			std::cout << "| "  << counter + 1 << ". " << std::left << std::setw(11) << curr_enemies[counter].getEName() << " |\n";
			counter++;
		}
		std::cout << "| 0.  " << std::left << std::setw(11) << "Return" << "|\n";

		std::cin >> selection;
		if (selection == 0)				//If the player wants to return to the main menu
		{
			break;
		}
		if (curr_enemies[selection - 1].health == 0)			//Case if unit is dead
		{
			std::cout << "That unit is dead\n";
			Sleep(1500);
			selection = 0;
			counter = 0;
		}

	} while (std::cin.fail() || selection > size || selection < 1);

	selection--;
	return selection;
}

///-----------------------------------------------------------
/// Handles basic attack from player
/// Hits only one. TODO add a critical hit chance
///-----------------------------------------------------------
void BattleSequence::playerAttack(int choice)
{
	int damage_roll = 0;
	int hit_chance = 0;
	int random_hit = 0;				//Random modifier to check if a hit lands
	double variance = 0;			//Adds variance to the attack rolls

	system("CLS");
	informationScreen();

	random_hit = rand() % 100;
	hit_chance = ((player->c_stats.proficiency / 2) + random_hit);

	if (hit_chance < (ATTACK_HIT - (curr_enemies[choice].c_stats.proficiency / 2)))
	{
		damage_roll = (player->c_stats.strength + (player->c_stats.proficiency / 2) + player->equip.weapon.base_damage);
		damage_roll = damage_roll - curr_enemies[choice].c_stats.constitution;

		variance = damageVariance();				//Set the variance
		damage_roll = damage_roll * variance;			//Calculate final damage

		std::cout << "Hit " << curr_enemies[choice].getEName() << " for " << damage_roll << " damage!\n";

		curr_enemies[choice].health = curr_enemies[choice].health - damage_roll;
		if (curr_enemies[choice].health < 0)
		{
			curr_enemies[choice].health = 0;
		}

		Sleep(1500);
	}
	else
	{
		printf("Attack missed!\n");
		Sleep(1500);
	}

	return;
}

///-----------------------------------------------------------
/// Function that will alow for variance to occur during spells or attacks
/// Will return a value between .7 and 1.2
///-----------------------------------------------------------
double BattleSequence::damageVariance()
{
	double variance = 0.0;

	variance = (rand() % 6) + 1;
	variance = (variance / 10) + 0.6;

	return variance;
}

///-----------------------------------------------------------
/// Function that displays the full list of spells that player has access to
/// Returns the spell_id of the selected spell. Uses choice to store the index post player selection
///-----------------------------------------------------------
int BattleSequence::playerChooseSpell()
{
int choice = 0;
int num_spells = 0;			//Holds how many spells the player has. For sake of sanitizing bad inputs
int counter = 0;
int spell_index = 0;
bool validate_check = true;

do
{
	system("CLS");
	informationScreen();
	validate_check = true;
	do
	{
		spell_index = player->spell_book[counter];
		std::cout << "| " << counter + 1 << ". " << std::left << std::setw(12) << spell_list[spell_index].name << " |\n";
		counter++;
		num_spells++;
	} while ((player->spell_book[counter] != 0) && (counter < spell_list->MAX_PLAYER_SPELL));				//Break if the next spell is not existent
	std::cout << "| 0. " << std::left << std::setw(12) << "Return" << " |\n";

	std::cin >> choice;
	if (std::cin.fail() || choice < 0 || choice > num_spells)					//Check if the input is correct (within range, is a
	{
		std::cin.clear();
		std::cin.ignore(1);
		counter = 0;
		num_spells = 0;
		validate_check = false;
	}
} while (!validate_check);
//-----------------------------------------------------------
// Set choice to the index of the spell that maps to the choice number
// Subtract one from the index in the player->spell_book then use that index to get the spell_id from the master list of spells
//-----------------------------------------------------------
if (choice != 0)
{
	choice = spell_list[player->spell_book[choice - 1]].spell_id;
}

return choice;
}

///-----------------------------------------------------------
/// Takes a spell_id from playerChooseSpell and uses it to cast spell with the effect for it depending on the type
/// Find way to make a more robust system for more interesting spells
///-----------------------------------------------------------
int BattleSequence::castSpell(int index)
{
int value = 0;			//Holds whatever number that the spell needs to use
int spell_type = 0;

spell_type = spell_list[index].s_class;

switch (spell_type)
{
	case PHYSICAL:
		value = physicalSpellcast(index);
		break;
	case MAGICAL:
		value = magicalSpellcast(index);
		break;
	case HEAL:
		value = healingSpellcast(index);
		break;
	case UTILITY:
		break;
	default:
		std::cout << "Error in building spell\n";
		break;
}

if (value > 0)
{
	player->mana = player->mana - spell_list[index].cost;
	Sleep(1500);
}

return value;
}

///-----------------------------------------------------------
/// Function that handles physical spells that will be cast
/// Spells scale off of strength and proficiency. Damage reduced my enemy constitution
///-----------------------------------------------------------
int BattleSequence::physicalSpellcast(int spell_id)
{
int damage_roll = 0;
int enemy_target = 0;
int counter = 0;
double variance = 0.0;

//-----------------------------------------------------------
// Spell logic if the spell is single target 
//-----------------------------------------------------------
if (!(spell_list[spell_id].aoe))
{
	enemy_target = enemySelect();
	if (enemy_target < 0) //Return call
	{
		damage_roll = -1;
	}
	//-----------------------------------------------------------
	// Select the target and deal
	// damage = ((STR + (PROF/2) * SPELL_MOD) + BASE) - ENEMY_CON
	//-----------------------------------------------------------
	else
	{
		damage_roll = ((player->c_stats.strength + (player->c_stats.proficiency / 2)) * spell_list[spell_id].modifier) + spell_list[spell_id].base_damage;
		variance = damageVariance();
		damage_roll = damage_roll * variance;
		damage_roll = damage_roll - curr_enemies[enemy_target].c_stats.constitution;
		curr_enemies[enemy_target].health = curr_enemies[enemy_target].health - damage_roll;
		std::cout << spell_list[spell_id].name << " dealt " << damage_roll << " damage to " << curr_enemies[enemy_target].getEName() << "!\n";
		if (curr_enemies[enemy_target].health < 0)
		{
			curr_enemies[enemy_target].health = 0;
		}
	}

}
//-----------------------------------------------------------
// Spell logic if the spell is aoe
//-----------------------------------------------------------
else
{
	std::cout << spell_list[spell_id].name << " dealt\n";
	//-----------------------------------------------------------
	// Run through the pod list and deal damage to each with
	// damage = ((STR + (PROF/2) * SPELL_MOD) + BASE) - ENEMY_CON
	//-----------------------------------------------------------
	while (counter < pod.set_size)
	{
		if (curr_enemies[counter].health > 0)			
		{
			variance = damageVariance();
			damage_roll = ((player->c_stats.strength + (player->c_stats.proficiency / 2)) * spell_list[spell_id].modifier) + spell_list[spell_id].base_damage;
			damage_roll = damage_roll * variance;
			damage_roll = damage_roll - curr_enemies[counter].c_stats.constitution;
			curr_enemies[counter].health = curr_enemies[counter].health - damage_roll;
			std::cout << damage_roll << " to " << curr_enemies[counter].getEName() << "!\n";
			if (curr_enemies[counter].health < 0)
			{
				curr_enemies[counter].health = 0;
			}
		}
		counter++;
	}
}

return damage_roll;
}

///-----------------------------------------------------------
/// Basically same function as physical spells but with different modifiers and such
///-----------------------------------------------------------
int BattleSequence::magicalSpellcast(int spell_id)
{
//-----------------------------------------------------------
// Variable declarations
//-----------------------------------------------------------
int damage_roll = 0;
int enemy_target = 0;
int counter = 0;
double variance = 0.0;

//-----------------------------------------------------------
// Spell logic if the spell is single target
//-----------------------------------------------------------
if (!spell_list[spell_id].aoe)
{
	enemy_target = enemySelect();

	if (enemy_target < 0)	//Return case
	{
		damage_roll = -1;
	}
	else
	{
		variance = damageVariance();
		damage_roll = (player->c_stats.aptitude * spell_list[spell_id].modifier) + spell_list[spell_id].base_damage;
		damage_roll = damage_roll * variance;
		damage_roll = damage_roll - curr_enemies[enemy_target].c_stats.fortitude;
		curr_enemies[enemy_target].health = curr_enemies[enemy_target].health - damage_roll;
		std::cout << spell_list[spell_id].name << " dealt " << damage_roll << " to " << curr_enemies[enemy_target].getEName() << "!\n";
		if (curr_enemies[enemy_target].health < 0)
		{
			curr_enemies[enemy_target].health = 0;
		}
	}
}
//-----------------------------------------------------------
// Spell logic if the spell is aoe
//-----------------------------------------------------------
else
{
	std::cout << spell_list[spell_id].name << " dealt\n";
	//-----------------------------------------------------------
	// Spell logic if the spell is aoe
	//-----------------------------------------------------------
	while (counter < pod.set_size)
	{
		if (curr_enemies[counter].health > 0)
		{
			variance = damageVariance();
			damage_roll = (player->c_stats.aptitude * spell_list[spell_id].modifier) + spell_list[spell_id].base_damage;
			damage_roll = damage_roll * variance;
			damage_roll = damage_roll - curr_enemies[counter].c_stats.fortitude;
			curr_enemies[counter].health = curr_enemies[counter].health - damage_roll;
			std::cout << damage_roll << " to " << curr_enemies[counter].getEName() << "!\n";
			if (curr_enemies[counter].health < 0)
			{
				curr_enemies[counter].health = 0;
			}
		}
		counter++;
	}
}


return damage_roll;
}

///-----------------------------------------------------------
/// Function that handles healing spells
/// TODO add in a system that handles for status removal as well
/// -----------------------------------------------------------
int BattleSequence::healingSpellcast(int spell_id)
{
int value = 0;

if (player->health = player->getMaxHealth())			//Case if player is already full health
{
	std::cout << "You are at full health!\n";
	value = -1;
}
else
{
	value = player->c_stats.aptitude * spell_list[spell_id].modifier + spell_list[spell_id].base_damage;
	player->health = player->health + value;
	if (player->health > player->getMaxHealth())
	{
		player->health = player->getMaxHealth();
	}
	std::cout << "You healed for " << value << "!\n";
}

Sleep(1400);

return value;
}

//Function that lets players defend for a turn
//Double their resistance stats for the next turn. 
void BattleSequence::playerGuard()
{
	system("CLS");
	informationScreen();
	std::cout << "Defenses raised!\n";
	player->c_stats.constitution = player->c_stats.constitution * 2;
	player->c_stats.fortitude = player->c_stats.fortitude * 2;
	return;
}

//Handles what enemies do during enemy turn. Read todo inside function
void BattleSequence::enemyPhase()
{
//TODO make a basic AI system for enemies
//If there is difficulty, make hardest difficulty calculate all damage and use highest one

int rand_hit = 0;
int hit_chance = 0;
int damage_roll = 0;
int size = pod.set_size;
int counter = 0;
double hit_variance = 0;

system("CLS");
informationScreen();

do
{
	if (curr_enemies[counter].health > 0)			//Check to see if enemy is alive
	{
		rand_hit = rand() % 100;				//Roll for hit chance
		hit_chance = (curr_enemies[counter].c_stats.proficiency / 2) + rand_hit;			//Calculate hit hance

		if (hit_chance < (ATTACK_HIT - (player->c_stats.proficiency / 2)))			//Check if it hits
		{
			hit_variance = damageVariance();

			//Temporary holder modifier for enemies to do damage while I figure out their attack system
			damage_roll = ((curr_enemies[counter].c_stats.strength * 5) + (curr_enemies[counter].c_stats.proficiency * 2))
				- (player->c_stats.constitution + player->equip.armor.phys_value);
			damage_roll = damage_roll * hit_variance;

			if (damage_roll < 1)				//Case if enemies do no damage
			{
				std::cout << curr_enemies[counter].getEName() << " dealt no damage! \n";
			}
			else
			{
				player->health = player->health - damage_roll;
				std::cout << curr_enemies[counter].getEName() << " strikes for " << damage_roll << " damage!\n";
			}

			Sleep(1500);
		}
		else				//Attack misses
		{
			std::cout << curr_enemies[counter].getEName() << " missed!\n";

			Sleep(1500);
		}
	} 
	else					//Set health to 0 if the monster is already dead
	{
		curr_enemies[counter].health = 0;
	}

	counter++;
}while(counter < size);
}

//For when the battle ends
//Handles cases for both leaving the battle early and killing all enemies
//Also resets any buffs player may have used
void BattleSequence::endPhase(bool &battle_flag)
{
	int counter = 0;
	int size = pod.set_size;
	int death_counter = 0;
	int experience = 0;
	int gold = 0;

	//Reset stats for player
	player->c_stats = player->getStats();

	//Reset gold and exp values before each end phase to return proper amount back
	gold = 0;
	experience = 0;
	//Checking for dead enemies. Then set their health to 0
	while (counter < size)
	{
		if (!(curr_enemies[counter].health > 0))
		{
			death_counter++;
			gold = gold + curr_enemies[counter].gold;
			experience = experience + curr_enemies[counter].exp;
		}

		counter++;
	}

	//Run if all enemies are dead OR player just ran from battle
	if (death_counter == size || !battle_flag)
	{
		system("CLS");
		informationScreen();
		if (battle_flag)			//If player did not escape before all enemies are defeated
		{
			std::cout << "The battle is won!\n";
		}
		else						//If player ran before all enemies were defeated
		{
			std::cout << "You escaped succesfully!\n";
		}
		std::cout << "You earned " << gold << " gold!\n";
		player->gold = player->gold + gold;
		std::cout << "You earned " << experience << " exp!\n";
		player->exp = experience;

		Sleep(1800);

		battle_flag = false;
	}

	return;
}

BattleSequence::~BattleSequence()
{
}

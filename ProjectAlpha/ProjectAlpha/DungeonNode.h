#pragma once
#include "Dungeon.h"
#include "EnemyPod.h"


/*
* This class deals with the zones (specific area) of a dungeon. It will maintain player position and all the monster information the player will run into
* All battles will be called from here and be returned back to the same node. This should be able to switch the probability of each pod by sharing the same
* index of the list of occurences and list of pods. Be sure to add and delete pods as they come. Be sure to track what proportion of monster die in each
* zone. Keep it local to each zone but think of expanding it to nearby zones as well. Find way to inherit the changing spawn rates from the
* GAME_INFO master class
*/


struct SPAWN_INFORMATION
{
	float* occurences;				//Holds the list of probabilites that each pod will have in any given zone
	int* pod_list;					//Holds list of pods that are available in this zone
};
typedef struct SPAWN_INFORMATION node_info;

class DungeonNode:public Dungeon
{
public:
	DungeonNode();

	node_info info;

	int id;					//Hold the ID of the specific node at hand. Used to determine specific spawn rates of enemy pods
	int x_coord;
	int y_coord;
	
	//Directional movements for dungeon
	DungeonNode* north;		//Positive y direction	
	DungeonNode* east;		//Negative x direction
	DungeonNode* south;		//Negative y direction
	DungeonNode* west;		//Positive x direction

	~DungeonNode();
};


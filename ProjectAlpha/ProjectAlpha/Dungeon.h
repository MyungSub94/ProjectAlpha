#pragma once
#include <string>

class Dungeon
{
public:
	Dungeon();
	
	//-----------------------------------------------------------
	// Class variables
	//-----------------------------------------------------------
	struct DUNGEON_COORDS
	{
		int x;
		int y;
	};
	typedef struct DUNGEON_COORDS coords;

	coords* layout;			//Holds layout of the dungeon (via holding the coordinates of each node)
	coords p_location;		//Coordinate location of each node
	int id;					//Id of the specific dungeon (probably not needed)

	~Dungeon();
};


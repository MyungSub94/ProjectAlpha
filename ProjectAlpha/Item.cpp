#include "stdafx.h"
#include "Item.h"

Item::Item()
{
}

Item::Item(std::string i_name, std::string descript, int i_id, int i_cost)
{
	name = i_name;
	description = descript;
	id = i_id;
	cost = i_cost;
}


Item::~Item()
{
}


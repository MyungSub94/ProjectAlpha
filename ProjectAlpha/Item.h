#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
public:
	Item();

	std::string name;
	std::string description;
	int id;					//Holds id of the item. TRY to be robust with it (leave space to add items) create a numbering scheme
	int cost;			//Price of item in the shop (if available) Negative price for Key items or nulls

	virtual ~Item();
};

#endif


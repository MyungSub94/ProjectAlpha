#pragma once
#include <string>

class Item
{
public:
	Item();

	std::string name;
	std::string description;
	int cost;			//Price of item in the shop (if available) Negative price for Key items or nulls

	virtual ~Item();
};


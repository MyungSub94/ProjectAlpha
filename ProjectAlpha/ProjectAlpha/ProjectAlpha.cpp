// ProjectAlpha.cpp : Defines the entry point for the console application.
//Test commit

#include "stdafx.h"
#include <stdlib.h>

#include "town.h"

int main()
{
	Town start_town = Town(1);

	start_town.townGUI();					//Build a town

    return 0;
}

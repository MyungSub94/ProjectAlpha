#include "stdafx.h"
#include "town.h"


Town::Town()
{
}

void Town::townGUI()
{
	int selection = 0;

	do
	{
		system("CLS");
		std::cout << "---------------------------\n";
		std::cout << "| 1. " << std::left << std::setw(20) << "go to dungeon" << " |\n";
		std::cout << "| 2. " << std::left << std::setw(20) << "visit item shop" << " |\n";
		std::cout << "| 3. " << std::left << std::setw(20) << "visit weapon shop" << " |\n";
		std::cout << "| 4. " << std::left << std::setw(20) << "visit armor shop" << " |\n";
		std::cout << "| 5. " << std::left << std::setw(20) << "visit inn" << " |\n";
		std::cout << "---------------------------\n";

		std::cin >> selection;
		switch (selection)
		{
		case 1:

		default:
			break;
		}
	} while (std::cin.fail() || selection > 5 || selection < 1);

}


Town::~Town()
{
}

#pragma once
#include "Headers/Player.h"
#include "Headers/Weapon.h"
#include "Headers/Enemy.h"
#include <iostream>
#include <ctime>

int main()
{
	srand(time(0));
	setlocale(0, "rus");

	int r, w;
	bool dodge, death = false;

	Weapon* weapon = nullptr;
	Enemy* enemy = nullptr;

	Mace m;
	Sword s;
	SpellBook sb;

	///////////////////////
	restart:
	///////////////////////

	std::cout << "Choose race:\n1 - Orc\n2 - Human\n3 - Elf\n";
	std::cin >> r;

	while (r < 1 || r > 3)
	{
		std::cout << "Enter correct value!" << std::endl;
		std::cin >> r;
	}

	std::cout << "\nChoose weapon:\n1 - Sword\n2 - Mace\n3 - Spell Book\n";
	std::cin >> w;

	while (w < 1 || w > 3)
	{
		std::cout << "Enter correct value!" << std::endl;
		std::cin >> w;
	}

	switch (w)
	{
	case ChooseSword:
		weapon = &s;
		break;
	case ChooseMace:
		weapon = &m;
		break;
	case ChooseSpellBook:
		weapon = &sb;
		break;
	default:
		weapon = nullptr;
		break;
	}
	
	Player p(r, w);
	
	std::cout << std::endl;
	
	p.GetInfo();

	while (p.GetHP() > 0)
	{
		if (death)
			break;
		switch (rand() % 3 + 1)
		{
		case 1:
			enemy = new Spider;
			break;
		case 2:
			enemy = new Wolf;
			break;
		case 3:
			enemy = new Bear;
			break;
		default:
			enemy = nullptr;
		}
		std::cout << "\nYou have been attacked by " << enemy->GetName() << "!" << std::endl;
		std::cout << "\nWhat should you do?\n1 - Attack\n2 - Try to escape (50% chance)\n3 - Get your status\n4 - Get enemy's status\n5 - Do seppuku\n";
		std::cin >> w;
		while (enemy->GetHP() > 0)
		{
			switch (w)
			{
			case 1:
				if (p.GetSP() >= weapon->GetSPD() && p.GetMP() >= weapon->GetMPD())
				{
					std::cout << "\nYou attack " << enemy->GetName() << " inflicting " << p.Strike(weapon, p, enemy) << " damage!" << std::endl;
					if (enemy->GetHP() > 0)
						std::cout << "\nEnemy has " << enemy->GetHP() << " health points left" << std::endl;
				}
				else
				{
					if (p.GetSP() < weapon->GetSPD())
						std::cout << "\nYou don't have enough stamina!" << std::endl;
					if (p.GetMP() < weapon->GetMPD())
						std::cout << "You don't have enough mana!" << std::endl << std::endl;
					std::cout << "Enemy has " << enemy->GetHP() << " health points left" << std::endl;
				}
				if (enemy->GetHP() <= 0)
				{
					std::cout << '\n' << enemy->GetName() << " has been defeated!" << " You earned " << enemy->GetXP() << " experience." << std::endl;
					enemy->PutXP(p);
					delete enemy;
					enemy = nullptr;
				}
				else
				{
					std::cout << '\n' << enemy->GetName() << " attacks back inflicting " << enemy->Strike(p) << " damage!" << std::endl;
					if (p.GetHP() <= 0)
					{
						death = true;
					}
				}
				break;
			case 2:
				if (rand() % 2)
				{
					dodge = true;
					std::cout << "\nYou have been escaped!" << std::endl;
					delete enemy;
					enemy = nullptr;
				}
				else
				{
					dodge = false;
					std::cout << "\nYou haven't been escaped!" << std::endl;
				}
				break;
			case 3:
				std::cout << std::endl;
				p.GetInfo();
				break;
			case 4:
				std::cout << std::endl;
				enemy->GetInfo();
				break;
			case 5:
				death = true;
				break;
			}
			if (death)
			{
				delete enemy;
				enemy = nullptr;
				break;
			}
			if (enemy == nullptr)
				break;
			else
			{
				std::cout << "\nWhat should you do?\n1 - Attack\n2 - Try to escape (50% chance)\n3 - Get your status\n4 - Get enemy's status\n5 - Do seppuku\n";
				std::cin >> w;
			}
		}
	}

	if (death)
	{
		std::cout << "\n\t\t=================YOU ARE DEAD!!!=================\n" << std::endl << std::endl;
		std::cout << "Start again? (1 - Yes, 2 - No)" << std::endl;
		std::cin >> w;
		while (w < 1 || w > 2)
		{
			std::cout << "Enter correct value!" << std::endl;
			std::cin >> w;
		}
		if (w == 1)
		{
			death = false;
			goto restart;
		}
	}

	return 0;
}
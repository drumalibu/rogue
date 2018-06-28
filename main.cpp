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

	std::cout << "Выберите расу:\n1 - Орк\n2 - Человек\n3 - Эльф\n";
	std::cin >> r;

	while (r < 1 || r > 3)
	{
		std::cout << "Введите корректное значение!" << std::endl;
		std::cin >> r;
	}

	std::cout << "\nВыберите оружие:\n1 - Меч\n2 - Булава\n3 - Книга заклинаний\n";
	std::cin >> w;

	while (w < 1 || w > 3)
	{
		std::cout << "Введите корректное значение!" << std::endl;
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
		std::cout << "\nНа вас напал " << enemy->GetName() << "!" << std::endl;
		std::cout << "\nЧто делать?\n1 - Ударить\n2 - Попробовать убежать (шанс 50%)\n3 - Получить информацию о себе\n4 - Получить информацию о противнике\n5 - Сделать сэппуку\n";
		std::cin >> w;
		while (enemy->GetHP() > 0)
		{
			switch (w)
			{
			case 1:
				if (p.GetSP() >= weapon->GetSPD() && p.GetMP() >= weapon->GetMPD())
				{
					std::cout << "\nВы бьете " << enemy->GetName() << " нанося " << p.Strike(weapon, p, enemy) << " урона!" << std::endl;
					if (enemy->GetHP() > 0)
						std::cout << "\nУ противника осталось " << enemy->GetHP() << " ед. здоровья" << std::endl;
				}
				else
				{
					if (p.GetSP() < weapon->GetSPD())
						std::cout << "\nУ вас не хватает выносливости!" << std::endl;
					if (p.GetMP() < weapon->GetMPD())
						std::cout << "У вас не хватает маны!" << std::endl << std::endl;
					std::cout << "У противника осталось " << enemy->GetHP() << " ед. здоровья" << std::endl;
				}
				if (enemy->GetHP() <= 0)
				{
					std::cout << '\n' << enemy->GetName() << " Повержен!" << " Получено " << enemy->GetXP() << " опыта." << std::endl;
					enemy->PutXP(p);
					delete enemy;
					enemy = nullptr;
				}
				else
				{
					std::cout << '\n' << enemy->GetName() << " бьет в ответ нанося " << enemy->Strike(p) << " урона!" << std::endl;
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
					std::cout << "\nВам удалось скрыться!" << std::endl;
					delete enemy;
					enemy = nullptr;
				}
				else
				{
					dodge = false;
					std::cout << "\nВам не удалось скрыться!" << std::endl;
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
				std::cout << "\nЧто делать?\n1 - Ударить\n2 - Попробовать убежать (шанс 50%)\n3 - Получить информацию о себе\n4 - Получить информацию о противнике\n5 - Сделать сэппуку\n";
				std::cin >> w;
			}
		}
	}

	if (death)
	{
		std::cout << "\n\t\t=================ВЫ ПОГИБЛИ!!!=================\n" << std::endl << std::endl;
		std::cout << "Начать заново? (1 - Да, 2 - нет)" << std::endl;
		std::cin >> w;
		while (w < 1 || w > 2)
		{
			std::cout << "Введите корректное значение!" << std::endl;
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
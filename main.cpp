#include "Player.h"
#include "Weapon.h"
#include "Enemy.h"
#include <iostream>
#include <time.h>
//#include <conio.h>

int main()
{
	srand(time(0));
	setlocale(0, "rus");

	int r, w;
	//int nww;
	bool dodge, death = false;

	Weapon *weapon;
	Enemy *enemy;

	Mace m;
	Sword s;
	SpellBook sb;

	///////////////////////
	restart:
	///////////////////////

	std::cout << "�������� ����:\n1 - ���\n2 - �������\n3 - ����\n";
	std::cin >> r;

	while (r < 1 || r > 3)
	{
		std::cout << "������� ���������� ��������!" << std::endl;
		std::cin >> r;
	}

	std::cout << "\n�������� ������:\n1 - ���\n2 - ������\n3 - ����� ����������\n";
	std::cin >> w;

	while (w < 1 || w > 3)
	{
		std::cout << "������� ���������� ��������!" << std::endl;
		std::cin >> w;
	}

	switch (w)
	{
	case ChooseSword:				//��������//
		weapon = &s;
		break;
	case ChooseMace:				   //��//
		weapon = &m;
		break;
	case ChooseSpellBook:		//WEAPON *? = new ??//
		weapon = &sb;
		break;
	}
	
	Player p(r, w);
	
	std::cout << std::endl;
	
	p.GetInfo();

	/*std::cout << "Smenit' pushku????" << std::endl;
	std::cin >> nww;
	if (nww == 1)
	{
		std::cout << "\n�������� ������:\n1 - ���\n2 - ������\n3 - ����� ����������\n";
		std::cin >> w;
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
		}
		p.SetWPN(weapon);
	}

	p.GetInfo();
	getch();*/

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
		}
		std::cout << "\n�� ��� ����� " << enemy->GetName() << "!" << std::endl;
		std::cout << "\n��� ������?\n1 - �������\n2 - ����������� ������� (���� 50%)\n3 - �������� ���������� � ����\n4 - �������� ���������� � ����������\n5 - ������� �������\n";
		std::cin >> w;
		while (enemy->GetHP() > 0)
		{
			switch (w)
			{
			case 1:
				if (p.GetSP() >= weapon->GetSPD() && p.GetMP() >= weapon->GetMPD())
				{
					std::cout << "\n�� ����� " << enemy->GetName() << " ������ " << p.Strike(weapon, p, enemy) << " �����!" << std::endl;
					if (enemy->GetHP() > 0)
						std::cout << "\n� ���������� �������� " << enemy->GetHP() << " ��. ��������" << std::endl;
				}
				else
				{
					if (p.GetSP() < weapon->GetSPD())
						std::cout << "\n� ��� �� ������� ������������!" << std::endl;
					if (p.GetMP() < weapon->GetMPD())
						std::cout << "� ��� �� ������� ����!" << std::endl << std::endl;
					std::cout << "� ���������� �������� " << enemy->GetHP() << " ��. ��������" << std::endl;
				}
				if (enemy->GetHP() <= 0)
				{
					std::cout << '\n' << enemy->GetName() << " ��������!" << " �������� " << enemy->GetXP(p) << " �����." << std::endl;
					delete enemy;
					enemy = nullptr;
				}
				else
				{
					std::cout << '\n' << enemy->GetName() << " ���� � ����� ������ " << enemy->Strike(p) << " �����!" << std::endl;
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
					std::cout << "\n��� ������� ��������!" << std::endl;
					delete enemy;
					enemy = nullptr;
				}
				else
				{
					dodge = false;
					std::cout << "\n��� �� ������� ��������!" << std::endl;
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
				std::cout << "\n��� ������?\n1 - �������\n2 - ����������� ������� (���� 50%)\n3 - �������� ���������� � ����\n4 - �������� ���������� � ����������\n5 - ������� �������\n";
				std::cin >> w;
			}
		}
	}

	if (death)
	{
		std::cout << "\n\t\t=================�� �������!!!=================\n" << std::endl << std::endl;
		std::cout << "������ ������? (1 - ��, 2 - ���)" << std::endl;
		std::cin >> w;
		while (w < 1 || w > 2)
		{
			std::cout << "������� ���������� ��������!" << std::endl;
			std::cin >> w;
		}
		if (w == 1)
		{
			death = false;
			goto restart;
		}
	}

	system("pause");
	return 0;
}
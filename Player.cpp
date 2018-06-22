#pragma once
#include "Player.h"
#include "Weapon.h"
#include "Enemy.h"
#include <string>
#include <iostream>

Player::Player()
{
	LVL = 0;
	HP = 0;
	MP = 0;
	SP = 0;
	XP = 0;
	NEXTLVLXP = 0;
	RACE = "";
	WEAPON = "";
}

Player::Player(int RACE, int WEAPON)
{
	LVL = 1;
	XP = 0;
	NEXTLVLXP = 1000;
	if (RACE == Orc)
	{
		this->RACE = "Орк";
		HP = 150;
		MAXHP = 150;
		MP = 30;
		MAXMP = 30;
		SP = 200;
		MAXSP = 200;

	}
	else if (RACE == Human)
	{
		this->RACE = "Человек";
		HP = 110;
		MAXHP = 110;
		MP = 50;
		MAXMP = 50;
		SP = 170;
		MAXSP = 50;
	}
	else if (RACE == Elf)
	{
		this->RACE = "Эльф";
		HP = 80;
		MAXHP = 80;
		MP = 80;
		MAXMP = 80;
		SP = 120;
		MAXSP = 120;
	}
	switch (WEAPON)
	{
	case ChooseSword:
		this->WEAPON = "Меч";
		break;
	case ChooseMace:
		this->WEAPON = "Булава";
		break;
	case ChooseSpellBook:
		this->WEAPON = "Книга заклинаний";
		break;
	}
}

Player::~Player()
{

}

//int Player::SetMP(int value)
//{
//	return MP + value;
//}

int Player::Strike(Weapon *w, Player &p, Enemy *e)
{
	e->SetHP(w->GetDMG());
	return w->Strike(p);
}

void Player::GetInfo()
{
	std::cout << "Раса: " << RACE << std::endl;
	std::cout << "Уровень: " << LVL << std::endl;
	std::cout << "Опыт: " << XP << " / " << NEXTLVLXP << std::endl;
	std::cout << "Здоровье: " << HP << " / " << MAXHP << std::endl;
	std::cout << "Мана: " << MP << " / " << MAXMP << std::endl;
	std::cout << "Выносливость: " << SP << " / " << MAXSP << std::endl;
	std::cout << "Оружие: " << WEAPON << std::endl;
}

void Player::SetMP(int value)
{
	MP += value;
}

int Player::GetMP()
{
	return this->MP;
}

void Player::SetSP(int value)
{
	SP += value;
}

int Player::GetSP()
{
	return this->SP;
}

void Player::SetHP(int value)
{
	HP += value;
}

int Player::GetHP()
{
	return this->HP;
}

void Player::SetXP(Enemy *e)
{
	XP += e->XP;
	if (XP >= NEXTLVLXP)
	{
		LVL += 1;
		if (RACE == "Орк")
		{
			MAXHP += 30;
			MAXSP += 30;
			MAXMP += 10;
		}
		else if (RACE == "Человек")
		{
			MAXHP += 20;
			MAXSP += 20;
			MAXMP += 15;
		}
		else if (RACE == "Эльф")
		{
			MAXHP += 15;
			MAXSP += 15;
			MAXMP += 25;
		}
		HP = MAXHP;
		MP = MAXMP;
		SP = MAXSP;
		XP -= NEXTLVLXP;
		NEXTLVLXP *= 1.5;
	}
}

void Player::SetWPN(Weapon *NewWPN)
{
	this->WEAPON = NewWPN->Name;
}
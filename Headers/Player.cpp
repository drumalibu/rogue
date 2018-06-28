#pragma once
#include "Player.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Armor.h"
#include <iostream>

Player::Player()
{
	LVL = 0;
	HP = 0;
	MP = 0;
	SP = 0;
	DMGREDUCTION = 0;
	XP = 0;
	NEXTLVLXP = 0;
	RACE = nullptr;
	WEAPON = nullptr;
	ARMOR = nullptr;
	STAT.STUN = false;
	STAT.POISON = false;
	STAT.BLEEDING = false;
}

Player::Player(int RACE, int WEAPON)
{
	LVL = 1;
	XP = 0;
	NEXTLVLXP = 1000;
    ARMOR = "N/A";
    DMGREDUCTION = 0;
	STAT.STUN = false;
	STAT.POISON = false;
	STAT.BLEEDING = false;
	if (RACE == Orc)
	{
		this->RACE = "Orc";
		HP = 150;
		MAXHP = 150;
		MP = 30;
		MAXMP = 30;
		SP = 200;
		MAXSP = 200;
	}
	else if (RACE == Human)
	{
		this->RACE = "Human";
		HP = 110;
		MAXHP = 110;
		MP = 50;
		MAXMP = 50;
		SP = 170;
		MAXSP = 50;
	}
	else if (RACE == Elf)
	{
		this->RACE = "Elf";
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
		this->WEAPON = "Sword";
		break;
	case ChooseMace:
		this->WEAPON = "Mace";
		break;
	case ChooseSpellBook:
		this->WEAPON = "Spell Book";
		break;
	default:
		break;
	}
}

Player::~Player()
{

}

int Player::Strike(Weapon* w, Player& p, Enemy* e)
{
	e->SetHP(w->GetDMG(), p);
	return w->Strike(p);
}

void Player::GetInfo()
{
	std::cout << "Race: " << RACE << std::endl;
	std::cout << "Level: " << LVL << std::endl;
	std::cout << "Experience: " << XP << " / " << NEXTLVLXP << std::endl;
	std::cout << "Health: " << HP << " / " << MAXHP << std::endl;
	std::cout << "Mana: " << MP << " / " << MAXMP << std::endl;
	std::cout << "Stamina: " << SP << " / " << MAXSP << std::endl;
	std::cout << "Weapon: " << WEAPON << std::endl;
}

void Player::SetMP(int value)
{
	MP += value;
}

int Player::GetMP()
{
	return MP;
}

void Player::SetSP(int value)
{
	SP += value;
}

int Player::GetSP()
{
	return SP;
}

void Player::SetHP(int value)
{
	HP += value;
}

int Player::GetHP()
{
	return HP;
}

void Player::SetXP(Enemy* e)
{
	XP += e->XP;
	if (XP >= NEXTLVLXP)
	{
		LVL += 1;
		if (RACE == "Orc")
		{
			MAXHP += 30;
			MAXSP += 30;
			MAXMP += 10;
		}
		else if (RACE == "Human")
		{
			MAXHP += 20;
			MAXSP += 20;
			MAXMP += 15;
		}
		else if (RACE == "Elf")
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
		std::cout << "Your level has increased!" << std::endl << std::endl;
	}
}

void Player::SetWPN(Weapon* NewWPN)
{
	WEAPON = NewWPN->GetName();
}

void Player::SetArmor(Armor* NewARM)
{
    ARMOR = NewARM->NAME;
}
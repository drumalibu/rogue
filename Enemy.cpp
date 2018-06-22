#pragma once
#include "Enemy.h"
#include "Player.h"
#include <iostream>

void Enemy::GetInfo()
{
	std::cout << "Противник: " << NAME << std::endl;
	std::cout << "Здоровье: " << HP << std::endl;
	std::cout << "Урон: " << DMG << std::endl;
	std::cout << "Опыт: " << XP << std::endl;
}

Spider::Spider()
{
	NAME = "Паук";
	HP = 15;
	DMG = 8;
	XP = 200;
}

Spider::~Spider()
{

}

int Spider::Strike(Player &p)
{
	p.SetHP(-DMG);
	return DMG;
}

std::string Spider::GetName()
{
	return this->NAME;
}

int Spider::GetHP()
{
	return this->HP;
}

void Spider::SetHP(int value)
{
	HP -= value;
}

int Spider::GetXP(Player &p)
{
	p.SetXP(this);
	return this->XP;
}

Wolf::Wolf()
{
	NAME = "Волк";
	HP = 25;
	DMG = 10;
	XP = 300;
}

Wolf::~Wolf()
{
	
}

int Wolf::Strike(Player &p)
{
	p.SetHP(-DMG);
	return DMG;
}

std::string Wolf::GetName()
{
	return this->NAME;
}

int Wolf::GetHP()
{
	return this->HP;
}

void Wolf::SetHP(int value)
{
	HP -= value;
}

int Wolf::GetXP(Player &p)
{
	p.SetXP(this);
	return this->XP;
}

Bear::Bear()
{
	NAME = "Медведь";
	HP = 35;
	DMG = 15;
	XP = 400;
}

Bear::~Bear()
{
	
}

int Bear::Strike(Player &p)
{
	p.SetHP(-DMG);
	return DMG;
}

std::string Bear::GetName()
{
	return this->NAME;
}

int Bear::GetHP()
{
	return this->HP;
}

void Bear::SetHP(int value)
{
	HP -= value;
}

int Bear::GetXP(Player &p)
{
	p.SetXP(this);
	return this->XP;
}
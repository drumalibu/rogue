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

const char* Enemy::GetName()
{
    return NAME;
}

int Enemy::GetHP()
{
	return HP;
}

int Enemy::GetXP()
{
	return XP;
}

void Enemy::PutXP(Player &p)
{
	p.SetXP(this);
}

void Enemy::SetHP(int value)
{
	HP -= value;
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

int Spider::Strike(Player& p)
{
	int damage = DMG - (DMG * (p.DMGREDUCTION / 100));
	p.SetHP(-damage);
	return damage;
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

int Wolf::Strike(Player& p)
{
	int damage = DMG - (DMG * (p.DMGREDUCTION / 100));
	p.SetHP(-damage);
	return damage;
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

int Bear::Strike(Player& p)
{
	int damage = DMG - (DMG * (p.DMGREDUCTION / 100));
	p.SetHP(-damage);
	return damage;
}
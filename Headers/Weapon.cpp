#pragma once
#include "Weapon.h"
#include "Player.h"
#include <iostream>

Weapon::Weapon()
{
	DMG = 0;
	SPD = 0;
	MPD = 0;
	WGT = 0;
}

Weapon::~Weapon()
{

}

const char* Weapon::GetName()
{
	return Name;
}

int Weapon::GetDMG()
{
	return DMG;
}

int Weapon::GetSPD()
{
	return SPD;
}

int Weapon::GetMPD()
{
	return MPD;
}

int Weapon::GetWGT()
{
    return WGT;
}

Sword::Sword()
{
	Name = "Меч";
	DMG = 15;
	SPD = 20;
	MPD = 0;
	WGT = 5;
}

Sword::~Sword()
{

}

Mace::Mace()
{
	Name = "Булава";
	DMG = 25;
	SPD = 30;
	MPD = 0;
	WGT = 10;
}

Mace::~Mace()
{

}

SpellBook::SpellBook()
{
	Name = "Книга заклинаний";
	DMG = 30;
	SPD = 10;
	MPD = 15;
	WGT = 2;
}

SpellBook::~SpellBook()
{

}

int Sword::Strike(Player& p)
{
	if (p.GetSP() >= SPD)
	{
		p.SetSP(-SPD);
		return DMG;
	}
	else
	{
		return 0;
	}
}

int Mace::Strike(Player& p)
{
	if (p.GetSP() >= SPD)
	{
		p.SetSP(-SPD);
		return DMG;
	}
	else
	{
		return 0;
	}
}

int SpellBook::Strike(Player& p)
{
	if (p.GetMP() >= MPD && p.GetSP() >= SPD)
	{
		p.SetSP(-SPD);
		p.SetMP(-MPD);
		return DMG;
	}
	else
	{
		return 0;
	}
}
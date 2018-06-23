#pragma once
#include "Weapon.h"
#include "Player.h"
#include <iostream>

Weapon::Weapon()
{
	DMG = 0;
	SPD = 0;
	MPD = 0;
}

Weapon::~Weapon()
{

}

int Weapon::Strike(Player &p)
{
	return 0;
}

int Weapon::GetSPD()
{
	return 0;
}

int Weapon::GetMPD()
{
	return 0;
}

int Weapon::GetDMG()
{
	return 0;
}

Sword::Sword()
{
	Name = "Меч";
	DMG = 15;
	SPD = 20;
	MPD = 0;
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
}

SpellBook::~SpellBook()
{

}

int Sword::Strike(Player &p)
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

int Mace::Strike(Player &p)
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

int SpellBook::Strike(Player &p)
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

int Sword::GetSPD()
{
	return this->SPD;
}

int Mace::GetSPD()
{
	return this->SPD;
}

int SpellBook::GetSPD()
{
	return this->SPD;
}

int Sword::GetMPD()
{
	return this->MPD;
}

int Mace::GetMPD()
{
	return this->MPD;
}

int SpellBook::GetMPD()
{
	return this->MPD;
}

int Sword::GetDMG()
{
	return this->DMG;
}

int Mace::GetDMG()
{
	return this->DMG;
}

int SpellBook::GetDMG()
{
	return this->DMG;
}
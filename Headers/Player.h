#pragma once
#include <string>

class Weapon;

class Enemy;

class Player
{
public:
	Player();
	Player(int RACE, int WEAPON);
	~Player();
	int Strike(Weapon *w, Player &p, Enemy *e); //////НАПИСАТЬ БРОНЮ!!!!//////СДЕЛАТЬ ИНВЕНТАРЬ!!!!///////
	void GetInfo();
	int GetMP();
	int GetSP();
	int GetHP();
	void SetWPN(Weapon *NewWPN);
	friend class Sword;
	friend class Mace;
	friend class SpellBook;
	friend class Spider;
	friend class Bear;
	friend class Wolf;

private:
#define Orc 1
#define Human 2
#define Elf 3
	unsigned short LVL;
	short HP; 
	short MAXHP;
	short MP; 
	short MAXMP;
	short SP; 
	short MAXSP;
	unsigned short XP;
	unsigned short NEXTLVLXP;
	std::string RACE;
	std::string WEAPON;
	void SetMP(int value);
	void SetSP(int value);
	void SetHP(int value);
	void SetXP(Enemy *e);
};
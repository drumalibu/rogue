#pragma once

class Weapon;

class Enemy;

class Armor;

class Player
{
public:
	Player();
	Player(int RACE, int WEAPON);
	~Player();
	int Strike(Weapon* w, Player& p, Enemy* e); //////НАПИСАТЬ БРОНЮ!!!!//////СДЕЛАТЬ ИНВЕНТАРЬ!!!!///////
	void GetInfo();
	int GetMP();
	int GetSP();
	int GetHP();
	void SetWPN(Weapon* NewWPN);
    void SetArmor(Armor* NewARM);
	friend class Enemy;
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
	short DMGREDUCTION;
	unsigned short XP;
	unsigned short NEXTLVLXP;
	const char* RACE;
	const char* WEAPON;
	const char* ARMOR;
	void SetMP(int value);
	void SetSP(int value);
	void SetHP(int value);
	void SetXP(Enemy* e);
};
#pragma once

class Player;

class Enemy;

class Weapon
{
public:
#define ChooseSword 1
#define ChooseMace 2
#define ChooseSpellBook 3
	/*friend class Player;*/
	Weapon();
	virtual ~Weapon();
	virtual int Strike(Player& p) = 0;
	const char* GetName();
	int GetDMG();
	int GetSPD();
	int GetMPD();
	int GetWGT();
protected:
	const char* Name;
	int DMG;
	int SPD;
	int MPD;
	int WGT;
};

class Sword : public Weapon
{
public:
	Sword();
	~Sword() override;
	int Strike(Player& p) override;
};

class Mace : public Weapon
{
public:
	Mace();
	~Mace() override;
	int Strike(Player& p) override;
};

class SpellBook : public Weapon
{
public:
	SpellBook();
	~SpellBook() override;
	int Strike(Player& p) override;
};
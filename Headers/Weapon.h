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
	const char* Name;
	virtual int Strike(Player& p);
	virtual int GetMPD();
	virtual int GetSPD();
	virtual int GetDMG();

protected:
	int SPD;
	int DMG;
	int MPD;
	int WGT;
};

class Sword : public Weapon
{
public:
	Sword();
	~Sword() override;
	int Strike(Player& p) override;
	int GetSPD() override;
	int GetMPD() override;
	int GetDMG() override;
};

class Mace : public Weapon
{
public:
	Mace();
	~Mace() override;
	int Strike(Player& p) override;
	int GetMPD() override;
	int GetSPD() override;
	int GetDMG() override;
};

class SpellBook : public Weapon
{
public:
	SpellBook();
	~SpellBook() override;
	int Strike(Player& p) override;
	int GetSPD() override;
	int GetMPD() override;
	int GetDMG() override;
};
#pragma once

class Player;

class Weapon;

class Enemy
{
public:
	const char* GetName();
	int GetHP();
	virtual int Strike(Player& p);
	int GetXP();
	void GetInfo();
	friend class Player;
protected:
	short HP;
	short DMG;
	short XP;
	const char* NAME;
private:
    void SetHP(int value);
    void PutXP(Player& p);
};

class Spider : public Enemy
{
public:
	Spider();
	virtual ~Spider();
	int Strike(Player& p) override;
};

class Wolf : public Enemy
{
public:
	Wolf();
	virtual ~Wolf();
	int Strike(Player& p) override;
};

class Bear : public Enemy
{
public:
	Bear();
	virtual ~Bear();
	int Strike(Player& p) override;
};
#pragma once

class Player;

class Weapon;

class Enemy
{
public:
    void GetInfo();
	const char* GetName();
	int GetHP();
    int GetXP();
	virtual int Strike(Player& p) = 0;
	friend class Player;
protected:
	short HP;
	short DMG;
	short XP;
	const char* NAME;
private:
    void SetHP(int value, Player &p);
    void PutXP(Player& p);
};

class Spider : public Enemy
{
public:
	Spider();
	virtual ~Spider();
	int Strike(Player& p) override;
	int GetPOISON();
private:
    short POISON = 5;
};

class Wolf : public Enemy
{
public:
	Wolf();
	virtual ~Wolf();
	int Strike(Player& p) override;
	int GetBLEEDING();
private:
    short BLEEDING = 5;
};

class Bear : public Enemy
{
public:
	Bear();
	virtual ~Bear();
	int Strike(Player& p) override;
	int GetSTUN();
private:
    short STUN = 20;
};
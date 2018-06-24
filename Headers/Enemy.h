#pragma once

class Player;

class Weapon;

class Enemy
{
public:
	virtual const char* GetName() = 0;
	virtual int GetHP() = 0;
	virtual int Strike(Player& p) = 0;
	virtual void SetHP(int value) = 0;
	virtual int GetXP(Player& p) = 0; /////////////Попробовать не переопределять!!!/////////////////
	void GetInfo();
	friend class Player;
protected:
	short HP;
	short DMG;
	short XP;
	const char* NAME;
};

class Spider : public Enemy
{
public:
	Spider();
	virtual ~Spider();
	int Strike(Player& p) override;
	const char* GetName() override;
	int GetHP() override;
	void SetHP(int value) override;
	int GetXP(Player& p) override;
};

class Wolf : public Enemy
{
public:
	Wolf();
	virtual ~Wolf();
	int Strike(Player& p) override;
	const char* GetName() override;
	int GetHP() override;
	void SetHP(int value) override;
	int GetXP(Player& p) override;
};

class Bear : public Enemy
{
public:
	Bear();
	virtual ~Bear();
	int Strike(Player& p) override;
	const char* GetName() override;
	int GetHP() override;
	void SetHP(int value) override;
	int GetXP(Player& p) override;
};
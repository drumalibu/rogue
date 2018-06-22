#pragma once
#include <string>

class Player;

class Weapon;

class Enemy
{
public:
	virtual std::string GetName() = 0;
	virtual int GetHP() = 0;
	virtual int Strike(Player &p) = 0;
	virtual void SetHP(int value) = 0;
	virtual int GetXP(Player &p) = 0; /////////////онопнанбюрэ ме оепенопедекърэ!!!/////////////////
	void GetInfo();
	friend class Player;
protected:
	short HP;
	short DMG;
	short XP;
	std::string NAME;
};

class Spider : public Enemy
{
public:
	Spider();
	virtual ~Spider();
	int Strike(Player &p) override;
	std::string GetName() override;
	int GetHP() override;
	void SetHP(int value) override;
	int GetXP(Player &p) override;
};

class Wolf : public Enemy
{
public:
	Wolf();
	virtual ~Wolf();
	int Strike(Player &p) override;
	std::string GetName() override;
	int GetHP() override;
	void SetHP(int value) override;
	int GetXP(Player &p) override;
};

class Bear : public Enemy
{
public:
	Bear();
	virtual ~Bear();
	int Strike(Player &p) override;
	std::string GetName() override;
	int GetHP() override;
	void SetHP(int value) override;
	int GetXP(Player &p) override;
};
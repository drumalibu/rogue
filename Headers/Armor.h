//
// Created by dmitry on 24.06.18.
//

class Armor
{
protected:
    const char* NAME;
    const char* ARMOR_CLASS;
    short WEIGHT;
    short DMG_REDUCTION;
    short LVL_REQ;
public:
    Armor();
    virtual ~Armor();
    void GetInfo();
    friend class Player;
};

class LightArmor : public Armor
{
private:
public:
    LightArmor();
    ~LightArmor() override;
};

class HeavyArmor : public Armor
{
private:
public:
    HeavyArmor();
    ~HeavyArmor() override;
};

class Robe : public Armor
{
private:
public:
    Robe();
    ~Robe() override;
};
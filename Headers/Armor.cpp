//
// Created by dmitry on 24.06.18.
//
#pragma once
#include <iostream>
#include "Armor.h"

Armor::Armor()
{
    NAME = "N/A";
    ARMOR_CLASS = "N/A";
    WEIGHT = 0;
    DMG_REDUCTION = 0;
    LVL_REQ = 0;
}

void Armor::GetInfo()
{
    std::cout << "Name: " << NAME << std::endl;
    std::cout << "Armor Class: " << ARMOR_CLASS << std::endl;
    std::cout << "Weight: " << WEIGHT << std::endl;
    std::cout << "Damage Reduction: " << DMG_REDUCTION << std::endl;
    std::cout << "Level Requirement: " << LVL_REQ << std::endl;
}

LightArmor::LightArmor()
{
    ARMOR_CLASS = "Light Armor";
}

HeavyArmor::HeavyArmor()
{
    ARMOR_CLASS = "Heavy Armor";
}

Robe::Robe()
{
    ARMOR_CLASS = "Robe";
}
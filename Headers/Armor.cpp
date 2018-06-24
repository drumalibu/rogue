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
    std::cout << "Название: " << NAME << std::endl;
    std::cout << "Класс брони: " << ARMOR_CLASS << std::endl;
    std::cout << "Вес: " << WEIGHT << std::endl;
    std::cout << "Сопротивление урону: " << DMG_REDUCTION << std::endl;
    std::cout << "Требуемый уровень: " << LVL_REQ << std::endl;
}

LightArmor::LightArmor()
{
    ARMOR_CLASS = "Легкая броня";
}

HeavyArmor::HeavyArmor()
{
    ARMOR_CLASS = "Тяжелая броня";
}

Robe::Robe()
{
    ARMOR_CLASS = "Роба";
}
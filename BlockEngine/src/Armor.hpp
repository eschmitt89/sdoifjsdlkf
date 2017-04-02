//
//  Armor.hpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#ifndef Armor_hpp
#define Armor_hpp

#include "Equipment.hpp"
#include "ArmorType.hpp"

class Armor : public Equipment
{
public:
	Armor(ArmorType armorType, EquipmentRarity rarity, int level, int health, int armor, int crit, int dodge, int power);
	Armor(EquipmentRarity equipmentRarity, int level);
    virtual ~Armor();

protected:
	ArmorType armorType;

	void GenerateStats(EquipmentRarity equipmentRarity, int level);

};

#endif /* Armor_hpp */

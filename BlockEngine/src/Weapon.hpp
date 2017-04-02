//
//  Weapon.hpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include "Equipment.hpp"
#include "WeaponType.hpp"
#include "WeaponSlot.hpp"

class Weapon : public Equipment
{
public:
	Weapon(WeaponType weaponType, WeaponSlot weaponSlot, EquipmentRarity rarity, int level, int health, int armor, int crit, int dodge, int power);
    virtual ~Weapon();

protected:
	WeaponType weaponType;
	WeaponSlot weaponSlot;

private:
};

#endif /* Weapon_hpp */
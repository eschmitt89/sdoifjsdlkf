#ifndef WeaponGenerator_hpp
#define WeaponGenerator_hpp

#include "EquipmentGenerator.hpp"
#include "Weapon.hpp"

class WeaponGenerator : public EquipmentGenerator
{
public:
	WeaponGenerator();
    ~WeaponGenerator();

	Weapon* Generate(int level);
	
private:
	WeaponType GetRandomWeaponType(int level);
	WeaponSlot GenerateWeaponSlot(WeaponType weaponType);
	WeaponSpeed GenerateWeaponSpeed(WeaponType weaponType, WeaponSlot weaponSlot);
	int GenerateWeaponDamage(int level, WeaponSpeed speed, EquipmentQuality equipmentQuality);

	map<WeaponType, string> weaponTypeNames;
	map<WeaponSlot, string> weaponSlotNames;
	map<WeaponType, map<WeaponSlot, map<EquipmentQuality, vector<string>>>> weaponTextureNames;

	void InitializeWeaponTypeNames();
	void InitializeWeaponSlotNames();
	void InitializeTextureNames();

	const sf::Texture* GenerateWeaponTexture(WeaponType weaponType, WeaponSlot weaponSlot, EquipmentQuality equipmentQuality);
};

#endif /* WeaponGenerator_hpp */

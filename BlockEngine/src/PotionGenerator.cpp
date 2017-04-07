//
//  EquipmentGenerator.cpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#include "PotionGenerator.hpp"
#include "ResourceManager.hpp"

PotionGenerator::PotionGenerator()
{

}

////////////////////////////////////////////////////////////////////////

PotionGenerator::~PotionGenerator()
{
    
}

////////////////////////////////////////////////////////////////////////

Potion * PotionGenerator::Generate(int level)
{
	return new Potion(ResourceManager::GetInstance().GetTexture("potion"));
}

////////////////////////////////////////////////////////////////////////

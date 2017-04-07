//
//  GemGenerator.cpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#include "GemGenerator.hpp"
#include "ResourceManager.hpp"

GemGenerator::GemGenerator()
{

}

////////////////////////////////////////////////////////////////////////

GemGenerator::~GemGenerator()
{
    
}

////////////////////////////////////////////////////////////////////////

Gem * GemGenerator::Generate(int level)
{
	return new Gem(ResourceManager::GetInstance().GetTexture("gem"));
}

////////////////////////////////////////////////////////////////////////

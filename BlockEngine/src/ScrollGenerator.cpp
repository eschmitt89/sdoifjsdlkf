//
//  ScrollGenerator.cpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#include "ScrollGenerator.hpp"
#include "ResourceManager.hpp"

ScrollGenerator::ScrollGenerator()
{

}

////////////////////////////////////////////////////////////////////////

ScrollGenerator::~ScrollGenerator()
{
    
}

////////////////////////////////////////////////////////////////////////

Scroll * ScrollGenerator::Generate(int level)
{
	return new Scroll(ResourceManager::GetInstance().GetTexture("scroll"));
}

////////////////////////////////////////////////////////////////////////

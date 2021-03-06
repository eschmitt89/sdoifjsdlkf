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

//
//  Block.cpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#include "Block.hpp"

Block::Block(BlockType type, sf::Vector2f position, sf::Vector2f size)
{
	this->type = type;
	this->position = position;
	this->size = size;
	this->globalBounds = sf::FloatRect(position, size);
}

////////////////////////////////////////////////////////////////////////

Block::~Block()
{
    
}

////////////////////////////////////////////////////////////////////////

BlockType Block::GetType()
{
	return type;
}

////////////////////////////////////////////////////////////////////////

sf::Vector2f Block::GetPosition()
{
	return position;
}

////////////////////////////////////////////////////////////////////////

sf::Vector2f Block::GetSize()
{
	return size;
}

////////////////////////////////////////////////////////////////////////

sf::FloatRect Block::GetGlobalBounds()
{
	return globalBounds;
}
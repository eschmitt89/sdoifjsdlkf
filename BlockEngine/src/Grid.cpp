//
//  Grid.cpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#include "Grid.hpp"
#include "ResourcePath.hpp"
#include "ResourceManager.hpp"

Grid::Grid(int columns, int rows, int blockWidth, int blockHeight)
{
	LoadBlockSprites();

	InitializeBlocks(columns, rows, blockWidth, blockHeight, BlockType::Solid);
}

////////////////////////////////////////////////////////////////////////

Grid::Grid(string fileName, int blockWidth, int blockHeight)
{
	LoadBlockSprites();

	sf::Image gridImage;
	gridImage.loadFromFile(resourcePath() + fileName);

	this->dimensions = (sf::Vector2i)gridImage.getSize();
	this->blockSize = sf::Vector2f(blockWidth, blockHeight);

	for (int column = 0; column < dimensions.x; column++)
	{
		vector<BlockType> blockColumn;

		for (int row = 0; row < dimensions.y; row++)
		{
			blockColumn.push_back(ColorToBlockType(gridImage.getPixel(column, row)));
		}

		blocks.push_back(blockColumn);
	}
}

////////////////////////////////////////////////////////////////////////

Grid::~Grid()
{
	Save("gridSave.png");
}

////////////////////////////////////////////////////////////////////////

void Grid::InitializeBlocks(int columns, int rows, int blockWidth, int blockHeight, BlockType blockType)
{
	dimensions = sf::Vector2i(columns, rows);
	blockSize = sf::Vector2f(blockWidth, blockHeight);

	for (int column = 0; column < dimensions.x; column++)
	{
		vector<BlockType> blockColumn;

		for (int row = 0; row < dimensions.y; row++)
		{
			blockColumn.push_back(blockType);
		}

		blocks.push_back(blockColumn);
	}
}

////////////////////////////////////////////////////////////////////////

void Grid::Draw(sf::RenderWindow &window, Camera* camera)
{
	Vector4i visibleBlocks = GetBlockIndicies(camera->GetView().getCenter() - (camera->GetView().getSize() * 0.5f), camera->GetView().getSize());
    
    for (int column = visibleBlocks.x1; column <= visibleBlocks.x2; column++)
    {
        for (int row = visibleBlocks.y1; row <= visibleBlocks.y2; row++)
        {
			if (IsValidNonEmptyBlockIndex(column, row))
			{
				blockSprites[blocks[column][row]].setPosition(GetBlockPosition(column, row));

				window.draw(blockSprites[blocks[column][row]]);
			}
        }
    }
}

////////////////////////////////////////////////////////////////////////

sf::Vector2i Grid::GetDimensions()
{
	return dimensions;
}

////////////////////////////////////////////////////////////////////////

Block Grid::GetBlock(int column, int row)
{
	if (IsValidBlockIndex(column, row))
	{
		return Block(blocks[column][row], GetBlockPosition(column, row), blockSize);
	}
}

////////////////////////////////////////////////////////////////////////

int Grid::GetBlockKey(int column, int row)
{
	return (column * dimensions.x) + row;
}

////////////////////////////////////////////////////////////////////////

BlockType Grid::GetBlockType(int column, int row)
{
	return IsValidBlockIndex(column, row) ? blocks[column][row] : BlockType::NoBlock;
}

////////////////////////////////////////////////////////////////////////

sf::Vector2f Grid::GetBlockPosition(int column, int row)
{
	return sf::Vector2f(column * blockSize.x, row * blockSize.y);
}

////////////////////////////////////////////////////////////////////////

sf::Vector2i Grid::GetBlockIndex(sf::Vector2f position)
{
	return sf::Vector2i(position.x / blockSize.x, position.y / blockSize.y);
}

////////////////////////////////////////////////////////////////////////

Vector4i Grid::GetBlockIndicies(sf::Vector2f position, sf::Vector2f size)
{
	return Vector4i(GetBlockIndex(position), GetBlockIndex(position + size));
}

////////////////////////////////////////////////////////////////////////

BlockNeighbors Grid::GetBlockNeighbors(int column, int row)
{
	BlockNeighbors neighbors;

	if (IsValidBlockIndex(column - 1, row - 1))
	{
		neighbors.TopLeft = blocks[column - 1][row - 1];
	}
	if (IsValidBlockIndex(column, row - 1))
	{
		neighbors.Top = blocks[column][row - 1];
	}
	if (IsValidBlockIndex(column + 1, row - 1))
	{
		neighbors.TopRight = blocks[column + 1][row - 1];
	}
	if (IsValidBlockIndex(column - 1, row))
	{
		neighbors.Left = blocks[column - 1][row];
	}
	if (IsValidBlockIndex(column + 1, row))
	{
		neighbors.Right = blocks[column + 1][row];
	}
	if (IsValidBlockIndex(column - 1, row + 1))
	{
		neighbors.BottomLeft = blocks[column - 1][row + 1];
	}
	if (IsValidBlockIndex(column, row + 1))
	{
		neighbors.Bottom = blocks[column][row + 1];
	}
	if (IsValidBlockIndex(column + 1, row + 1))
	{
		neighbors.BottomRight = blocks[column + 1][row + 1];
	}

	return neighbors;
}

////////////////////////////////////////////////////////////////////////

void Grid::SetBlockType(int column, int row, BlockType blockType)
{
	if (IsValidBlockIndex(column, row))
	{
		blocks[column][row] = blockType;
	}
}

////////////////////////////////////////////////////////////////////////

void Grid::SetBlockType(sf::Vector2i blockIndex, BlockType blockType)
{
	if (IsValidBlockIndex(blockIndex))
	{
		blocks[blockIndex.x][blockIndex.y] = blockType;
	}
}

////////////////////////////////////////////////////////////////////////

void Grid::SetBlockType(sf::Vector2f position, BlockType blockType)
{
	sf::Vector2i blockIndex = GetBlockIndex(position);

	if (IsValidBlockIndex(blockIndex))
	{
		blocks[blockIndex.x][blockIndex.y] = blockType;
	}
}

////////////////////////////////////////////////////////////////////////

void Grid::SetBlockType(sf::Vector2f position, sf::Vector2f size, BlockType blockType)
{
	Vector4i collidedBlocks = GetBlockIndicies(position, size);

	for (int column = collidedBlocks.x1; column <= collidedBlocks.x2; column++)
	{
		for (int row = collidedBlocks.y1; row <= collidedBlocks.y2; row++)
		{
			if (IsValidBlockIndex(column, row))
			{
				blocks[column][row] = blockType;
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////

bool Grid::IsValidBlockIndex(int column, int row)
{
	return column >= 0 && row >= 0 && column < dimensions.x && row < dimensions.y;
}

////////////////////////////////////////////////////////////////////////

bool Grid::IsValidBlockIndex(sf::Vector2i blockIndex)
{
	return IsValidBlockIndex(blockIndex.x, blockIndex.y);
}

////////////////////////////////////////////////////////////////////////

bool Grid::IsValidNonEmptyBlockIndex(int column, int row)
{
	return IsValidBlockIndex(column, row) && blocks[column][row] != BlockType::Empty;
}

////////////////////////////////////////////////////////////////////////

void Grid::LoadBlockSprites()
{
	blockSprites[BlockType::Solid] = sf::Sprite(*ResourceManager::GetInstance().GetTexture("whiteBlock"));
	blockSprites[BlockType::Corner] = sf::Sprite(*ResourceManager::GetInstance().GetTexture("whiteBlock"));
	blockSprites[BlockType::Platform] = sf::Sprite(*ResourceManager::GetInstance().GetTexture("platformBlock"));
	blockSprites[BlockType::Ladder] = sf::Sprite(*ResourceManager::GetInstance().GetTexture("ladderBlock"));
	blockSprites[BlockType::LadderBottom] = sf::Sprite(*ResourceManager::GetInstance().GetTexture("ladderBlock"));
	blockSprites[BlockType::LadderTop] = sf::Sprite(*ResourceManager::GetInstance().GetTexture("ladderBlock"));
	blockSprites[BlockType::Liquid] = sf::Sprite(*ResourceManager::GetInstance().GetTexture("waterBlock"));
	blockSprites[BlockType::LiquidTop] = sf::Sprite(*ResourceManager::GetInstance().GetTexture("waterBlock"));
}

////////////////////////////////////////////////////////////////////////

void Grid::Save(string fileName)
{
	sf::Image gridImage;
	gridImage.create(dimensions.x, dimensions.y, sf::Color::White);

	for (int column = 0; column < dimensions.x; column++)
	{
		for (int row = 0; row < dimensions.y; row++)
		{
			gridImage.setPixel(column, row, BlockTypeToColor(blocks[column][row]));
		}
	}                                 

	gridImage.saveToFile(resourcePath() + fileName);
}

////////////////////////////////////////////////////////////////////////

sf::Color Grid::BlockTypeToColor(BlockType blockType)
{
	switch (blockType)
	{
	case Empty:
		return sf::Color::White;
	case Solid:
		return sf::Color::Black;
	case Liquid:
		return sf::Color::Blue;
	case LiquidTop:
		return sf::Color(123, 12, 67, 255);
	case Ladder:
		return sf::Color(185, 122, 87, 255);
	case LadderTop:
		return sf::Color(90, 56, 37, 255);
	case LadderBottom:
		return sf::Color(213, 174, 153, 255);
	case Corner:
		return sf::Color(128, 128, 128, 255);
	case Platform:
		return sf::Color::Red;
	default:
		return sf::Color::White;
	}
}

////////////////////////////////////////////////////////////////////////

BlockType Grid::ColorToBlockType(sf::Color color)
{
	if (color == sf::Color::White)
	{
		return BlockType::Empty;
	}
	else if (color == sf::Color::Black)
	{
		return BlockType::Solid;
	}
	else if (color == sf::Color::Blue)
	{
		return BlockType::Liquid;
	}
	else if (color == sf::Color(123, 12, 67, 255))
	{
		return BlockType::LiquidTop;
	}
	else if (color == sf::Color(185, 122, 87, 255))
	{
		return BlockType::Ladder;
	}
	else if (color == sf::Color(90, 56, 37, 255))
	{
		return BlockType::LadderTop;
	}
	else if (color == sf::Color(213, 174, 153, 255))
	{
		return BlockType::LadderBottom;
	}
	else if (color == sf::Color(128, 128, 128, 255))
	{
		return BlockType::Corner;
	}
	else if (color == sf::Color::Red)
	{
		return BlockType::Platform;
	}

	return BlockType::Empty;
}

////////////////////////////////////////////////////////////////////////

int Grid::LayoutNodeIndexToBlockIndex(int index, int nodeSize)
{
	return (index * (nodeSize + 1)) + 1;
}

////////////////////////////////////////////////////////////////////////

sf::Vector2f Grid::LayoutNodePositionToBlockPosition(sf::Vector2i position, int nodeSize)
{
	sf::Vector2i gridIndex = sf::Vector2i(LayoutNodeIndexToBlockIndex(position.x, nodeSize), LayoutNodeIndexToBlockIndex(position.y, nodeSize));
	return GetBlockPosition(gridIndex.x, gridIndex.y);
}

////////////////////////////////////////////////////////////////////////

sf::Vector2f Grid::LayoutNodeSizeToGridSize(sf::Vector2i size, int nodeSize)
{
	return sf::Vector2f(((size.x * (nodeSize + 1) - 1) * blockSize.x) - 1, ((size.y * (nodeSize + 1) - 1) * blockSize.y) - 1);
}



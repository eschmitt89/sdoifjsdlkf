#ifndef Grid_hpp
#define Grid_hpp

#include <SFML/Graphics.hpp>
#include "Block.hpp"
#include "Camera.hpp"
#include "Utilities.hpp"
#include "BlockNeighbors.hpp"
#include <vector>
#include <map>

using namespace std;

class Grid
{
public:
    Grid(int columns, int rows, int blockWidth, int blockHeight);
	Grid(string fileName, int blockWidth, int blockHeight);
    ~Grid();
    
    void Draw(sf::RenderWindow& window, Camera* camera);

	sf::Vector2i GetDimensions();
	Block GetBlock(int column, int row);
	int GetBlockKey(int column, int row);
	BlockType GetBlockType(int column, int row);
	sf::Vector2f GetBlockPosition(int column, int row);
	sf::Vector2i GetBlockIndex(sf::Vector2f position);
	Vector4i GetBlockIndicies(sf::Vector2f position, sf::Vector2f size);
	BlockNeighbors GetBlockNeighbors(int column, int row);

	void SetBlockType(int column, int row, BlockType blockType);
	void SetBlockType(sf::Vector2i blockIndex, BlockType blockType);
	void SetBlockType(sf::Vector2f position, BlockType blockType);
	void SetBlockType(sf::Vector2f position, sf::Vector2f size, BlockType blockType);

	bool IsValidBlockIndex(int column, int row);
	bool IsValidBlockIndex(sf::Vector2i blockIndex);
	bool IsValidNonEmptyBlockIndex(int column, int row);

private:
    vector<vector<BlockType>> blocks;
	map<BlockType, sf::RectangleShape> blockTextures;
	sf::Vector2i dimensions;
	sf::Vector2f blockSize;
	sf::Vector2f size;

	void LoadBlockTextures();
	sf::RectangleShape LoadBlockTexture(string textureName);
	void Save(string fileName);

	sf::Color BlockTypeToColor(BlockType blockType);
	BlockType ColorToBlockType(sf::Color color);

	int LayoutNodeIndexToBlockIndex(int index, int nodeSize);
	sf::Vector2f LayoutNodePositionToBlockPosition(sf::Vector2i position, int nodeSize);
	sf::Vector2f LayoutNodeSizeToGridSize(sf::Vector2i size, int nodeSize);
};

#endif /* Grid_hpp */

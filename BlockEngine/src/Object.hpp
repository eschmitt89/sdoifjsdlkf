//
//  Object.hpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <SFML/Graphics.hpp>

class Object
{
public:
	Object(sf::Texture& texture, sf::Vector2f position, sf::Vector2f size);
    ~Object();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

	void SetSize(sf::Vector2f size);
    
protected:
	sf::Sprite sprite;
	sf::Vector2f size;
};

#endif /* Object_hpp */
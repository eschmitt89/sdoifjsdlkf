//
//  AbstractScreen.hpp
//  BlockEngine
//
//  Created by Eric Schmitt on 3/2/17.
//  Copyright © 2017 Eric Schmitt. All rights reserved.
//

#ifndef AbstractScreen_hpp
#define AbstractScreen_hpp

#include <SFML/Graphics.hpp>

using namespace std;

class AbstractScreen
{
public:
    AbstractScreen();
    virtual ~AbstractScreen();
    virtual bool DoesHandleInput();
    virtual void HandleInput(const sf::RenderWindow& window);
    virtual bool DoesUpdate();
    virtual void Update(float dt);
    virtual bool DoesDraw();
    virtual void Draw(const sf::RenderWindow& window);
    
private:
    
};

#endif /* AbstractScreen_hpp */

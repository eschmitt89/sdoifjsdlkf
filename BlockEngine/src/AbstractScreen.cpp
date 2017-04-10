#include "AbstractScreen.hpp"

AbstractScreen::AbstractScreen()
{
    
}

////////////////////////////////////////////////////////////////////////

AbstractScreen::~AbstractScreen()
{

}

////////////////////////////////////////////////////////////////////////

bool AbstractScreen::DoesHandleInput()
{
    return true;
}

////////////////////////////////////////////////////////////////////////

void AbstractScreen::HandleInput(const sf::RenderWindow &window)
{
    
}

////////////////////////////////////////////////////////////////////////

bool AbstractScreen::DoesUpdate()
{
    return true;
}

////////////////////////////////////////////////////////////////////////

void AbstractScreen::Update(float dt)
{
    
}

////////////////////////////////////////////////////////////////////////

bool AbstractScreen::DoesDraw()
{
    return true;
}

////////////////////////////////////////////////////////////////////////

void AbstractScreen::Draw(sf::RenderWindow &window)
{
    
}

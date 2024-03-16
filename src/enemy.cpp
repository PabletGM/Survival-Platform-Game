#include "enemy.h"


enemy::enemy()
{
    
}

enemy::~enemy()
{
}



void enemy::update()
{
}

void enemy::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
    MoveSprite();
}

void enemy::MoveSprite()
{
    
}

void enemy::RotateSprite()
{
    
}

void enemy::ScaleSprite()
{

}
void enemy::ChangeOriginSprite()
{
   
}


void enemy::UpdateSprite(sf::RenderWindow& window)
{
    
}

void enemy::SetInitialPosition(Position p)
{
    
}

Position enemy::getPosition()
{
    return posEnemy;
}

sf::FloatRect enemy::getBoxColliderEnemy() const
{
    return spriteEnemy.getGlobalBounds();
}

void enemy::LoadTextureInit()
{

}



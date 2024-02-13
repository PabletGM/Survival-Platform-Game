#include "enemy.h"


enemy::enemy() : maxLife{ 3 }, actualLife{ 4 }, posXInit{ 0 }, posYInit{ 0 }
{
}

enemy::enemy( int posX, int posY): maxLife{3}, actualLife{4}, posXInit{0}, posYInit{0}
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
    // position
    //sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position
    spriteEnemy.move(sf::Vector2f(1, 0)); // offset relative to the current position
}

void enemy::RotateSprite()
{
    //// rotation
    //sprite.setRotation(90.f); // absolute angle
    //sprite.rotate(15.f); // offset relative to the current angle
}

void enemy::ScaleSprite()
{
    // scale
    spriteEnemy.setScale(sf::Vector2f(0.1f, 0.1f)); // absolute scale factor
    //sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale
}

void enemy::ChangeOriginSprite()
{
    //origen por defecto es el top-left esquina izquierda
    /*sprite.setOrigin(sf::Vector2f(25.f, 25.f));*/
}


void enemy::UpdateSprite(sf::RenderWindow& window)
{
    
}

void enemy::SetInitialPosition(int posXInit, int posYInit)
{
    
}

void enemy::LoadTextureInit()
{


    

}

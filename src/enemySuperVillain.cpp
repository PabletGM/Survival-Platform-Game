#include "enemySuperVillain.h"


enemySuperVillain::enemySuperVillain() : maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 0 }, dirYInit{ 1 }
{

}

enemySuperVillain::enemySuperVillain( Position param, limits limits) : maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 0 }, dirYInit{ 1 }
{
    limitsEnemy = limits;
    //cargas textura inicialmente
    LoadTextureInit();
    ScaleSprite();
    ChangeOriginSprite();
    //inicializamos variables de posicion
    p.posX = param.posX;
    p.posY = param.posY;
    //se inicia posicion de enemy
    SetInitialPosition(p);
}

void enemySuperVillain::update()
{
    MoveSprite();
}

void enemySuperVillain::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
    
}

void enemySuperVillain::MoveSprite()
{
    // position
     //sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position

     //move position con dirInit

    p.posX += dirXInit;
    p.posY += dirYInit;
    CheckLimits();
    // offset relative to the current position
    spriteEnemy.move(sf::Vector2f(dirXInit, dirYInit));
}

void enemySuperVillain::RotateSprite()
{
    //// rotation
    //sprite.setRotation(90.f); // absolute angle
    //sprite.rotate(15.f); // offset relative to the current angle
}

void enemySuperVillain::ScaleSprite()
{
    // scale
    spriteEnemy.setScale(sf::Vector2f(0.3f, 0.3f)); // absolute scale factor
    //sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale
}

//origen centro
void enemySuperVillain::ChangeOriginSprite()
{
    //origen por defecto es el top-left esquina izquierda
    spriteEnemy.setOrigin(sf::Vector2f(100.f, 100.f));
}


void enemySuperVillain::UpdateSprite(sf::RenderWindow& window)
{
    window.draw(spriteEnemy);
}

void enemySuperVillain::SetInitialPosition(Position p)
{
    spriteEnemy.move(sf::Vector2f(p.posX, p.posY));
}

void enemySuperVillain::ChangeXDirection()
{
    //change direction
    dirXInit *= -1;
    FlipSpriteX();

}

void enemySuperVillain::ChangeYDirection()
{
    dirYInit *= -1;
    FlipSpriteX();
}

void enemySuperVillain::CheckLimits()
{
    //CHECK LIMITS X size
    if (p.posX > limitsEnemy.limitDerecho || (p.posX < limitsEnemy.limitIzquierdo))
    {
        //out of limits
        ChangeXDirection();
    }
    //check limits YSize
    if (p.posY > limitsEnemy.limitAbajo || p.posY < limitsEnemy.limitArriba)
    {
        //out of limits
        ChangeYDirection();
    }
}

void enemySuperVillain::FlipSpriteX()
{
    spriteEnemy.scale(-1, 1);
}



void enemySuperVillain::LoadTextureInit()
{



    //carga de imagen del proyecto
    textureEnemy.loadFromFile("../sprites/enemy/supervillano.png");
    //le ponemos textura
    spriteEnemy.setTexture(textureEnemy);



}

#include "enemyVillain.h"


enemyVillain::enemyVillain() : maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 1 }, dirYInit{ 0 }
{

}

enemyVillain::enemyVillain(Position param, limits limits): maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 1 }, dirYInit{ 0 }
{
    limitsEnemy = limits;
    //cargas textura inicialmente
    LoadTextureInit();
    ScaleSprite();
    ChangeOriginSprite();
    //inicializamos variables de posicion
    p.posX= param.posX;
    p.posY = param.posY;
    //se inicia posicion de enemy
    SetInitialPosition(p);
}

//check if the enemy goes out of the limits to change the direction
void enemyVillain::update()
{
    MoveSprite();
}

void enemyVillain::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
    
}

void enemyVillain::MoveSprite()
{
    // position
    //sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position

    //move position con dirInit
    
    p.posX+=dirXInit;
    p.posY += dirYInit;
    CheckLimits();
    // offset relative to the current position
    spriteEnemy.move(sf::Vector2f(dirXInit, dirYInit)); 
    
}

void enemyVillain::RotateSprite()
{
    //// rotation
    //sprite.setRotation(90.f); // absolute angle
    //sprite.rotate(15.f); // offset relative to the current angle;
}

void enemyVillain::ScaleSprite()
{
    // scale
    spriteEnemy.setScale(sf::Vector2f(0.1f, 0.1f)); // absolute scale factor
    //sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale
}

void enemyVillain::ChangeOriginSprite()
{
    //origen por defecto es el top-left esquina izquierda
    spriteEnemy.setOrigin(sf::Vector2f(250.f, 250.f));
}


void enemyVillain::UpdateSprite(sf::RenderWindow& window)
{
    window.draw(spriteEnemy);
}

void enemyVillain::SetInitialPosition(Position p)
{
    spriteEnemy.move(sf::Vector2f(p.posX,p.posY));
}

void enemyVillain::ChangeXDirection()
{
    //change direction
    dirXInit *= -1;
    FlipSpriteX();
    
}

void enemyVillain::ChangeYDirection()
{
    dirYInit *= -1;
    FlipSpriteX();
}

void enemyVillain::CheckLimits()
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

void enemyVillain::FlipSpriteX()
{
    spriteEnemy.scale(-1, 1);
}


void enemyVillain::LoadTextureInit()
{



    //carga de imagen del proyecto
    textureEnemy.loadFromFile("../sprites/enemy/villano.png");
    //le ponemos textura
    spriteEnemy.setTexture(textureEnemy);

    


}

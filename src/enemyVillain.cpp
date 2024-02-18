#include "enemyVillain.h"


enemyVillain::enemyVillain() : maxLife{ 3 }, actualLife{ 4 }, posXInit{ 0 }, posYInit{ 0 }, dirXInit{ 1 }, dirYInit{ 0 }, limitOffsetX{ 30 }, limitOffsetY{ 30 }
{

}

enemyVillain::enemyVillain(int posX, int posY): maxLife{ 3 }, actualLife{ 4 }, posXInit{ 0 }, posYInit{0}, dirXInit{ 1 }, dirYInit{ 0 }, limitOffsetX{ 30 }, limitOffsetY{ 30 }
{
    //cargas textura inicialmente
    LoadTextureInit();
    ScaleSprite();
    //inicializamos variables de posicion
    posXInit = posX;
    posYInit = posY;
    //se inicia posicion de enemy
    SetInitialPosition(posX, posY);
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
    
    posXInit+=dirXInit;
    posYInit += dirYInit;
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
    /*sprite.setOrigin(sf::Vector2f(25.f, 25.f));*/
}


void enemyVillain::UpdateSprite(sf::RenderWindow& window)
{
    window.draw(spriteEnemy);
}

void enemyVillain::SetInitialPosition(int posXInit, int posYInit)
{
    spriteEnemy.move(sf::Vector2f(posXInit, posYInit));
}

void enemyVillain::ChangeXDirection()
{
    //change direction
    dirXInit *= -1;
    
}

void enemyVillain::ChangeYDirection()
{
    dirYInit *= -1;
}

void enemyVillain::CheckLimits()
{
    //CHECK LIMITS X size
    if (posXInit > 1920 - limitOffsetX*2 || (posXInit < limitOffsetX))
    {
        //out of limits
        ChangeXDirection();
    }
    //check limits YSize
    if (posYInit > 1080 - limitOffsetY*2 || posYInit < 0)
    {
        //out of limits
        ChangeYDirection();
    }
}

void enemyVillain::LoadTextureInit()
{


    ////dibujamos pelota
    //sf::CircleShape shape(300.f);
    ////le pones un color a la forma
    //shape.setFillColor(sf::Color::Green);
    ////haces metodo dibujar
    //window.setFramerateLimit(144);
    //window.draw(shape);


    //carga de imagen del proyecto
    textureEnemy.loadFromFile("../sprites/enemy/villano.png");
    //le ponemos textura
    spriteEnemy.setTexture(textureEnemy);

    


}

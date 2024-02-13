#include "enemySuperVillain.h"


enemySuperVillain::enemySuperVillain() : maxLife{ 3 }, actualLife{ 4 }, posXInit{ 0 }, posYInit{ 0 }
{

}

enemySuperVillain::enemySuperVillain( int posX, int posY) : maxLife{ 3 }, actualLife{ 4 }, posXInit{ 0 }, posYInit{ 0 }
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

void enemySuperVillain::update()
{
}

void enemySuperVillain::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
    MoveSprite();
}

void enemySuperVillain::MoveSprite()
{
    // position
    //sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position
    spriteEnemy.move(sf::Vector2f(1, 0)); // offset relative to the current position
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

void enemySuperVillain::ChangeOriginSprite()
{
    //origen por defecto es el top-left esquina izquierda
    /*sprite.setOrigin(sf::Vector2f(25.f, 25.f));*/
}


void enemySuperVillain::UpdateSprite(sf::RenderWindow& window)
{
    window.draw(spriteEnemy);
}

void enemySuperVillain::SetInitialPosition(int posXInit, int posYInit)
{
    spriteEnemy.move(sf::Vector2f(posXInit, posYInit));
}

void enemySuperVillain::LoadTextureInit()
{


    ////dibujamos pelota
    //sf::CircleShape shape(300.f);
    ////le pones un color a la forma
    //shape.setFillColor(sf::Color::Green);
    ////haces metodo dibujar
    //window.setFramerateLimit(144);
    //window.draw(shape);


    //carga de imagen del proyecto
    textureEnemy.loadFromFile("../sprites/enemy/supervillano.png");
    //le ponemos textura
    spriteEnemy.setTexture(textureEnemy);



}

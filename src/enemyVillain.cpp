#include "enemyVillain.h"
#include <ObjectPooler.h>
#include <iostream>


enemyVillain::enemyVillain() : maxLife{ 3 }, actualLife{ 3 }, dirXInit{ 1 }, dirYInit{ 0 },animacionVector(0.0f, 0.0f),
frameWidth{ 157 }, frameHeight{ 192 }
{

}

enemyVillain::enemyVillain(Position param, limits limits): maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 1 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{157}, frameHeight{192}
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

enemyVillain::~enemyVillain()
{
}

//check if the enemy goes out of the limits to change the direction
void enemyVillain::update()
{
    if (this != nullptr)
    {
        //comprobamos si hay colisiones con alguna bala
        bool estado = ObjectPooler::getInstance().checkPositionCollisionEnemyVillain(getBoxColliderEnemy());
        if (estado)
        {
            DeathEnemy();
            
        }
        else
        {
            MoveSprite();
        }
    }
    
    

}

sf::FloatRect enemyVillain::getBoxColliderEnemy() const
{
    return spriteEnemy.getGlobalBounds();
}

void enemyVillain::render(sf::RenderWindow& window)
{
    if (this != nullptr)
    {
        UpdateSprite(window);
    }
    
}

void enemyVillain::DeathEnemy()
{
    std::cout << "Enemigo muerto";
    muerto = true;
   /* ObjectPooler::getInstance().DeleteEnemyVillain(this);*/
}

void enemyVillain::ChangeAnimationTime()
{
    sf::Time tiempoTranscurrido = cronometro.getElapsedTime();

    if (tiempoTranscurrido >= tiempoDeseado) {
        // Se ha alcanzado el tiempo deseado, ejecuta la función y reinicia el cronómetro
        UpdateAnimation();
        cronometro.restart();
    }
}

void enemyVillain::UpdateAnimation()
{
    //hacemos comprobacion de si ha llegado al ultimo sprite de animacion, o si se ha pasado del tamaño de la textura
    if (animacionVector.x * frameWidth >= textureEnemy.getSize().x)
    {
        //reiniciamos animacion
        animacionVector.x = 0;
    }
    // Define el rectángulo de la animación actual usando animacionVector.x * frameWidth para elegir cuadro animacion
    //en horizontal, en vertical no hay por eso es 0, y tamaño de un sprite en vertical y horizontal
    spriteEnemy.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
    //sumamos 1 sprite
    animacionVector.x++;
}

void enemyVillain::MoveSprite()
{
    // position
    //sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position

    //move position con dirInit
    
    p.posX +=dirXInit;
    p.posY += dirYInit;
    CheckLimits();
    // offset relative to the current position
    spriteEnemy.setPosition(sf::Vector2f(p.posX, p.posY)); 
    
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
    spriteEnemy.setScale(sf::Vector2f(0.5f, 0.5f)); // absolute scale factor
    //sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale
}

void enemyVillain::ChangeOriginSprite()
{
    //origen por defecto es el top-left esquina izquierda
    spriteEnemy.setOrigin(sf::Vector2f(75.f, 90.f));
}


void enemyVillain::UpdateSprite(sf::RenderWindow& window)
{
    ChangeAnimationTime();
    window.draw(spriteEnemy);
}

void enemyVillain::SetInitialPosition(Position p)
{
    spriteEnemy.setPosition(sf::Vector2f(p.posX,p.posY));
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
    textureEnemy.loadFromFile("../sprites/enemy/andandoVillano.png");
    //le ponemos textura
    spriteEnemy.setTexture(textureEnemy);
    spriteEnemy.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
}

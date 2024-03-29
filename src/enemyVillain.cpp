#include "enemyVillain.h"
#include <ObjectPooler.h>
#include <iostream>


enemyVillain::enemyVillain() : maxLife{ 3 }, actualLife{ 3 }, dirXInit{ 1 }, dirYInit{ 0 },animacionVector(0.0f, 0.0f),
frameWidth{ 157 }, frameHeight{ 192 }
{

}

//constructor initialise enemy normal
enemyVillain::enemyVillain(Position param, limits limits): maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 1 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{157}, frameHeight{192}
{
    limitsEnemy = limits;
    //cargas textura inicialmente
    LoadTextureInit();
    ScaleSprite();
    ChangeOriginSprite();
    //inicializamos variables de posicion
    posEnemy.posX= param.posX;
    posEnemy.posY = param.posY;
    //se inicia posicion de enemy
    SetInitialPosition(posEnemy);
}

enemyVillain::~enemyVillain()
{
}
//update pos enemy and bullets 
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

//collider enemy
sf::FloatRect enemyVillain::getBoxColliderEnemy() const
{
    return spriteEnemy.getGlobalBounds();
}

//render enemy normal
void enemyVillain::render(sf::RenderWindow& window)
{
    if (this != nullptr)
    {
        UpdateSprite(window);
    }
}

//death enemy
void enemyVillain::DeathEnemy()
{
    std::cout << "Enemigo muerto";
    muerto = true;
   /* ObjectPooler::getInstance().DeleteEnemyVillain(this);*/
}

Position enemyVillain::getPosition()
{
   return posEnemy;
}

//animation enemy change each tiempoDeseado time
void enemyVillain::ChangeAnimationTime()
{
    sf::Time tiempoTranscurrido = cronometro.getElapsedTime();

    if (tiempoTranscurrido >= tiempoDeseado) {
        // Se ha alcanzado el tiempo deseado, ejecuta la funci�n y reinicia el cron�metro
        UpdateAnimation();
        cronometro.restart();
    }
}

//animacion vector enemyVillain
void enemyVillain::UpdateAnimation()
{
    //hacemos comprobacion de si ha llegado al ultimo sprite de animacion, o si se ha pasado del tama�o de la textura
    if (animacionVector.x * frameWidth >= textureEnemy.getSize().x)
    {
        //reiniciamos animacion
        animacionVector.x = 0;
    }
    // Define el rect�ngulo de la animaci�n actual usando animacionVector.x * frameWidth para elegir cuadro animacion
    //en horizontal, en vertical no hay por eso es 0, y tama�o de un sprite en vertical y horizontal
    spriteEnemy.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
    //sumamos 1 sprite
    animacionVector.x++;
}

//move sprite enemyVillain
void enemyVillain::MoveSprite()
{
    //move position con dirInit 
    posEnemy.posX +=dirXInit;
    posEnemy.posY += dirYInit;
    CheckLimits();
    // offset relative to the current position
    spriteEnemy.setPosition(sf::Vector2f(posEnemy.posX, posEnemy.posY)); 
}


void enemyVillain::RotateSprite()
{

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

//check limits to turn around to the other side
void enemyVillain::CheckLimits()
{
    //CHECK LIMITS X size
    if (posEnemy.posX > limitsEnemy.limitDerecho || (posEnemy.posX < limitsEnemy.limitIzquierdo))
    {
        //out of limits
        ChangeXDirection();
    }
    //check limits YSize
    if (posEnemy.posY > limitsEnemy.limitAbajo || posEnemy.posY < limitsEnemy.limitArriba)
    {
        //out of limits
        ChangeYDirection();
    }
}

void enemyVillain::FlipSpriteX()
{
    spriteEnemy.scale(-1, 1);
}


//load texture
void enemyVillain::LoadTextureInit()
{
    //carga de imagen del proyecto
    textureEnemy.loadFromFile("../sprites/enemy/andandoVillano.png");
    //le ponemos textura
    spriteEnemy.setTexture(textureEnemy);
    spriteEnemy.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
}

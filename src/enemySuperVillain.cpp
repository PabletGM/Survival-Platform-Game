#include "enemySuperVillain.h"
#include <ObjectPooler.h>


enemySuperVillain::enemySuperVillain() : maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 0 }, dirYInit{ 1 }, animacionVector(0.0f, 0.0f)
,frameWidth{132}, frameHeight{139}
{

}

enemySuperVillain::~enemySuperVillain()
{
}

enemySuperVillain::enemySuperVillain( Position param, limits limits) : maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 0 }, dirYInit{ 1 }, animacionVector(0.0f, 0.0f)
, frameWidth{ 132 }, frameHeight{ 139 }
{
    limitsEnemy = limits;
    //cargas textura inicialmente
    LoadTextureInit();
    ScaleSprite();
    ChangeOriginSprite();
    //inicializamos variables de posicion
    posEnemy.posX = param.posX;
    posEnemy.posY = param.posY;
    //se inicia posicion de enemy
    SetInitialPosition(posEnemy);

    
    
}

void enemySuperVillain::update()
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

void enemySuperVillain::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
    
}

void enemySuperVillain::DeathEnemy()
{
    muerto = true;

}

Position enemySuperVillain::getPosition()
{
    return posEnemy;
}


void enemySuperVillain::ChangeAnimationTime()
{
        sf::Time tiempoTranscurrido = cronometro.getElapsedTime();

        if (tiempoTranscurrido >= tiempoDeseado) {
            // Se ha alcanzado el tiempo deseado, ejecuta la función y reinicia el cronómetro
            UpdateAnimation();
            cronometro.restart();
        }

        // Resto de la lógica de tu aplicación
    
}

void enemySuperVillain::UpdateAnimation()
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



void enemySuperVillain::MoveSprite()
{
    // position
     //sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position

     //move position con dirInit

    posEnemy.posX += dirXInit;
    posEnemy.posY += dirYInit;
    CheckLimits();
    // offset relative to the current position
    spriteEnemy.setPosition(sf::Vector2f(posEnemy.posX, posEnemy.posY));
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
    spriteEnemy.setScale(sf::Vector2f(0.6f, 0.6f)); // absolute scale factor
    //sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale
}

//origen centro
void enemySuperVillain::ChangeOriginSprite()
{
    //origen por defecto es el top-left esquina izquierda
    spriteEnemy.setOrigin(sf::Vector2f(65,65));
}


void enemySuperVillain::UpdateSprite(sf::RenderWindow& window)
{
    //comprobamos si ha pasado tiempo para cambiar sprite animacion
    ChangeAnimationTime();
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
    if (posEnemy.posX >= limitsEnemy.limitDerecho || (posEnemy.posX <= limitsEnemy.limitIzquierdo))
    {
        //out of limits
        ChangeXDirection();
    }
    //check limits YSize
    if (posEnemy.posY >= limitsEnemy.limitAbajo || posEnemy.posY <= limitsEnemy.limitArriba)
    {
        //out of limits
        ChangeYDirection();
    }
}

void enemySuperVillain::FlipSpriteX()
{
    spriteEnemy.scale(-1, 1);
}

sf::FloatRect enemySuperVillain::getBoxColliderEnemy() const
{
    return spriteEnemy.getGlobalBounds();
}



void enemySuperVillain::LoadTextureInit()
{



    //carga de imagen del proyecto
    textureEnemy.loadFromFile("../sprites/enemy/andandoSuperVillano.png");
    //le ponemos textura
    spriteEnemy.setTexture(textureEnemy);
    spriteEnemy.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));



}

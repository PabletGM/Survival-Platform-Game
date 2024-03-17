#include "shoot.h"
#include <gameManager.h>


//constructor
shoot::shoot() :  dirXInit{ 1 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{ 80 }, speed{5}
{

}

shoot::~shoot()
{
}

//constructor with load textures, scale and more functionality and initial direction
shoot::shoot(limits limits, Position position, bool directionRight) :  dirXInit{ 1 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{ 80 }, speed{5}
{
    //eliges direccion
    if (directionRight)
    {
        dirXInit = 1;
    }
    else
    {
        dirXInit = -1;
    }
    
    //cargas textura inicialmente
    LoadTextureInit();
    ScaleSprite();
    ChangeOriginSprite();
    
    
    //se inicia posicion de bala en player
    SetInitialPosition(position);
   
}

//move the enemy and death
void shoot::update()
{
    MoveSprite();
    //iniciar contador destruir bala
    Death();
}

//render sprite
void shoot::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
}


void shoot::ChangeAnimationTime()
{
    sf::Time tiempoTranscurrido = cronometro.getElapsedTime();

    if (tiempoTranscurrido >= tiempoDeseado) {
        // Se ha alcanzado el tiempo deseado, ejecuta la función y reinicia el cronómetro
        UpdateAnimation();
        cronometro.restart();
    }
}

//animation bullet changing texture
void shoot::UpdateAnimation()
{
    //hacemos comprobacion de si ha llegado al ultimo sprite de animacion, o si se ha pasado del tamaño de la textura
    if (animacionVector.x * frameWidth >= textureBala.getSize().x)
    {
        //reiniciamos animacion
        animacionVector.x = 0;
    }
    // Define el rectángulo de la animación actual usando animacionVector.x * frameWidth para elegir cuadro animacion
    //en horizontal, en vertical no hay por eso es 0, y tamaño de un sprite en vertical y horizontal
    spriteBala.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
    //sumamos 1 sprite
    animacionVector.x++;
}


//direction bullet and movement
void shoot::MoveSprite()
{
    // position
    //sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position

    //move position con dirInit
    int movementX = 0;
    if (dirXInit > 0)
    {
        movementX = dirXInit + speed;
    }
    else if(dirXInit < 0)
    {
        movementX = dirXInit - speed;
    }
    //si es 0 se coge direccion de player actual
    else if (dirXInit == 0)
    {
        if (gameManager::getInstance().directionRight)
        {
            movementX = dirXInit + speed;
        }
        else
        {
            movementX = dirXInit - speed;
        }
    }
    
    
    p.posX += movementX;
    p.posY += dirYInit;
    CheckLimits();
    // offset relative to the current position
    spriteBala.setPosition(sf::Vector2f(p.posX, p.posY));

}

void shoot::RotateSprite()
{
    
}

void shoot::ScaleSprite()
{
    // scale
    spriteBala.setScale(sf::Vector2f(1.0f, 1.0f)); // absolute scale factor
}

void shoot::ChangeOriginSprite()
{
    //origen por defecto es el top-left esquina izquierda
    spriteBala.setOrigin(spriteBala.getLocalBounds().width / 2, spriteBala.getLocalBounds().height / 2);
}


void shoot::UpdateSprite(sf::RenderWindow& window)
{
    ChangeAnimationTime();
    window.draw(spriteBala);
}

void shoot::SetInitialPosition(Position position)
{
    p = position;
    spriteBala.setPosition(sf::Vector2f(p.posX, p.posY));
}

void shoot::ChangeXDirection()
{
    //change direction
    dirXInit *= -1;
    FlipSpriteX();

}

void shoot::ChangeYDirection()
{
    dirYInit *= -1;
    FlipSpriteX();
}

void shoot::CheckLimits()
{
    
}

//change direction bullet
void shoot::FlipSpriteX()
{
    spriteBala.scale(-1, 1);
}

//position on player
void shoot::RestartPosShootEnPlayer()
{
    p= gameManager::getInstance().getPlayerPosition();
}

//collider bala
sf::FloatRect shoot::getBoxColliderBala() const
{
    return spriteBala.getGlobalBounds();
}

//restart direction
void shoot::RestartDirShootEnPlayer()
{
    dirXInit = 0;

}




void shoot::LoadTextureInit()
{
    //carga de imagen del proyecto
    textureBala.loadFromFile("../sprites/bullet/bullet.png");
    //le ponemos textura
    spriteBala.setTexture(textureBala);
    spriteBala.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
}

void shoot::Death()
{
    sf::Time tiempo = cronometroDeath.getElapsedTime();

    if (tiempo >= timeDeath)
    {
        cronometroDeath.restart();

        //ponemos pos bala en player pos
        RestartPosShootEnPlayer();
        //destruir bala
        ObjectPooler::getInstance().DevolverBala(this);
    }
   
}

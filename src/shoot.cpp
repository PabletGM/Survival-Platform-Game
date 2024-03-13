#include "shoot.h"


shoot::shoot() :  dirXInit{ 1 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{ 80 }
{

}

shoot::shoot(limits limits, Position p) :  dirXInit{ 1 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{ 80 }
{
    
    //cargas textura inicialmente
    LoadTextureInit();
    ScaleSprite();
    ChangeOriginSprite();
    
    //se inicia posicion de enemy
    SetInitialPosition(p);
}

//check if the enemy goes out of the limits to change the direction
void shoot::update()
{
    MoveSprite();
}

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

void shoot::MoveSprite()
{
    // position
    //sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position

    //move position con dirInit

    p.posX += dirXInit;
    p.posY += dirYInit;
    CheckLimits();
    // offset relative to the current position
    spriteBala.move(sf::Vector2f(dirXInit, dirYInit));

}

void shoot::RotateSprite()
{
    //// rotation
    //sprite.setRotation(90.f); // absolute angle
    //sprite.rotate(15.f); // offset relative to the current angle;
}

void shoot::ScaleSprite()
{
    // scale
    spriteBala.setScale(sf::Vector2f(0.5f, 0.5f)); // absolute scale factor
    //sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale
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
    p.posX = position.posX;
    p.posY = position.posY;
    spriteBala.move(sf::Vector2f(p.posX, p.posY));
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
    ////CHECK LIMITS X size
    //if (p.posX > limitsEnemy.limitDerecho || (p.posX < limitsEnemy.limitIzquierdo))
    //{
    //    //out of limits
    //    ChangeXDirection();
    //}
    ////check limits YSize
    //if (p.posY > limitsEnemy.limitAbajo || p.posY < limitsEnemy.limitArriba)
    //{
    //    //out of limits
    //    ChangeYDirection();
    //}
}

void shoot::FlipSpriteX()
{
    spriteBala.scale(-1, 1);
}


void shoot::LoadTextureInit()
{
    //carga de imagen del proyecto
    textureBala.loadFromFile("../sprites/bullet/bullet.png");
    //le ponemos textura
    spriteBala.setTexture(textureBala);
    spriteBala.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
}

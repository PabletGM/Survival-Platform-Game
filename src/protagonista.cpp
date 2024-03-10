#include "protagonista.h"

protagonista::protagonista() : maxLife { 3 }, actualLife{ 3 }, dirXInit{ -1 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{ 80 }
{
}

protagonista::protagonista(Position param, limits limits) : maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 1 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{80 }
{
    limitsPlayer = limits;
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

void protagonista::update()
{
    MoveSprite();
}

void protagonista::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
}

void protagonista::ChangeAnimationTime()
{
    sf::Time tiempoTranscurrido = cronometro.getElapsedTime();

    if (tiempoTranscurrido >= tiempoDeseado) {
        // Se ha alcanzado el tiempo deseado, ejecuta la función y reinicia el cronómetro
        UpdateAnimation();
        cronometro.restart();
    }
}

bool protagonista::MovementTime()
{
    sf::Time tiempo = cronometroMovement.getElapsedTime();

    if (tiempo >= movementSpeed)
    {
        cronometroMovement.restart();
        return true;
    }
    else
    {
        return false;
    }
}

void protagonista::UpdateAnimation()
{
    //hacemos comprobacion de si ha llegado al ultimo sprite de animacion, o si se ha pasado del tamaño de la textura
    if (animacionVector.x * frameWidth >= texturePlayer.getSize().x)
    {
        //reiniciamos animacion
        animacionVector.x = 0;
    }
    // Define el rectángulo de la animación actual usando animacionVector.x * frameWidth para elegir cuadro animacion
    //en horizontal, en vertical no hay por eso es 0, y tamaño de un sprite en vertical y horizontal
    spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
    //sumamos 1 sprite
    animacionVector.x++;
}

void protagonista::MoveSprite()
{
    //to move 
    InputPlayer();  
}


void protagonista::ScaleSprite()
{
    spritePlayer.setScale(sf::Vector2f(1, 1));
}

void protagonista::ChangeOriginSprite()
{
    spritePlayer.setOrigin(sf::Vector2f(75.f, 90.f));
}

void protagonista::LoadTextureInit()
{
    //carga de imagen del proyecto
    texturePlayer.loadFromFile("../sprites/player/MovingPlayer.png");
    //le ponemos textura
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
}

void protagonista::UpdateSprite(sf::RenderWindow& window)
{
    ChangeAnimationTime();
    window.draw(spritePlayer);
}

void protagonista::SetInitialPosition(Position p)
{
    spritePlayer.move(sf::Vector2f(p.posX, p.posY));
    FlipSpriteX();
}

void protagonista::ChangeXDirection()
{
    //change direction
    dirXInit *= -1;
    FlipSpriteX();
}

bool protagonista::CheckLimits()
{
    //CHECK LIMITS X size
    if (p.posX > limitsPlayer.limitDerecho || (p.posX < limitsPlayer.limitIzquierdo))
    {
        //out of limits
        return false;
       
    }
    //if its in the limits
    else
    {
        
        return true;
    }

}

void protagonista::FlipSpriteX()
{
    spritePlayer.scale(-1, 1);
}

void protagonista::InputPlayer()
{
    //if left pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        // left key is pressed: move our character
        dirXInit = -1;

        bool readyToMove = MovementTime();
        //canMove y onLimits
        if ( readyToMove && p.posX  >= limitsPlayer.limitIzquierdo)
        {
            // offset relative to the current position
            p.posX += dirXInit;
            spritePlayer.move(sf::Vector2f(dirXInit, dirYInit));
        }
       
    }
    //if right pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // left key is pressed: move our character
        dirXInit = 1; 

        bool readyToMove = MovementTime();
        //canMove y onLimits
        if ( readyToMove && p.posX <= limitsPlayer.limitDerecho)
        {
            // offset relative to the current position
            p.posX += dirXInit;
            spritePlayer.move(sf::Vector2f(dirXInit, dirYInit));
        }
        
    }

    
}

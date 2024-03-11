#include "protagonista.h"

protagonista::protagonista() : maxLife { 3 }, actualLife{ 3 }, dirXInit{ -1 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{ 80 }, speed {2}
{
}

protagonista::protagonista(Position param, limits limits) : maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 0 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{80 }, speed {2}
{
    limitsPlayer = limits;
    //cargas textura inicialmente
    InitTextures();
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
    if(animacionVector.x * frameWidth >= texturePlayer.getSize().x)
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

void protagonista::InputMovePlayer()
{
    //if left pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        // left key is pressed: move our character
        dirXInit = -speed;
        //canMove y onLimits
        if (p.posX >= limitsPlayer.limitIzquierdo)
        {
            // offset relative to the current position
            p.posX += dirXInit;
            FlipSpriteLeft();
            spritePlayer.move(sf::Vector2f(dirXInit, dirYInit));
        }
    }
    //if right pressed
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // left key is pressed: move our character
        dirXInit = speed;

        //canMove y onLimits
        if (p.posX <= limitsPlayer.limitDerecho)
        {
            // offset relative to the current position
            p.posX += dirXInit;
            FlipSpriteRight();
            spritePlayer.move(sf::Vector2f(dirXInit, dirYInit));
        }
    }

    //sino se pulsa nada posicion idle
    else
    {
        IdleSprite();
        spritePlayer.move(sf::Vector2f(0,0));
    }
}

void protagonista::InputJumpPlayer()
{
    //si se pulsa space
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        
    }
}

void protagonista::Gravity()
{
    
    //check if surpass ground height
    if (spritePlayer.getPosition().y > groundHeight)
    {

    }
    else
    {
        //gravity
        //on each cicle a force push you down
        spritePlayer.move(sf::Vector2f(0, 1));
    }
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
    spritePlayer.setOrigin(spritePlayer.getLocalBounds().width / 2, spritePlayer.getLocalBounds().height / 2);
}

void protagonista::LoadTextureInit()
{
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
    IdleSprite();
}






void protagonista::FlipSpriteLeft()
{
    texturePlayer = texturePlayerMoveLeft;
    spritePlayer.setTexture(texturePlayer);
}

void protagonista::FlipSpriteRight()
{
    texturePlayer = texturePlayerMoveRight;
    spritePlayer.setTexture(texturePlayer);
   
}



void protagonista::IdleSprite()
{
    texturePlayer = texturePlayerIdle;
    spritePlayer.setTexture(texturePlayer);
}


void protagonista::InputPlayer()
{
    //apply gravity
    Gravity();

    bool readyToMove = MovementTime();
    if (readyToMove)
    {
        InputMovePlayer();
        InputJumpPlayer();
    }
    
}

void protagonista::InitTextures()
{
    //init texture idle
    texturePlayerIdle.loadFromFile("../sprites/player/playerIdle.png");
    //le ponemos textura
    spritePlayer.setTexture(texturePlayerIdle);
    spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));

    ////init texture right move
    texturePlayerMoveRight.loadFromFile("../sprites/player/MovingPlayerRight.png");
    //le ponemos textura
    spritePlayer.setTexture(texturePlayerMoveRight);
    spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));

    ////init texture left move
    texturePlayerMoveLeft.loadFromFile("../sprites/player/MovingPlayerLeft.png");
    //le ponemos textura
    spritePlayer.setTexture(texturePlayerMoveLeft);
    spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
}

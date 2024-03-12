#include "protagonista.h"
#include <iostream>


protagonista::protagonista() : maxLife { 3 }, actualLife{ 3 }, dirXInit{ -1 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{ 80 }, speed {2}, canJump{ true }
{
}

protagonista::protagonista(Position param, limits limits, std::vector<sf::FloatRect> boxColliders) : maxLife{ 3 }, actualLife{ 4 }, dirXInit{ 0 }, dirYInit{ 0 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{80 }, speed {2}, canJump{true}
{
    //sabemos las plataformas y su box collider
    boxCollidersPlatformArray = boxColliders;
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
    //collisions with platforms
    TakeFromMapArrayBoxColliders();
}

void protagonista::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
}

sf::FloatRect protagonista::getBoxColliderPlayer() const
{
    return spritePlayer.getGlobalBounds();
}

void protagonista::ChangeAnimationTime()
{
    sf::Time tiempoTranscurrido = cronometro.getElapsedTime();

    if (tiempoTranscurrido >= tiempoDeseado) {
        // Se ha alcanzado el tiempo deseado, ejecuta la funci�n y reinicia el cron�metro
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

bool protagonista::JumpTime()
{
    sf::Time tiempo = cronometroJump.getElapsedTime();

    //ha pasado el segundo de salto
    if (tiempo >= timeJump)
    {
        canJump = false;
        cronometroJump.restart();
        return true;
    }
    //seguimos en el aire
    else
    { 
        p.posY -= jumpForce;
        //se mueve hacia arriba
        spritePlayer.setPosition(sf::Vector2f(p.posX, p.posY));
        return false;
    }
}

void protagonista::UpdateAnimation()
{

    //hacemos comprobacion de si ha llegado al ultimo sprite de animacion, o si se ha pasado del tama�o de la textura
    if(animacionVector.x * frameWidth >= texturePlayer.getSize().x)
    {
        //reiniciamos animacion
        animacionVector.x = 0;
    }
    // Define el rect�ngulo de la animaci�n actual usando animacionVector.x * frameWidth para elegir cuadro animacion
    //en horizontal, en vertical no hay por eso es 0, y tama�o de un sprite en vertical y horizontal
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
        p.posX -= speed;
        //canMove y onLimits
        if (p.posX >= limitsPlayer.limitIzquierdo)
        {
            // offset relative to the current position

            FlipSpriteLeft();
            spritePlayer.setPosition(sf::Vector2f(p.posX, p.posY));
        }
    }
    //if right pressed
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // left key is pressed: move our character
        p.posX += speed;

        //canMove y onLimits
        if (p.posX <= limitsPlayer.limitDerecho)
        {
            // offset relative to the current position

            FlipSpriteRight();
            spritePlayer.setPosition(sf::Vector2f(p.posX, p.posY));
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
        //permiso para saltar
        if (canJump )
        {

            //si salto no ha acabado
            if (JumpTime())
            {
                
               
            }
           
        }
    }
}

void protagonista::Gravity()
{
    
    //check if surpass ground height o subido a plataforma
    if (spritePlayer.getPosition().y > groundHeight)
    {
        //damos permiso de salto
        canJump = true;
        InputJumpPlayer();
    }
    //si esta por encima del suelo gravedad
    else
    {
        //quitamos permiso de salto
        canJump = false;
        //gravity
        //on each cicle a force push you down
        p.posY += 1;
        spritePlayer.setPosition(sf::Vector2f(p.posX, p.posY));
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
    //apply gravity and Jump
    Gravity();

    bool readyToMove = MovementTime();
    if (readyToMove)
    {
        InputMovePlayer();
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

void protagonista::TakeFromMapArrayBoxColliders()
{
   //compare if the position of the player intersects one of the platforms
    for (int i = 0; i < 6;i++)
    {
        if (getBoxColliderPlayer().intersects(boxCollidersPlatformArray[i]))
        {
            std::cout << "Intersect" << std::endl;
            p.posY += -boxCollidersPlatformArray[i].height;
            spritePlayer.setPosition(sf::Vector2f(p.posX, p.posY));
            
        }
    }
}

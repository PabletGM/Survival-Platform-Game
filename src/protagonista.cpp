#include "protagonista.h"
#include <iostream>


protagonista::protagonista() : maxLife{ 3 }, actualLife{ 3 }, animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{ 80 }, speed{ 2 }, canJump{ true }, platformRider{ false }
{
}

protagonista::protagonista(Position param, limits limits, std::vector<sf::FloatRect> boxColliders, int numPlatforms) : maxLife{ 3 }, actualLife{ 4 },  animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{80 }, speed {2}, canJump{true}, platformRider{ false }
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
    //num platforms
    numPlatform = numPlatforms;

}

void protagonista::update()
{
    //collisions with platforms
    TakeFromMapArrayBoxColliders();
    //move sprite
    MoveSprite();
    spritePlayer.setPosition(sf::Vector2f(p.posX, p.posY));
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

bool protagonista::JumpTime()
{
        //salta
        p.posY -= jumpForce;
        return true;
    
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
        p.posX -= speed;
        //canMove y onLimits
        if (p.posX >= limitsPlayer.limitIzquierdo)
        {
            // offset relative to the current position

            FlipSpriteLeft();
            /*spritePlayer.setPosition(sf::Vector2f(p.posX, p.posY));*/
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
           /* spritePlayer.setPosition(sf::Vector2f(p.posX, p.posY));*/
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
    
    //si esta en el suelo o plataforma puede saltar
    if (spritePlayer.getPosition().y >= groundHeight || platformRider)
    {
        //damos permiso de salto
        canJump = true;
        InputJumpPlayer();
    }
    //si esta por encima del suelo y no esta en plataforma no puede saltar
    else if (spritePlayer.getPosition().y < groundHeight && !platformRider)
    {
        //quitamos permiso de salto
        canJump = false;
        //gravity APPLIED
        //on each cicle a force push you down
        p.posY += 1;
        /*spritePlayer.setPosition(sf::Vector2f(p.posX, p.posY));*/
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
    for (int i = 0; i < numPlatform;i++)
    {
        float alturaPlataforma = boxCollidersPlatformArray[i].getPosition().y +5;
        //si colisionan y altura player > altura platform
        if (getBoxColliderPlayer().intersects(boxCollidersPlatformArray[i]) && p.posY < alturaPlataforma)
        {
            std::cout << "Intersect" << std::endl;

            //posicion o altura de la plataforma
             p.posY = boxCollidersPlatformArray[i].getPosition().y - getBoxColliderPlayer().height/2;
            //subido a plataforma
            platformRider = true;
            //puede saltar
            canJump = true;

            return;
           
            
        }
        else
        {
            platformRider = false;
        }
    }
}

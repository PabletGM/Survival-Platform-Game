#include "protagonista.h"
#include <iostream>
#include <gameManager.h>




protagonista::protagonista()
{
}

protagonista::~protagonista()
{
}

protagonista::protagonista(Position param, limits limits, std::vector<sf::FloatRect> boxColliders, int numPlatforms) :   animacionVector(0.0f, 0.0f),
frameWidth{ 100 }, frameHeight{80 }, speed {2}, canJump{true}, platformRider{ false }
{
    //sabemos las plataformas y su box collider
    boxCollidersPlatformArray = boxColliders;
    limitsPlayer = limits;
    //cargas textura inicialmente
    InitTextures();
    LoadTextureInit();
    //scale sprite
    ScaleSprite();

    ChangeOriginSprite();
    //inicializamos variables de posicion and notify gameManager
    gameManager::getInstance().posPlayer.posX = param.posX;
    gameManager::getInstance().posPlayer.posY = param.posY;
    //se inicia posicion de enemy
    SetInitialPosition(gameManager::getInstance().posPlayer);
    //num platforms
    numPlatform = numPlatforms;



}

//check the collision with the platforms and move the player
void protagonista::update()
{
    //collisions with platforms
    TakeFromMapArrayBoxColliders();
    //move sprite
    MoveSprite();
    //spritePlatform
    gameManager::getInstance().spritePlayer.setPosition(sf::Vector2f(gameManager::getInstance().posPlayer.posX, gameManager::getInstance().posPlayer.posY));
}

Position protagonista::getPosition()
{
    return  gameManager::getInstance().posPlayer;
}

//render player
void protagonista::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
}
//collider player
sf::FloatRect protagonista::getBoxColliderPlayer() const
{
    return gameManager::getInstance().spritePlayer.getGlobalBounds();
}

//check if the player is dead
bool protagonista::playerIsDead()
{

    //despues de perder vida vemos si esta muerto

        return ObjectPooler::getInstance().playerIsDead(getBoxColliderPlayer());
    
    
}



void protagonista::LookToRight()
{
    gameManager::getInstance().directionRight = true;
    gameManager::getInstance().directionLeft = false;
}

void protagonista::LookToLeft()
{
    gameManager::getInstance().directionLeft = true;
    gameManager::getInstance().directionRight = false;
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

bool protagonista::CanShoot()
{
    sf::Time tiempo = recargaDisparo.getElapsedTime();

    if (tiempo >= timeCharge)
    {
        recargaDisparo.restart();
        canShoot = true; 
    }
    else
    {
        canShoot = false;
    }
    return canShoot;
}

bool protagonista::JumpTime()
{
        //salta
    gameManager::getInstance().posPlayer.posY -= jumpForce;
        return true;
    
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
    gameManager::getInstance().spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
    //sumamos 1 sprite
    animacionVector.x++;
}

void protagonista::InputMovePlayer()
{
    sf::Event event;



    //if left pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        // left key is pressed: move our character
        gameManager::getInstance().posPlayer.posX -= speed;
        //canMove y onLimits
        if (gameManager::getInstance().posPlayer.posX >= limitsPlayer.limitIzquierdo)
        {
            // offset relative to the current position
            
               FlipSpriteLeft();
               //miramos izquierda
               LookToLeft();
        }
    }
    //if right pressed
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // left key is pressed: move our character
        gameManager::getInstance().posPlayer.posX += speed;

        //canMove y onLimits
        if (gameManager::getInstance().posPlayer.posX <= limitsPlayer.limitDerecho)
        {
            // offset relative to the current position

            //sino esta en el aire, sino puede saltar
           
                FlipSpriteRight();
                //miramos izquierda
                LookToRight();

        }
    }
    //click derecho
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        //si mira a la derecha
        if (gameManager::getInstance().directionRight)
        {
            ShootSpriteDer();
        }
        else if (gameManager::getInstance().directionLeft)
        {
            // Acciones que deseas realizar al hacer clic derecho
            ShootSpriteIzq();
        }

        //bala, si puede disparar por tiempo de espera
        if (CanShoot())
        {
            InstantiateBala();
        }
        
    }

    //sino se pulsa nada posicion idle
    else
    {
        //si esta en el suelo o plataforma
        if (canJump || platformRider)
        {
            //si mira a la derecha
            if (gameManager::getInstance().directionRight)
            {
                IdleSpriteDer();
            }
            else if (gameManager::getInstance().directionLeft)
            {
                IdleSpriteIzq();
            }

           
        }
        gameManager::getInstance().spritePlayer.move(sf::Vector2f(0,0));
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
    if (gameManager::getInstance().spritePlayer.getPosition().y >= groundHeight || platformRider)
    {
        //damos permiso de salto
        canJump = true;

        InputJumpPlayer();
    }
    //si esta por encima del suelo y no esta en plataforma no puede saltar
    else if (gameManager::getInstance().spritePlayer.getPosition().y < groundHeight && !platformRider)
    {
        //quitamos permiso de salto
        canJump = false;
        //gravity APPLIED
        FallSprite();
        //on each cicle a force push you down
        gameManager::getInstance().posPlayer.posY += 1;
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
    gameManager::getInstance().spritePlayer.setScale(sf::Vector2f(1, 1));
}

void protagonista::ChangeOriginSprite()
{
    gameManager::getInstance().spritePlayer.setOrigin(gameManager::getInstance().spritePlayer.getLocalBounds().width / 2, gameManager::getInstance().spritePlayer.getLocalBounds().height / 2);
}

void protagonista::LoadTextureInit()
{
    //le ponemos textura
    gameManager::getInstance().spritePlayer.setTexture(texturePlayer);
    gameManager::getInstance().spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
}

void protagonista::UpdateSprite(sf::RenderWindow& window)
{
    ChangeAnimationTime();
    window.draw(gameManager::getInstance().spritePlayer);
}

void protagonista::SetInitialPosition(Position p)
{
    gameManager::getInstance().spritePlayer.move(sf::Vector2f(p.posX, p.posY));
    IdleSpriteIzq();
}






void protagonista::InstantiateBala()
{
    //y le pasamos la posicion del player
    ObjectPooler::getInstance().Disparar(gameManager::getInstance().posPlayer, gameManager::getInstance().directionRight);

}

void protagonista::FlipSpriteLeft()
{
    texturePlayer = texturePlayerMoveLeft;
    gameManager::getInstance().spritePlayer.setTexture(texturePlayer);
}

void protagonista::FlipSpriteRight()
{
    texturePlayer = texturePlayerMoveRight;
    gameManager::getInstance().spritePlayer.setTexture(texturePlayer);
   
}





void protagonista::IdleSpriteIzq()
{
    texturePlayer = texturePlayerIdleIzq;
    gameManager::getInstance().spritePlayer.setTexture(texturePlayer);
}

void protagonista::IdleSpriteDer()
{
    texturePlayer = texturePlayerIdleDer;
    gameManager::getInstance().spritePlayer.setTexture(texturePlayer);
}



void protagonista::FallSprite()
{
    texturePlayer = texturePlayerFall;
    gameManager::getInstance().spritePlayer.setTexture(texturePlayer);
}

void protagonista::ShootSpriteIzq()
{
    texturePlayer = texturePlayerShootIzq;
    gameManager::getInstance().spritePlayer.setTexture(texturePlayer);
}

void protagonista::ShootSpriteDer()
{
   texturePlayer = texturePlayerShootDer;
    gameManager::getInstance().spritePlayer.setTexture(texturePlayer);
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
    texturePlayerIdleIzq.loadFromFile("../sprites/player/playerIdleIzq.png");
    //le ponemos textura
    gameManager::getInstance().spritePlayer.setTexture(texturePlayerIdleIzq);
    gameManager::getInstance().spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));


    //init texture idle
    texturePlayerIdleDer.loadFromFile("../sprites/player/playerIdleDer.png");
    //le ponemos textura
    gameManager::getInstance().spritePlayer.setTexture(texturePlayerIdleDer);
    gameManager::getInstance().spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));

    ////init texture right move
    texturePlayerMoveRight.loadFromFile("../sprites/player/MovingPlayerRight.png");
    //le ponemos textura
    gameManager::getInstance().spritePlayer.setTexture(texturePlayerMoveRight);
    gameManager::getInstance().spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));

    ////init texture left move
    texturePlayerMoveLeft.loadFromFile("../sprites/player/MovingPlayerLeft.png");
    //le ponemos textura
    gameManager::getInstance().spritePlayer.setTexture(texturePlayerMoveLeft);
    gameManager::getInstance().spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));

    ////caer
    texturePlayerFall.loadFromFile("../sprites/player/playerCaer.png");
    //le ponemos textura
    gameManager::getInstance().spritePlayer.setTexture(texturePlayerFall);
    gameManager::getInstance().spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));

    ////shootIzq
    texturePlayerShootIzq.loadFromFile("../sprites/player/PlayerShootIzq.png");
    //le ponemos textura
    gameManager::getInstance().spritePlayer.setTexture(texturePlayerShootIzq);
    gameManager::getInstance().spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));

    ////shootDer
    texturePlayerShootDer.loadFromFile("../sprites/player/PlayerShootDer.png");
    //le ponemos textura
    gameManager::getInstance().spritePlayer.setTexture(texturePlayerShootDer);
    gameManager::getInstance().spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));

    //damage
   textureDamage.loadFromFile("../sprites/player/playerDamage.png");
    //le ponemos textura
    gameManager::getInstance().spritePlayer.setTexture(textureDamage);
    gameManager::getInstance().spritePlayer.setTextureRect(sf::IntRect(static_cast<int>(animacionVector.x) * frameWidth, 0, frameWidth, frameHeight));
}

void protagonista::TakeFromMapArrayBoxColliders()
{

   //compare if the position of the player intersects one of the platforms
    for (int i = 0; i < numPlatform;i++)
    {
        float alturaPlataforma = boxCollidersPlatformArray[i].getPosition().y +5;
        //si colisionan y altura player < altura platform(ya que el eje dereferencia es al reves en consola
        if (getBoxColliderPlayer().intersects(boxCollidersPlatformArray[i]) && gameManager::getInstance().posPlayer.posY <= alturaPlataforma)
        {
            /*std::cout << "Intersect" << std::endl;*/

            //posicion o altura de la plataforma
            gameManager::getInstance().posPlayer.posY = boxCollidersPlatformArray[i].getPosition().y - getBoxColliderPlayer().height/2.1;
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


void protagonista::DamageSprite()
{

    texturePlayer = textureDamage;
    gameManager::getInstance().spritePlayer.setTexture(textureDamage);

}


#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <position.h>
#include <screenSize.h>
#include <ObjectPooler.h>


class protagonista
{
public:
    //constructor by defect
    protagonista();
    ~protagonista();
    //constructor with arguments
    protagonista(Position p, limits limits, std::vector<sf::FloatRect> boxColliders, int numPlatforms);


    void update();

    //get player pos
    Position getPosition();

    void render(sf::RenderWindow& window);

    //box collider of player
    sf::FloatRect getBoxColliderPlayer() const;

    //check if it is dead
    bool playerIsDead();



private:

    //constats
    const float gravity = 1;
    const float groundHeight = 1000;
    const float jumpForce = 150;

    //numPlatforms map
    int numPlatform;


    
    //look to right or left with texture
    void LookToRight();
    void LookToLeft();


    //animation Vector parameter, in constructor
    sf::Vector2f animacionVector;

    //cronometro change animation player
    sf::Clock cronometro;
    sf::Time tiempoDeseado = sf::seconds(0.1f);

    //cronometer speed
    sf::Clock cronometroMovement;
    sf::Time movementSpeed = sf::seconds(0.001);

    //recarga Disparo
    sf::Clock recargaDisparo;
    sf::Time timeCharge = sf::seconds(0.5);

    //cronometro duracion salto
    sf::Clock cronometroJump;
    sf::Time timeJump = sf::seconds(1);

    //cronometro cambio de animacion
    void ChangeAnimationTime();
    bool MovementTime();

    //puede disparar o no
    bool CanShoot();


    bool JumpTime();
    void UpdateAnimation();
    void InputMovePlayer();
    void InputJumpPlayer();
    void Gravity();

    //dimensiones de cada cuadro de animacion
    int frameWidth;
    int frameHeight;

    float speed;

    //si esta en sueo o plataforma y puede saltar
    bool canJump;
    //si esta subido en una plataforma
    bool platformRider;

    bool canShoot = true;



    //metodos privados
    void MoveSprite();

    void ScaleSprite();
    void ChangeOriginSprite();
    void LoadTextureInit();
    void UpdateSprite(sf::RenderWindow& window);

    //pones todo inicialmente
    void SetInitialPosition(Position p);


    //instanciar bala
    void InstantiateBala();


    void FlipSpriteLeft();
    void FlipSpriteRight();

    void IdleSpriteIzq();
    void IdleSpriteDer();

    void FallSprite();
    void ShootSpriteIzq();
    void ShootSpriteDer();

    void InputPlayer();

    void InitTextures();

    void TakeFromMapArrayBoxColliders();

    //texture enemigo
    sf::Texture texturePlayerIdleIzq;
    sf::Texture texturePlayerIdleDer;
    sf::Texture texturePlayerMoveRight;
    sf::Texture texturePlayerMoveLeft;
    sf::Texture texturePlayerFall;
    sf::Texture texturePlayerShootIzq;
    sf::Texture texturePlayerShootDer;
    //sprite enemigo
    sf::Texture texturePlayer;
    sf::Texture textureDamage;

    void DamageSprite();

public:
    //posicionInicial


private:
    limits limitsPlayer;

    //array de box colliders de plataformas
    std::vector<sf::FloatRect> boxCollidersPlatformArray;



};
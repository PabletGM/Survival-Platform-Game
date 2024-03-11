#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <position.h>
#include <screenSize.h>

class protagonista
{
public:
    //constructor por defecto
    protagonista();
    protagonista(Position p, limits limits);


    void update();


    void render(sf::RenderWindow& window) ;


private:

    const float gravity = 1;
    const float groundHeight = 1000;


    //animation Vector parametro, en constructor
    sf::Vector2f animacionVector;

    //cronometro cambio animacion enemigos
    sf::Clock cronometro;
    sf::Time tiempoDeseado = sf::seconds(0.1f);

    //cronometro cambio animacion enemigos
    sf::Clock cronometroMovement;
    sf::Time movementSpeed = sf::seconds(0.001);

    //cronometro cambio de animacion
    void ChangeAnimationTime();
    bool MovementTime();
    void UpdateAnimation();
    void InputMovePlayer();
    void InputJumpPlayer();
    void Gravity();

    //dimensiones de cada cuadro de animacion
    int frameWidth;
    int frameHeight;

    float speed;

    //direction
    int dirXInit;
    int dirYInit;

    //metodos privados
    void MoveSprite();

    void ScaleSprite();
    void ChangeOriginSprite();
    void LoadTextureInit();
    void UpdateSprite(sf::RenderWindow& window);

    //pones todo inicialmente
    void SetInitialPosition(Position p);



    void FlipSpriteLeft();
    void FlipSpriteRight();

    void IdleSprite();

    void InputPlayer();

    void InitTextures();



    //vida
    int maxLife;
    int actualLife;



    //sprite enemigo
    sf::Sprite spritePlayer;
    sf::Texture texturePlayer;
    //texture enemigo
    sf::Texture texturePlayerIdle;
    sf::Texture texturePlayerMoveRight;
    sf::Texture texturePlayerMoveLeft;

    //posicionInicial
    Position p;

    limits limitsPlayer;

};
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

    //animation Vector parametro, en constructor
    sf::Vector2f animacionVector;

    //cronometro cambio animacion enemigos
    sf::Clock cronometro;
    sf::Time tiempoDeseado = sf::seconds(0.1f);

    //cronometro cambio de animacion
    void ChangeAnimationTime();
    void UpdateAnimation();

    //dimensiones de cada cuadro de animacion
    int frameWidth;
    int frameHeight;

    //direction
    int dirXInit;
    int dirYInit;

    //metodos privados
    void MoveSprite();
    void RotateSprite();
    void ScaleSprite();
    void ChangeOriginSprite();
    void LoadTextureInit();
    void UpdateSprite(sf::RenderWindow& window);

    //pones todo inicialmente
    void SetInitialPosition(Position p);

    //change X direction
    void ChangeXDirection();

    bool CheckLimits();

    void FlipSpriteX();

    void InputPlayer();



    //vida
    int maxLife;
    int actualLife;

    //sprite enemigo
    sf::Sprite spritePlayer;
    //texture enemigo
    sf::Texture texturePlayer;

    //posicionInicial
    Position p;

    limits limitsPlayer;

};
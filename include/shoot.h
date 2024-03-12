#pragma once
#include <SFML/Graphics.hpp>
#include <position.h>
#include <screenSize.h>
class shoot
{
public:
    //constructor por defecto
    shoot();
    shoot(limits limits, Position p);


    void update();


    void render(sf::RenderWindow& window);


private:

    //animation Vector parametro, en constructor
    sf::Vector2f animacionVector;

    //cronometro cambio animacion bala
    sf::Clock cronometro;
    sf::Time tiempoDeseado = sf::seconds(0.1f);

    //cronometro cambio de animacion
    void ChangeAnimationTime();
    void UpdateAnimation();
    //dimensiones de cada cuadro de animacion
    int frameWidth;
    int frameHeight;


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
    //change Y direction
    void ChangeYDirection();

    void CheckLimits();

    void FlipSpriteX();





    //sprite enemigo
    sf::Sprite spriteBala;
    //texture enemigo
    sf::Texture textureBala;

    //posicionInicial
    Position p;

};
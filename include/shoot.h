#pragma once
#include <SFML/Graphics.hpp>
#include <position.h>
#include <screenSize.h>

class shoot
{
public:
    //constructor por defecto
    shoot();
    ~shoot();
    shoot(limits limits, Position p, bool directionRight);


    void update();


    void render(sf::RenderWindow& window);


private:

    //animation Vector parameter, in constructor
    sf::Vector2f animacionVector;

    //cronometro change animation bullet
    sf::Clock cronometro;
    sf::Time tiempoDeseado = sf::seconds(0.1f);


    //cronometro duration deatch bullet
    sf::Clock cronometroDeath;
    sf::Time timeDeath = sf::seconds(3);

    

    //can die or not each 3 seconds
    void Death();

    //cronometer change animation
    void ChangeAnimationTime();
    //update animation
    void UpdateAnimation();
    //dimensions of each sprite
    int frameWidth;
    int frameHeight;

    //direction X and Y
    int dirXInit;
    int dirYInit;

    //private methods
    void MoveSprite();
    void RotateSprite();
    void ScaleSprite();
    void ChangeOriginSprite();
    void LoadTextureInit();
    void UpdateSprite(sf::RenderWindow& window);

    //initial pos
    void SetInitialPosition(Position p);

    //change X direction
    void ChangeXDirection();
    //change Y direction
    void ChangeYDirection();

    void CheckLimits();

    void FlipSpriteX();

public:
    //restart pos bullet on player when destroyed
    void RestartPosShootEnPlayer();
    void RestartDirShootEnPlayer();
    //box collider de bala
    sf::FloatRect getBoxColliderBala() const;

private:

    //sprite bullet
    sf::Sprite spriteBala;
    //texture enemy
    sf::Texture textureBala;
    sf::Texture textureNone;

    //por defecto inicializado a valor 5
    int speed;

public:
    //posicionInicial
    Position p;

};
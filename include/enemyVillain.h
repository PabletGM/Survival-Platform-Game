#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <position.h>
#include <screenSize.h>

//enemy class normal with sprite ghost
class enemyVillain: public enemy
{
    public:

        //constructor por defecto
        enemyVillain();
        enemyVillain( Position p,  limits limits);
        ~enemyVillain();

        void update() override;


        void render(sf::RenderWindow& window) override;

        //acgtivate death
        void DeathEnemy();

        Position getPosition();


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
        void MoveSprite() override;
        void RotateSprite() override;
        void ScaleSprite() override;
        void ChangeOriginSprite() override;
        void LoadTextureInit() override;
        void UpdateSprite(sf::RenderWindow& window) override;

        //pones todo inicialmente
        void SetInitialPosition(Position p) override;

        //change X direction
        void ChangeXDirection() override;
        //change Y direction
        void ChangeYDirection() override;

        void CheckLimits() override;

        void FlipSpriteX() override;


public:
        //box collider de enemy
        sf::FloatRect getBoxColliderEnemy() const;


private:

        //vida
        int maxLife;
        int actualLife;


        //texture enemigo
        sf::Texture textureEnemy;

        //posicionInicial
      

        

};
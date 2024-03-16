#pragma once
#include <SFML/Graphics.hpp>
#include <position.h>
#include <screenSize.h>

class enemy
{
    public:
        //constructor por defecto
        enemy();

        virtual void update() = 0;


        virtual void render(sf::RenderWindow& window) = 0;


        //metodos privados
        virtual void MoveSprite() = 0;
        virtual void RotateSprite()= 0;
        virtual void ScaleSprite() = 0;
        virtual void ChangeOriginSprite() = 0;
        virtual void LoadTextureInit() = 0;
        virtual void UpdateSprite(sf::RenderWindow& window) = 0;

        //pones todo inicialmente
       virtual void SetInitialPosition(Position p) = 0;

       //change X direction
       virtual void ChangeXDirection() = 0;
       //change Y direction
       virtual void ChangeYDirection() = 0;

       //check limits
       virtual void CheckLimits() = 0;

       //flip sprite in limit
       virtual void FlipSpriteX() = 0;


    public: 

        limits limitsEnemy;

        bool muerto = false;
        

};
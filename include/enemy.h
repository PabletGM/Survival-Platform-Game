#pragma once
#include <SFML/Graphics.hpp>

class enemy
{
    public:
        //constructor por defecto
        enemy();
        enemy( int posXInit, int posYInit);


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
       virtual void SetInitialPosition(int posX, int posY) = 0;

       //change X direction
       virtual void ChangeXDirection() = 0;
       //change Y direction
       virtual void ChangeYDirection() = 0;

       //check limits
       virtual void CheckLimits() = 0;

    protected: 

        

};
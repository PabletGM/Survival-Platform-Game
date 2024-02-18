#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
class enemyVillain: public enemy
{
    public:
        //constructor por defecto
        enemyVillain();
        enemyVillain( int posXInit, int posYInit);


        void update() override;


        void render(sf::RenderWindow& window) override;


    private:


        //limitOffset
        int limitOffsetX;
        int limitOffsetY;

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
        void SetInitialPosition(int posX, int posY) override;

        //change X direction
        void ChangeXDirection() override;
        //change Y direction
        void ChangeYDirection() override;

        void CheckLimits() override;

        //vida
        int maxLife;
        int actualLife;

        //sprite enemigo
        sf::Sprite spriteEnemy;
        //texture enemigo
        sf::Texture textureEnemy;

        //posicionInicial
        int posXInit;
        int posYInit;

};
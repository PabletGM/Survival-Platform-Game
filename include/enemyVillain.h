#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <position.h>
class enemyVillain: public enemy
{
    public:
        //constructor por defecto
        enemyVillain();
        enemyVillain( Position p,  int spaceXPlay, int spaceYPlay);


        void update() override;


        void render(sf::RenderWindow& window) override;


    private:




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

        //vida
        int maxLife;
        int actualLife;

        //sprite enemigo
        sf::Sprite spriteEnemy;
        //texture enemigo
        sf::Texture textureEnemy;

        //posicionInicial
        Position p;

};
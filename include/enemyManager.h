
#pragma once
#include <SFML/Graphics.hpp>
#include <enemy.h>


class enemyManager
{
    public:
        //constructor por defecto
        enemyManager();

        void update();


        void render(sf::RenderWindow& window);


    private:

        int numEnemiesTotal = 3;
        //array con enemigos
        enemy* enemiesInGame[3];
        

};
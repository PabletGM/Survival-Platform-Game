
#pragma once
#include <SFML/Graphics.hpp>
#include <enemy.h>


class enemyManager
{
    public:
        //constructor por defecto
        enemyManager(sf::RenderWindow& window);

        void update();


        void render(sf::RenderWindow& window);

        void CreateEnemies(sf::RenderWindow& window);


    private:

        int numEnemiesTotal;
        //array con enemigos
        enemy* enemiesInGame[6];
        std::vector<enemy*> m_enemies{};
        

};
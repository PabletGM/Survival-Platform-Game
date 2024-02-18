
#pragma once
#include <SFML/Graphics.hpp>
#include <enemy.h>


class enemyManager
{
    public:
        //constructor por defecto
        enemyManager(sf::RenderWindow& window);

        void update();

        //renderizar enemies
        void render(sf::RenderWindow& window);

        void CreateEnemies(sf::RenderWindow& window);


    private:

        int numEnemiesTotalVillain;
        int numEnemiesTotalSuperVillain;
        //array con enemigos
        std::vector<enemy*> m_enemies{};
        

};
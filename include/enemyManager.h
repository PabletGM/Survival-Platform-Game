
#pragma once
#include <SFML/Graphics.hpp>
#include <enemy.h>


class enemyManager
{
    public:
        //constructor por defecto
        enemyManager(sf::RenderWindow& window,limits  limits);

        void update();

        //renderizar enemies
        void render(sf::RenderWindow& window);

        void CreateEnemies(sf::RenderWindow& window, limits limits);
        void CreateSpawns();
        void CreateSpawnsSuperVillain();
        void CreateSpawnsVillain();


    private:

        int numEnemiesTotalVillain;
        int numEnemiesTotalSuperVillain;
        //array con enemigos
        std::vector<enemy*> m_enemies{};

        //spawns de enemySuperVillain
        static const int enemySuperSpawns = 3;
        Position spawnsEnemySuperVillain[enemySuperSpawns];

        //spawns de enemyVillain
        static const int enemySpawns = 3;
        Position spawnsEnemyVillain[enemySpawns];
        

};
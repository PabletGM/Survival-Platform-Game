
#pragma once
#include <SFML/Graphics.hpp>
#include <enemy.h>


class enemyManager
{
    public:
        //constructor por defecto
        enemyManager(sf::RenderWindow& window,limits  limits);
        ~enemyManager();
       

        void CreateEnemies(sf::RenderWindow& window, limits limits);
        

    public:

        int numEnemiesTotalVillain;
        int numEnemiesTotalSuperVillain;

        void CreateNewEnemy();

        void update();

        bool canSpawnEnemy();


    private:

        //cronometro spawn enemy
        sf::Clock cronometroSpawnEnemy;
        sf::Time tiempoDeseado = sf::seconds(2.0f);
        bool canSpawn = false;

        



        //singleton
public:
    // Constructor privado para evitar la creación de instancias
    enemyManager();
    // Variable estática que almacena la única instancia de ObjectPooler
    static enemyManager instance;
    static enemyManager& getInstance(); // Método para obtener la instancia singleton
        

};
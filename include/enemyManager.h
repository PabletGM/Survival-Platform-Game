
#pragma once
#include <SFML/Graphics.hpp>
#include <enemy.h>


class enemyManager
{
    public:
        //constructor por defecto
        enemyManager(sf::RenderWindow& window,limits  limits);

       

        void CreateEnemies(sf::RenderWindow& window, limits limits);
        

    public:

        int numEnemiesTotalVillain;
        int numEnemiesTotalSuperVillain;


        



        //singleton
public:
    // Constructor privado para evitar la creación de instancias
    enemyManager();
    // Variable estática que almacena la única instancia de ObjectPooler
    static enemyManager instance;
    static enemyManager& getInstance(); // Método para obtener la instancia singleton
        

};
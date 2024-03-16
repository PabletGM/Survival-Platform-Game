
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
    // Constructor privado para evitar la creaci�n de instancias
    enemyManager();
    // Variable est�tica que almacena la �nica instancia de ObjectPooler
    static enemyManager instance;
    static enemyManager& getInstance(); // M�todo para obtener la instancia singleton
        

};
#pragma once
#include <SFML/Graphics.hpp>
#include <enemyManager.h>
#include <protagonista.h>
#include <map.h>
#include <screenSize.h>
#include <gameManager.h>

//para tema de enemigos clase villano y supervillano hacer stateMachine con IA, buscar tutorial para los diferentes estados, perseguir, idle, buscar, etc
class Game
{
    public:
        //constructor por defecto
        Game(sf::RenderWindow& window, screenSize screen);


        void update(float deltaMS, sf::RenderWindow& window);
    

        void render(float deltaMS, sf::RenderWindow& window);
        

        //metodo con condiciones para salir del juego
        bool wantsExit();

        
        

    private:
        //enemyManager con todos los enemigos del juego
        enemyManager* m_enemyManager;
        //player del juego
        gameManager* m_gameManager;
        unsigned int spaceXPlayable;
        unsigned int spaceYPlayable;
        //limitOffset
        unsigned  int limitOffsetX;
        unsigned  int limitOffsetY;

        bool finishGame = false;

    public:
       



};
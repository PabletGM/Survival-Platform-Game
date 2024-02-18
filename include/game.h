#pragma once
#include <SFML/Graphics.hpp>
#include <enemyManager.h>
#include <protagonista.h>
#include <plataforma.h>
#include <screenSize.h>

//para tema de enemigos clase villano y supervillano hacer stateMachine con IA, buscar tutorial para los diferentes estados, perseguir, idle, buscar, etc
class Game
{
    public:
        //constructor por defecto
        Game(sf::RenderWindow& window, screenSize screen);


        void update(float deltaMS, sf::RenderWindow& window);
    

        void render(float deltaMS, sf::RenderWindow& window);
        

        //metodo con condiciones para salir del juego
        bool wantsExit()
        {
            return false;
        }

    private:
        //enemyManager con todos los enemigos del juego
        enemyManager* m_enemyManager;
        //player del juego
        protagonista* m_protagonista;
        //plataformas del juego, TO DO--> cambiar por mapa y que este dentro tenga un array de plataformas que se rendericen
        plataforma* m_plataforma;

        unsigned int spaceXPlayable;
        unsigned int spaceYPlayable;
        //limitOffset
        unsigned  int limitOffsetX;
        unsigned  int limitOffsetY;

    public:
       



};
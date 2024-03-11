#pragma once
#include <SFML/Graphics.hpp>
#include <protagonista.h>
#include <map.h>
#include <protagonista.h>
#include <screenSize.h>

//para tema de enemigos clase villano y supervillano hacer stateMachine con IA, buscar tutorial para los diferentes estados, perseguir, idle, buscar, etc
class gameManager
{
    public:
    //constructor por defecto
    gameManager(sf::RenderWindow& window, screenSize screenParam,unsigned int limitOffsetX, unsigned int limitOffsetY, unsigned int spaceXPlayable, unsigned int spaceYPlayable);


    void update(float deltaMS, sf::RenderWindow& window);


    void render(float deltaMS, sf::RenderWindow& window);


    

private:
   
    //player del juego
    protagonista* m_protagonista;
    //plataformas del juego, TO DO--> cambiar por mapa y que este dentro tenga un array de plataformas que se rendericen
    map* m_map;

    unsigned int spaceXPlayable;
    unsigned int spaceYPlayable;
    //limitOffset
    unsigned  int limitOffsetX;
    unsigned  int limitOffsetY;




};
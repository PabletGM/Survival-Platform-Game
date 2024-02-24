#include "game.h"


Game::Game(sf::RenderWindow& window, screenSize screenParam)
{
   
    //inicializamos pantalla con tamaño jugable
    limitOffsetX = 80;
    limitOffsetY = 80;
    spaceXPlayable = screenParam.screenSizeX - limitOffsetX;
    spaceYPlayable = screenParam.screenSizeY - limitOffsetY;
    //definimos espacio jugable
    limits limits{(spaceXPlayable),(limitOffsetX),(limitOffsetY),(spaceYPlayable) };
    //inicializar enemyManager
    m_enemyManager = new enemyManager(window, limits);
    m_map = new map();
    m_protagonista = new protagonista();
}


void Game::update(float deltaMS, sf::RenderWindow& window)
{
    //updating positions of enemies
    m_enemyManager->update();
        /* m_mainCharacter->update(deltaMS);
         m_enemyManager->update(deltaMS);*/
    
}

void Game::render(float deltaMS, sf::RenderWindow& window)
{
    
        window.clear();

        m_map->render(window);
        /*m_mainCharacter->render();*/
        m_enemyManager->render(window);
        

        //creo un circulo de tamaño 300
       

        window.display();
    
}

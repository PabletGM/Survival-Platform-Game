#include "game.h"


Game::Game(sf::RenderWindow& window, screenSize screenParam)
{
   
    //inicializamos pantalla con tamaño jugable
    limitOffsetX = 60;
    limitOffsetY = 60;
    spaceXPlayable = screenParam.screenSizeX - limitOffsetX;
    spaceYPlayable = screenParam.screenSizeY - limitOffsetY;

    //inicializar enemyManager
    m_enemyManager = new enemyManager(window, spaceXPlayable, spaceYPlayable, limitOffsetX,limitOffsetY);
    m_plataforma = new plataforma();
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

        /*m_map->render();
        m_mainCharacter->render();*/
        m_enemyManager->render(window);

        //creo un circulo de tamaño 300
       

        window.display();
    
}

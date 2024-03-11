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
    m_gameManager = new gameManager(window, screenParam, limitOffsetX, limitOffsetY, spaceXPlayable, spaceYPlayable);
}


void Game::update(float deltaMS, sf::RenderWindow& window)
{
    m_gameManager->update(deltaMS, window);
    m_enemyManager->update();
    
}

void Game::render(float deltaMS, sf::RenderWindow& window)
{
    
        window.clear();

        m_gameManager->render(deltaMS,window);
        m_enemyManager->render(window);
        

        window.display();
    
}

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
    m_protagonista = new protagonista(Position{800,1000}, limits);
}


void Game::update(float deltaMS, sf::RenderWindow& window)
{
    //updating positions of enemies
    m_enemyManager->update();
    m_protagonista->update();
     
    
}

void Game::render(float deltaMS, sf::RenderWindow& window)
{
    
        window.clear();

        m_map->render(window);
        m_protagonista->render(window);
        m_enemyManager->render(window);
        

        
       

        window.display();
    
}

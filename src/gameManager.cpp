#include "gameManager.h"






gameManager::gameManager(sf::RenderWindow& window, screenSize screenParam, unsigned int limittOffsetX, unsigned int limittOffsetY, unsigned int spaceeXPlayable, unsigned int spaceeYPlayable)
{

    //inicializamos pantalla con tamaño jugable
    limitOffsetX = limittOffsetX;
    limitOffsetY = limittOffsetY;
    spaceXPlayable = spaceeYPlayable;
    spaceYPlayable = spaceeYPlayable;
    //definimos espacio jugable
    limits limits{ (spaceXPlayable),(limitOffsetX),(limitOffsetY),(spaceYPlayable) };
    //inicializar enemyManager

    m_map = new map();
    m_protagonista = new protagonista(Position{ 800,1000 }, limits);
}


void gameManager::update(float deltaMS, sf::RenderWindow& window)
{
    //input of player and position
    m_protagonista->update();
}

void gameManager::render(float deltaMS, sf::RenderWindow& window)
{
    window.clear();

    m_map->render(window);
    m_protagonista->render(window);

    window.display();
}

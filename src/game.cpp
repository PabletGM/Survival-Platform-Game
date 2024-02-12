#include "game.h"

void Game::update(float deltaMS, sf::RenderWindow& window)
{
    
        /* m_mainCharacter->update(deltaMS);
         m_enemyManager->update(deltaMS);*/
    
}

void Game::render(float deltaMS, sf::RenderWindow& window)
{
    
        window.clear();

        /*m_map->render();
        m_mainCharacter->render();
        m_enemyManager->render();*/

        window.display();
    
}

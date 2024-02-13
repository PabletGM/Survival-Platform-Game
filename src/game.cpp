#include "game.h"


Game::Game()
{
    //inicializar enemyManager
    m_enemyManager = new enemyManager();
    m_plataforma = new plataforma();
    m_protagonista = new protagonista();
}


void Game::update(float deltaMS, sf::RenderWindow& window)
{
    
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

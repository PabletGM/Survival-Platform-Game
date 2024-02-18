
#include "enemyManager.h"
#include "enemySuperVillain.h"
#include "enemyVillain.h"
#include <random>
#include <position.h>
#include <game.h>

//lista de inicializacion con valor de numEnemiesTotal
enemyManager::enemyManager(sf::RenderWindow& window, unsigned int spaceXPlayable, unsigned int spaceYPlayable, unsigned int limitOffsetX, unsigned int limitOffsetY) : numEnemiesTotalVillain{ 3 }, numEnemiesTotalSuperVillain{ 3 }
{
	CreateEnemies(window, spaceXPlayable, spaceYPlayable,limitOffsetX,limitOffsetY);	
}

void enemyManager::update()
{
	//updating position of enemies
	for (auto i = m_enemies.begin(); i < m_enemies.end(); i++)
	{
		//accedemos al objeto apuntado por iterador i, accedemos al contenido que apunta i
		enemy* currentEnemy = *i;
		//si el objeto existe
		if (currentEnemy)
		{
			// Llamar al método render del objeto actual
			currentEnemy->update();
		}
	}
}

void enemyManager::render(sf::RenderWindow& window )
{


	//iterador que recorre toda la lista de enemigos in game
	for (auto i = m_enemies.begin(); i < m_enemies.end(); i++) 
	{
		//accedemos al objeto apuntado por iterador i, accedemos al contenido que apunta i
		enemy* currentEnemy = *i;
		//si el objeto existe
		if (currentEnemy)
		{
			// Llamar al método render del objeto actual
			currentEnemy->render(window);
		}
	}
}


void enemyManager::CreateEnemies(sf::RenderWindow& window, unsigned int spaceXPlayable, unsigned int spaceYPlayable, unsigned int limitOffsetX, unsigned int limitOffsetY)
{

	//generamos posiciones iniciales aleatorias, entre 1 y 1000
	std::srand(std::time(nullptr));

	int spaceXPlay = static_cast<int>(spaceXPlayable);
	int spaceYPlay = static_cast<int>(spaceYPlayable);


	//inicializamos enemySuperVillain
	for (int i = 0;i < numEnemiesTotalSuperVillain;i++)
	{
		int posXInitRandomEnemy =  limitOffsetX+ std::rand() % spaceXPlay;
		int posYInitRandomEnemy = limitOffsetX + std::rand() % spaceYPlay;
		Position p{ posXInitRandomEnemy, posYInitRandomEnemy };
		enemy* e = new enemySuperVillain(p, spaceXPlay, spaceYPlay);
		m_enemies.push_back(e);
		
	}

	//inicializamos enemyVillain
	for (int i = 0;i < numEnemiesTotalVillain;i++)
	{
		int posXInitRandomEnemy = limitOffsetY + std::rand() % spaceXPlay;
		int posYInitRandomEnemy = limitOffsetY + std::rand() % spaceYPlay;
		Position p{ posXInitRandomEnemy, posYInitRandomEnemy };
		enemy* e = new enemyVillain(p, spaceXPlay, spaceYPlay);
		m_enemies.push_back(e);
		
	}



}

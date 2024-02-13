
#include "enemyManager.h"
#include "enemySuperVillain.h"
#include "enemyVillain.h"
#include <random>

//lista de inicializacion con valor de numEnemiesTotal
enemyManager::enemyManager(sf::RenderWindow& window) : numEnemiesTotal{ 6 }
{
	

	CreateEnemies(window);
	
}

void enemyManager::update()
{
}

void enemyManager::render(sf::RenderWindow& window )
{
	for (int i = 0; i < numEnemiesTotal;i++)
	{
		enemiesInGame[i]->render(window);
	}
}


void enemyManager::CreateEnemies(sf::RenderWindow& window)
{

	//generamos posiciones iniciales aleatorias, entre 1 y 1000
	std::srand(std::time(nullptr));
	//inicializamos enemies y array enemiesInGame
	for (int i = 0;i < numEnemiesTotal;i++)
	{
		int posXInitRandomEnemy = 1 + std::rand() % 1000;
		int posYInitRandomEnemy = 1 + std::rand() % 1000;
		enemySuperVillain* e = new enemySuperVillain();
		m_enemies.push_back(e);
		/*enemiesInGame[i] = new enemy(window, posXInitRandomEnemy, posYInitRandomEnemy);*/

	}

}

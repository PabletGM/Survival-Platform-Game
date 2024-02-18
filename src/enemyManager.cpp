
#include "enemyManager.h"
#include "enemySuperVillain.h"
#include "enemyVillain.h"
#include <random>

//lista de inicializacion con valor de numEnemiesTotal
enemyManager::enemyManager(sf::RenderWindow& window) : numEnemiesTotalVillain{ 3 }, numEnemiesTotalSuperVillain{ 3 }
{
	CreateEnemies(window);	
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


void enemyManager::CreateEnemies(sf::RenderWindow& window)
{

	//generamos posiciones iniciales aleatorias, entre 1 y 1000
	std::srand(std::time(nullptr));

	//inicializamos enemySuperVillain
	for (int i = 0;i < numEnemiesTotalSuperVillain;i++)
	{
		int posXInitRandomEnemy = 1 + std::rand() % 1000;
		int posYInitRandomEnemy = 1 + std::rand() % 1000;
		enemy* e = new enemySuperVillain(posXInitRandomEnemy, posYInitRandomEnemy);
		m_enemies.push_back(e);
		
	}

	//inicializamos enemyVillain
	for (int i = 0;i < numEnemiesTotalVillain;i++)
	{
		int posXInitRandomEnemy = 1 + std::rand() % 1000;
		int posYInitRandomEnemy = 1 + std::rand() % 1000;
		enemy* e = new enemyVillain(posXInitRandomEnemy, posYInitRandomEnemy);
		m_enemies.push_back(e);
		
	}

}

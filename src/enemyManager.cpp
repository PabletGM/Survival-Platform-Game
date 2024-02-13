
#include "enemyManager.h"

//lista de inicializacion con valor de numEnemiesTotal
enemyManager::enemyManager() : numEnemiesTotal{ 3 }
{
	//inicializamos enemies y array enemiesInGame
	for (int i = 0;i < numEnemiesTotal;i++)
	{
		enemiesInGame[i] = new enemy();
	}
	
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

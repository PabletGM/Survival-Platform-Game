
#include "enemyManager.h"
#include "enemySuperVillain.h"
#include "enemyVillain.h"
#include <random>
#include <position.h>
#include <game.h>

//lista de inicializacion con valor de numEnemiesTotal
enemyManager::enemyManager(sf::RenderWindow& window,limits limits): numEnemiesTotalVillain{ 3 }, numEnemiesTotalSuperVillain{ 3 }
{
	CreateSpawns();
	CreateEnemies(window, limits);

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


void enemyManager::CreateEnemies(sf::RenderWindow& window, limits limits)
{

	//generamos posiciones iniciales aleatorias, entre 1 y 1000
	std::srand(std::time(nullptr));



	//inicializamos enemySuperVillain
	for (int i = 0;i < numEnemiesTotalSuperVillain;i++)
	{

		enemy* e = new enemySuperVillain(spawnsEnemySuperVillain[i], limits);
		m_enemies.push_back(e);
		
	}

	//inicializamos enemyVillain
	for (int i = 0;i < numEnemiesTotalVillain;i++)
	{
		
		enemy* e = new enemyVillain(spawnsEnemyVillain[i],limits);
		m_enemies.push_back(e);
		
	}



}

void enemyManager::CreateSpawns()
{
	CreateSpawnsSuperVillain();
	CreateSpawnsVillain();
	
}

void enemyManager::CreateSpawnsSuperVillain()
{
	//spawns pre-created in places
	Position p1 = { 100,100 };
	Position p2 = { 300,300 };
	Position p3 = { 500,700 };
	//Position p4 = { 700,900 };
	//Position p5 = { 900,000 };

	for (int i = 0; i < enemySuperSpawns; ++i)
	{

		//switch to choose the enemy
		switch (i)
		{
			case 0:
				spawnsEnemySuperVillain[i].posX = p1.posX;
				spawnsEnemySuperVillain[i].posY = p1.posY;
				break;

			case 1:
				spawnsEnemySuperVillain[i].posX = p2.posX;
				spawnsEnemySuperVillain[i].posY = p2.posY;
				break;

			case 2:
				spawnsEnemySuperVillain[i].posX = p3.posX;
				spawnsEnemySuperVillain[i].posY = p3.posY;
				break;
		}

	}
}

void enemyManager::CreateSpawnsVillain()
{
	//spawns pre-created in places
	Position p1 = { 300,300 };
	Position p2 = { 1200,200 };
	Position p3 = { 1400,700 };
	//Position p4 = { 700,900 };
	//Position p5 = { 900,000 };

	for (int i = 0; i < enemySpawns; ++i)
	{

		//switch to choose the enemy
		switch (i)
		{
			case 0:
				spawnsEnemyVillain[i].posX = p1.posX;
				spawnsEnemyVillain[i].posY = p1.posY;
				break;

			case 1:
				spawnsEnemyVillain[i].posX = p2.posX;
				spawnsEnemyVillain[i].posY = p2.posY;
				break;

			case 2:
				spawnsEnemyVillain[i].posX = p3.posX;
				spawnsEnemyVillain[i].posY = p3.posY;
				break;
		}

	}
}

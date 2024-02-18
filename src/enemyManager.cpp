
#include "enemyManager.h"
#include "enemySuperVillain.h"
#include "enemyVillain.h"
#include <random>
#include <position.h>
#include <game.h>

//lista de inicializacion con valor de numEnemiesTotal
enemyManager::enemyManager(sf::RenderWindow& window,limits limits): numEnemiesTotalVillain{ 3 }, numEnemiesTotalSuperVillain{ 3 }
{
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
		int posXInitRandomEnemy =  limits.limitIzquierdo+ std::rand() % limits.limitDerecho;
		int posYInitRandomEnemy =limits.limitArriba + std::rand() % limits.limitAbajo;
		Position p{ posXInitRandomEnemy, posYInitRandomEnemy };
		enemy* e = new enemySuperVillain(p, limits);
		m_enemies.push_back(e);
		
	}

	//inicializamos enemyVillain
	for (int i = 0;i < numEnemiesTotalVillain;i++)
	{
		int posXInitRandomEnemy = limits.limitIzquierdo + std::rand() % limits.limitDerecho;
		int posYInitRandomEnemy = limits.limitArriba + std::rand() % limits.limitAbajo;
		Position p{ posXInitRandomEnemy, posYInitRandomEnemy };
		enemy* e = new enemyVillain(p,limits);
		m_enemies.push_back(e);
		
	}



}


#include "enemyManager.h"

#include "enemySuperVillain.h"
#include "enemyVillain.h"
#include <random>
#include <position.h>
#include <game.h>

//constructor and creation of enemies calling ObjectPooler
enemyManager::enemyManager(sf::RenderWindow& window,limits limits): numEnemiesTotalVillain{ 3 }, numEnemiesTotalSuperVillain{ 3 }
{
	CreateEnemies(window, limits);
}

enemyManager::~enemyManager()
{
}

//create new enemy
void enemyManager::CreateNewEnemy()
{
	//generamos posiciones iniciales aleatorias, entre 1 y 1000
	std::srand(std::time(nullptr));

	//llamamos a objectPoolermetodo donde se crearan enemigos
	ObjectPooler::getInstance().CreateNewEnemy();
}

//to create new enemy with access each x seconds
void enemyManager::update()
{
	bool CanSpawnEnemy = canSpawnEnemy();
	if (CanSpawnEnemy)
	{
		CreateNewEnemy();
	}
}

//timer to spawn enemies
bool enemyManager::canSpawnEnemy()
{
	sf::Time tiempo = cronometroSpawnEnemy.getElapsedTime();

	if (tiempo >= tiempoDeseado)
	{
		cronometroSpawnEnemy.restart();
		canSpawn = true;
	}
	else
	{
		canSpawn = false;
	}
	return canSpawn;
}




//create enemies

void enemyManager::CreateEnemies(sf::RenderWindow& window, limits limits)
{

	//generamos posiciones iniciales aleatorias, entre 1 y 1000
	std::srand(std::time(nullptr));

	//llamamos a objectPoolermetodo donde se crearan enemigos
	ObjectPooler::getInstance().CreateSpawns();
	ObjectPooler::getInstance().CreateEnemies(numEnemiesTotalVillain, numEnemiesTotalSuperVillain, limits);

}


//constructor por defecto
enemyManager::enemyManager()
{
}

// Inicialización de la variable estática instance
enemyManager enemyManager::instance;



// Implementación del método getInstance para devolver la instancia singleton
enemyManager& enemyManager::getInstance()
{
	return instance;
}

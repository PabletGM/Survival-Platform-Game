
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

// Inicializaci�n de la variable est�tica instance
enemyManager enemyManager::instance;



// Implementaci�n del m�todo getInstance para devolver la instancia singleton
enemyManager& enemyManager::getInstance()
{
	return instance;
}

#include "gameManager.h"






gameManager::gameManager(sf::RenderWindow& window, screenSize screenParam, unsigned int limittOffsetX, unsigned int limittOffsetY, unsigned int spaceeXPlayable, unsigned int spaceeYPlayable)
{

    //inicializamos pantalla con tamaño jugable
    limitOffsetX = limittOffsetX;
    limitOffsetY = limittOffsetY;
    spaceXPlayable = spaceeXPlayable;
    spaceYPlayable = spaceeYPlayable;
    //definimos espacio jugable
    limits limits{ (spaceXPlayable),(limitOffsetX),(limitOffsetY),(spaceYPlayable) };
   
    //create platforms
    PlatformSpawn();
    LoadBoxCollidersArrayInit();

    m_map = new map();
    m_protagonista = new protagonista(Position{ 800,1000 }, limits);
}

void gameManager::LoadBoxCollidersArrayInit()
{
    for (int i = 0; i < numPlatforms; ++i)
    {
    	// Asegúrate de que platformArray contiene punteros a plataforma
    	plataforma* currentPlatform = &platformArray[i];

    	// Llama al método global bound y saca el boxcollider de cada plataforma
    	sf::FloatRect boxCollider = currentPlatform->getGlobalBounds();

    	//lo guardas en el vector
    	boxCollidersPlatformArray.push_back(boxCollider);

    }
}

void gameManager::PlatformSpawn()
{
    //create array platforms
    Position positions[] =
    {
        {100, 100},
        {150, 100},
        {500, 700},
        {100, 700},
        {1100, 300},
        {1500, 700}
    };

    //create platforms
    for (int i = 0; i < numPlatforms; ++i)
    {
        plataforma* pl = new plataforma(positions[i]);
        platformArray.push_back(*pl);
    }

}


void gameManager::update(float deltaMS, sf::RenderWindow& window)
{
    //input of player and position
    m_protagonista->update();

   
}

void gameManager::render(float deltaMS, sf::RenderWindow& window)
{


    m_map->render(window);
    //renderizamos las plataformas
    for (int i = 0; i < numPlatforms; ++i)
    {
        // Asegúrate de que platformArray contiene punteros a plataforma
        plataforma* currentPlatform = &platformArray[i];

        // Llama al método render de la plataforma actual
        currentPlatform->render(window);
    }
    m_protagonista->render(window);


}

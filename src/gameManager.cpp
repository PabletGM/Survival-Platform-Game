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
    //crea un pool de 10 balas
    Position p;
    p.posX = 1000;
    p.posY = 1000;
    m_map = new map();
    m_protagonista = new protagonista(Position{ 800,1000 }, limits, boxCollidersPlatformArray, numPlatforms);
}

void gameManager::LoadBoxCollidersArrayInit()
{
    for (int i = 0; i < numPlatforms; ++i)
    {
    	// Asegúrate de que platformArray contiene punteros a plataforma
    	plataforma* currentPlatform = &platformArray[i];

        //modificamos width un poco
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
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
       
    };
    bool collision = false;
    for (int i = 0; i < numPlatforms; ++i)
    {
        do
        {
            // Genera valores aleatorios entre 100 y 1800 en X
            positions[i].posX = rand() % 1701 + 100;

            // Genera valores aleatorios entre 100 y 1000 en Y
            positions[i].posY = rand() % 900 + 100;

            // Comprueba si la nueva plataforma choca con alguna plataforma existente
            collision = false;
            //recorre plataformas generadas
            for (int j = 0; j < i; ++j)
            {
                //mira distancia entre plataformas de 300
                if (std::abs(positions[i].posX - positions[j].posX) < 300 &&
                    std::abs(positions[i].posY - positions[j].posY) < 200)
                {
                    collision = true;
                    break;
                }
            }
        } while (collision);
    }

    //create platforms
    for (int i = 0; i < numPlatforms; ++i)
    {
        plataforma* pl = new plataforma(positions[i]);
        platformArray.push_back(*pl);
    }

}

// Inicialización de la variable estática instance
gameManager gameManager::instance;

// Implementación del constructor por defecto
gameManager::gameManager()
{
    // Aquí puedes realizar cualquier inicialización necesaria para tu ObjectPooler
}

// Implementación del método getInstance para devolver la instancia singleton
gameManager& gameManager::getInstance()
{
    return instance;
}

Position& gameManager::GetPosPlayer()
{

    //actualizamos pos player
    return playerPos;
}


void gameManager::update(float deltaMS, sf::RenderWindow& window)
{
    //input of player and position
    m_protagonista->update();
    ObjectPooler::getInstance().UpdateBulletUsed();
    //actualizamos playerPos
    playerPos = getPlayerPosition();
   
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
    ObjectPooler::getInstance().RenderBulletUsed(window);


}

Position gameManager::getPlayerPosition()
{
    return m_protagonista->getPosition();
}


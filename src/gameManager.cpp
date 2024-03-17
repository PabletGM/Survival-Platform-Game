#include "gameManager.h"





//constructor to create spawn platforms, protagonista and UIManager
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
    m_UIManager = new UIManager();
}

gameManager::~gameManager()
{
}

//load box colliders array 
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

//platform spawn
void gameManager::PlatformSpawn()
{
    // Crear array de posiciones para 20 plataformas
    Position positions[50];

    bool collision = false;
    for (int i = 0; i < 50; ++i) // Cambiar el límite a 20
    {
        do
        {
            // Genera valores aleatorios entre 100 y 1800 en X
            positions[i].posX = rand() % 1700 + 100;

            // Genera valores aleatorios entre 100 y 1000 en Y
            positions[i].posY = rand() % 900 + 100;

            // Comprueba si la nueva plataforma choca con alguna plataforma existente
            collision = false;
            // Recorre plataformas generadas
            for (int j = 0; j < i; ++j)
            {
                // Mira la distancia entre plataformas de 300
                if (std::abs(positions[i].posX - positions[j].posX) < 100 &&
                    std::abs(positions[i].posY - positions[j].posY) < 100)
                {
                    collision = true;
                    break;
                }
            }
        } while (collision);
    }

    // Crear plataformas
    for (int i = 0; i < numPlatforms; ++i) // Cambiar el límite a 20
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
   
}

// Implementación del método getInstance para devolver la instancia singleton
gameManager& gameManager::getInstance()
{
    return instance;
}


//update pos protagonista, bullets and UIManager
void gameManager::update(float deltaMS, sf::RenderWindow& window)
{
   
        //input of player and position
        m_protagonista->update();
        ObjectPooler::getInstance().UpdateBulletUsed();
        m_UIManager->update();
}

//mapa, protagonista and bullets render
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
        //uiManager
        m_UIManager->render(window);
    
}

//position get player
Position gameManager::getPlayerPosition()
{

    return posPlayer;
}

//protagonista devuelve si esta muerto
bool gameManager::playerIsDead()
{
    //llamamos a metodo de protagonista que devuelve si esta muerto
   return  m_protagonista->playerIsDead();
}






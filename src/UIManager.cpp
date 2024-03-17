#include "UIManager.h"
#include <ObjectPooler.h>




UIManager::UIManager()
{
    LifesSpawn();
}

UIManager::~UIManager()
{
}

//comprobamos todo el rato las vidas del player preguntandoselo al ObjectPooler
void UIManager::update()
{
   numVidas = ObjectPooler::getInstance().GetActualLifes();
}

void UIManager::render(sf::RenderWindow& window)
{
    //renderizamos las vidas
    for (int i = 0; i < numVidas; ++i)
    {
        // Asegúrate de que platformArray contiene punteros a plataforma
        Life* currentLife = &LifesArray[i];

        // Llama al método render de la plataforma actual
        currentLife->render(window);
    }
}

void UIManager::LifesSpawn()
{
    // Crear array de posiciones para 3 lifes
    Position positions[3];
    //pones posiciones
    positions[0].posX = 1860;
    positions[0].posY = 50;

    positions[1].posX = 1780;
    positions[1].posY = 50;

    positions[2].posX = 1700;
    positions[2].posY = 50;

    // Creas vidas
    for (int i = 0; i < numVidas; ++i) // Cambiar el límite a 3
    {
        Life* pl = new Life(positions[i]);
        LifesArray.push_back(*pl);
    }
}



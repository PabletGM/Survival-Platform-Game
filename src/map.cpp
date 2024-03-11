#include "map.h"
#include <position.h>

map::map()
{
	PlatformSpawn();
    LoadTextureInit();
	//load the box colliders array
	LoadBoxCollidersArrayInit();
}



void map::update()
{
}

void map::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
}

void map::LoadTextureInit()
{
    //carga de imagen del proyecto
    textureMap.loadFromFile("../sprites/map/mapa.png");
    //le ponemos textura
    spriteMap.setTexture(textureMap);
}

void map::LoadBoxCollidersArrayInit()
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

std::vector<sf::FloatRect> map::getBoxCollidersPlatform() const
{
	return boxCollidersPlatformArray;
}

void map::UpdateSprite(sf::RenderWindow& window)
{
    window.draw(spriteMap);
	//renderizamos las plataformas
	for (int i = 0; i < numPlatforms; ++i)
	{
		// Asegúrate de que platformArray contiene punteros a plataforma
		plataforma* currentPlatform = &platformArray[i];

		// Llama al método render de la plataforma actual
		currentPlatform->render(window);
	}
}

void map::PlatformSpawn()
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

#include "map.h"
#include <position.h>

map::map()
{
    LoadTextureInit();
}

map::~map()
{
}



void map::update()
{
}

//render map 
void map::render(sf::RenderWindow& window)
{
    UpdateSprite(window);
}

//load textures of the map
void map::LoadTextureInit()
{
    //carga de imagen del proyecto
    textureMap.loadFromFile("../sprites/map/mapa.png");
    //le ponemos textura
    spriteMap.setTexture(textureMap);
}





void map::UpdateSprite(sf::RenderWindow& window)
{
    window.draw(spriteMap);
	
}



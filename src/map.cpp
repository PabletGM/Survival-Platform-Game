#include "map.h"
#include <position.h>

map::map()
{
	
    LoadTextureInit();
	
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





void map::UpdateSprite(sf::RenderWindow& window)
{
    window.draw(spriteMap);
	
}



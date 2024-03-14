#include "plataforma.h"

plataforma::plataforma(Position p)
{
    position.posX = p.posX;
    position.posY = p.posY;
    LoadTextureInit();
    MoveSpriteInit();
    SetOrigin();
    SetScale();



    
}

void plataforma::update()
{
}

void plataforma::render(sf::RenderWindow& window)
{
    window.draw(spritePlatform);
}

sf::FloatRect plataforma::getGlobalBounds() const
{
    return spritePlatform.getGlobalBounds();
}

void plataforma::MoveSpriteInit()
{

        // offset relative to the current position
        spritePlatform.move(sf::Vector2f(position.posX, position.posY));

}

void plataforma::LoadTextureInit()
{
   
        //carga de imagen del proyecto
        texturePlatform.loadFromFile("../sprites/map/platform.png");
        //le ponemos textura
        spritePlatform.setTexture(texturePlatform);
       
    
}

void plataforma::SetOrigin()
{
    spritePlatform.setOrigin(spritePlatform.getLocalBounds().width / 2, spritePlatform.getLocalBounds().height / 2);
}

void plataforma::SetScale()
{
    float size = rand() % 100 + 70;

    spritePlatform.setScale(size/200,size/200);
    
}



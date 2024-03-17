#include "plataforma.h"

//constructor
plataforma::plataforma(Position p)
{
    position.posX = p.posX;
    position.posY = p.posY;
    LoadTextureInit();
    MoveSpriteInit();
    SetOrigin();
    SetScale();
}

//destructor
plataforma::~plataforma()
{
}

//update
void plataforma::update()
{
}

//render
void plataforma::render(sf::RenderWindow& window)
{
    window.draw(spritePlatform);
}

//collider platform
sf::FloatRect plataforma::getGlobalBounds() const
{
    return spritePlatform.getGlobalBounds();
}

//position platform sprite
void plataforma::MoveSpriteInit()
{
        // offset relative to the current position
        spritePlatform.move(sf::Vector2f(position.posX, position.posY));
}

//load texture
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

//set scale platform
void plataforma::SetScale()
{
    float size = rand() % 100 + 70;

    spritePlatform.setScale(size/200,size/200);
    
}



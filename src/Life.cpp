#include "Life.h"

Life::Life()
{
}

Life::Life(Position p)
{
    position.posX = p.posX;
    position.posY = p.posY;
    LoadTextureInit();
    MoveSpriteInit();
    SetOrigin();
    SetScale();
}

Life::~Life()
{
}

void Life::render(sf::RenderWindow& window)
{
    window.draw(spriteLife);

}

void Life::MoveSpriteInit()
{
    // offset relative to the current position
    spriteLife.move(sf::Vector2f(position.posX, position.posY));
}

void Life::LoadTextureInit()
{
    //carga de imagen del proyecto
    textureLife.loadFromFile("../sprites/canvas/Life.png");
    //le ponemos textura
    spriteLife.setTexture(textureLife);
}

void Life::SetOrigin()
{
    spriteLife.setOrigin(spriteLife.getLocalBounds().width / 2, spriteLife.getLocalBounds().height / 2);
}

void Life::SetScale()
{

    spriteLife.setScale(0.08f,0.08f);
}

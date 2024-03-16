#include "InitScene.h"

InitScene::InitScene()
{
    LoadTextureInit();
}

InitScene::~InitScene()
{
}

void InitScene::update(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Enter)
            {
                isActiveInitScene = false;
            }
        }
    }
}

void InitScene::render(sf::RenderWindow& window)
{
	UpdateSprite(window);
}

void InitScene::LoadTextureInit()
{
    //carga de imagen del proyecto
    textureMainMenu.loadFromFile("../sprites/map/SceneInit.png");
    //le ponemos textura
    spriteMainMenu.setTexture(textureMainMenu);
}

void InitScene::UpdateSprite(sf::RenderWindow& window)
{
    window.draw(spriteMainMenu);
}

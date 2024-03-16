#pragma once
#include <SFML/Graphics.hpp>

class InitScene
{
public:
    //constructor por defecto
    InitScene();
    ~InitScene();


    void update(sf::RenderWindow& window);


    void render(sf::RenderWindow& window);

    void LoadTextureInit();


    bool isActiveInitScene = true;



private:

    //sprite enemigo
    sf::Sprite spriteMainMenu;
    //texture enemigo
    sf::Texture textureMainMenu;

    void UpdateSprite(sf::RenderWindow& window);




};
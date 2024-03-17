#pragma once
#include <SFML/Graphics.hpp>
#include <position.h>


class Life
{
public:
    //constructor por defecto
    Life();
    Life(Position p);
    ~Life();



    void render(sf::RenderWindow& window);


private:

    //sprite enemigo
    sf::Sprite spriteLife;
    //texture enemigo
    sf::Texture textureLife;
    void MoveSpriteInit();
    void LoadTextureInit();
    void SetOrigin();
    void SetScale();

    Position position;


};
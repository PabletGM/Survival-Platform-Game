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

    //sprite life canvas
    sf::Sprite spriteLife;
    //texture life canvas
    sf::Texture textureLife;

    //sprite methods
    void MoveSpriteInit();
    void LoadTextureInit();
    void SetOrigin();
    void SetScale();

    //position
    Position position;


};
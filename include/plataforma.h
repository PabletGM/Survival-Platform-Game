#pragma once
#include <SFML/Graphics.hpp>
#include <position.h>


class plataforma
{
    public:
        //constructor por defecto
        plataforma(Position p);

        void update();


        void render(sf::RenderWindow& window);

        //box collider de plataformas
        sf::FloatRect getGlobalBounds() const;

    private:

        //sprite enemigo
        sf::Sprite spritePlatform;
        //texture enemigo
        sf::Texture texturePlatform;
        void MoveSpriteInit();
        void LoadTextureInit();

        Position position;

};
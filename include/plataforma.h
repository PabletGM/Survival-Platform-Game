#pragma once
#include <SFML/Graphics.hpp>
#include <position.h>

//each platform of the map
class plataforma
{
    public:
        //constructor por defecto
        plataforma(Position p);
        ~plataforma();

        void update();


        void render(sf::RenderWindow& window);

        //box collider de plataformas
        sf::FloatRect getGlobalBounds() const;

    private:

        //sprite platform
        sf::Sprite spritePlatform;
        //texture platform
        sf::Texture texturePlatform;
        //move sprite initial
        void MoveSpriteInit();
        //load init texture
        void LoadTextureInit();
        //set origin
        void SetOrigin();
        //set scale sprite
        void SetScale();

        Position position;
      

};
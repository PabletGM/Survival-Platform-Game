#pragma once
#include <SFML/Graphics.hpp>
#include <plataforma.h>

//class to put the background
class map
{
    public:
        //constructor por defecto
        map();
        ~map();
        

        void update();


        void render(sf::RenderWindow& window);

        void LoadTextureInit();

    private:

        //sprite map
        sf::Sprite spriteMap;
        //texture map
        sf::Texture textureMap;

        void UpdateSprite(sf::RenderWindow& window);
        


      
};
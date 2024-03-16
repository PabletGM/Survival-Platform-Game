#pragma once
#include <SFML/Graphics.hpp>
#include <plataforma.h>
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

        //sprite enemigo
        sf::Sprite spriteMap;
        //texture enemigo
        sf::Texture textureMap;

        void UpdateSprite(sf::RenderWindow& window);
        


      
};
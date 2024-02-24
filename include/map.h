#pragma once
#include <SFML/Graphics.hpp>
#include <plataforma.h>
class map
{
    public:
        //constructor por defecto
        map();


        void update();


        void render(sf::RenderWindow& window);

        void LoadTextureInit();

        


    private:

        //sprite enemigo
        sf::Sprite spriteMap;
        //texture enemigo
        sf::Texture textureMap;

        void UpdateSprite(sf::RenderWindow& window);
        void PlatformSpawn();

        //array de plataformas
        static const int numPlatforms = 6;
        std::vector<plataforma> platformArray;

};
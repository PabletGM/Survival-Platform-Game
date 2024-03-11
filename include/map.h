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
        void LoadBoxCollidersArrayInit();

        //devuelve el vector de boxColliders del platform
        std::vector<sf::FloatRect> getBoxCollidersPlatform() const;
        


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
        //array de box colliders de plataformas
        std::vector<sf::FloatRect> boxCollidersPlatformArray;

};
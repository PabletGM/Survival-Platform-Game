#include <SFML/Graphics.hpp>

class enemySuperVillain
{
    public:
        //constructor por defecto
        enemySuperVillain(sf::RenderWindow& window, int posXInit, int posYInit);


        void update();


        void render(sf::RenderWindow& window);


    private:


        //metodos privados
        void MoveSprite();
        void RotateSprite();
        void ScaleSprite();
        void ChangeOriginSprite();
        void LoadTextureInit(sf::RenderWindow& window);
        void UpdateSprite(sf::RenderWindow& window);

        //pones todo inicialmente
        void SetInitialPosition(int posX, int posY);

        //vida
        int maxLife;
        int actualLife;

        //sprite enemigo
        sf::Sprite spriteEnemy;
        //texture enemigo
        sf::Texture textureEnemy;

        //posicionInicial
        int posXInit;
        int posYInit;

};
#include <SFML/Graphics.hpp>

class enemy
{
    public:
        //constructor por defecto
        enemy();

        void update();


        void render(sf::RenderWindow& window);


    private:

        int maxLife;
        int actualLife;

};
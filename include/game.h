
#include <SFML/Graphics.hpp>


class Game
{
    public:
        void update(float deltaMS, sf::RenderWindow& window);
    

        void render(float deltaMS, sf::RenderWindow& window);
        

        //metodo con condiciones para salir del juego
        bool wantsExit()
        {
            return false;
        }

    private:
        /*EnemyManager* m_enemyManager;*/
};

#include <SFML/Graphics.hpp>

//para tema de enemigos clase villano y supervillano hacer stateMachine con IA, buscar tutorial para los diferentes estados, perseguir, idle, buscar, etc
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
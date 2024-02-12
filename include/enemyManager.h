#include <enemy.h>


class enemyManager
{
    public:
        //constructor por defecto
        enemyManager();

        void update();


        void render();


    private:

        //array con enemigos
        enemy* enemiesInGame[3];

};
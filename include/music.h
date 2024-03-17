#include <vector>
#include <shoot.h>
#include "enemy.h"
#include "enemyVillain.h"
#include "enemySuperVillain.h"
#include <SFML/Audio/Music.hpp>


class music
{
public:
    // Constructor
    music();
    ~music();

    
    // Variable est�tica que almacena la �nica instancia de ObjectPooler
    static music instance;
    static music& getInstance(); // M�todo para obtener la instancia singleton

    void Play();
    void Stop();
    void LoadMusic();

private:
    
    // Objeto sf::Music para gestionar la m�sica
    sf::Music musicObject;



};
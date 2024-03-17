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

    
    // Variable estática que almacena la única instancia de ObjectPooler
    static music instance;
    static music& getInstance(); // Método para obtener la instancia singleton

    void Play();
    void Stop();
    void LoadMusic();

private:
    
    // Objeto sf::Music para gestionar la música
    sf::Music musicObject;



};
#pragma once
#include <SFML/Graphics.hpp>
#include <protagonista.h>
#include <map.h>
#include <protagonista.h>
#include <screenSize.h>


//para tema de enemigos clase villano y supervillano hacer stateMachine con IA, buscar tutorial para los diferentes estados, perseguir, idle, buscar, etc
class gameManager
{
    public:
    //constructor por defecto
    gameManager(sf::RenderWindow& window, screenSize screenParam,unsigned int limitOffsetX, unsigned int limitOffsetY, unsigned int spaceXPlayable, unsigned int spaceYPlayable);


    void update(float deltaMS, sf::RenderWindow& window);


    void render(float deltaMS, sf::RenderWindow& window);


    // Método para obtener la posición del jugador
    Position getPlayerPosition();


private:

    void LoadBoxCollidersArrayInit();
    void PlatformSpawn();
   
    //player del juego
    protagonista* m_protagonista;
    //plataformas del juego, TO DO--> cambiar por mapa y que este dentro tenga un array de plataformas que se rendericen
    map* m_map;

    //array de plataformas
    static const int numPlatforms = 10;


    std::vector<plataforma> platformArray;
    //array de box colliders de plataformas
    std::vector<sf::FloatRect> boxCollidersPlatformArray;


    unsigned int spaceXPlayable;
    unsigned int spaceYPlayable;
    //limitOffset
    unsigned  int limitOffsetX;
    unsigned  int limitOffsetY;


    //singleton
    
     // Constructor privado para evitar la creación de instancias
    gameManager();
    // Variable estática que almacena la única instancia de ObjectPooler
    

 public:
    static gameManager instance;
    static gameManager& getInstance();

     Position posPlayer;

     //direccion a la que mira el player
     bool directionRight;
     //por defecto
     bool directionLeft;

};
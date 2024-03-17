#pragma once
#include <SFML/Graphics.hpp>
#include <protagonista.h>
#include <map.h>
#include <screenSize.h>
#include <gameManager.h>
#include <InitScene.h>
#include <UIManager.h>
//#include <UIManager.h>



//has the functionality to rendere and update, player,map platforms and canvas
class gameManager
{
    public:
    //constructor por defecto
    gameManager(sf::RenderWindow& window, screenSize screenParam,unsigned int limitOffsetX, unsigned int limitOffsetY, unsigned int spaceXPlayable, unsigned int spaceYPlayable);
    ~gameManager();

    void update(float deltaMS, sf::RenderWindow& window);


    void render(float deltaMS, sf::RenderWindow& window);


    // Método para obtener la posición del jugador
    Position getPlayerPosition();

    bool playerIsDead();




   


private:

    void LoadBoxCollidersArrayInit();
    void PlatformSpawn();
   
    //player del juego
    protagonista* m_protagonista;
    //plataformas del juego, TO DO--> cambiar por mapa y que este dentro tenga un array de plataformas que se rendericen
    map* m_map;
    //uiManager
    UIManager* m_UIManager;

    //array de plataformas
    static const int numPlatforms = 100;


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

     sf::Sprite spritePlayer;


};
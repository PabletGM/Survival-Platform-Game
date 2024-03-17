#pragma once
#include <SFML/Graphics.hpp>
#include <Life.h>
#include "UIManager.h"





//para tema de enemigos clase villano y supervillano hacer stateMachine con IA, buscar tutorial para los diferentes estados, perseguir, idle, buscar, etc
class UIManager                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
{
public:
    //constructor por defecto
    UIManager();
    ~UIManager();

    void update();


    void render( sf::RenderWindow& window);



private:

    std::vector<Life> LifesArray;

    //array de plataformas
    static const int numVidas = 3;

    void LifesSpawn();





};
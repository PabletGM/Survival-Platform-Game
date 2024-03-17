#pragma once
#include <SFML/Graphics.hpp>
#include <Life.h>
#include "UIManager.h"




//with canvas functionality
class UIManager                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
{
public:
    //constructor
    UIManager();
    //destructor
    ~UIManager();

    void update();


    void render( sf::RenderWindow& window);



private:

    //array with number of hearts
    std::vector<Life> LifesArray;

    //vidas player
     int numVidas = 3;

     //lifes to spawn
    void LifesSpawn();

};
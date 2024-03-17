#pragma once
#include <SFML/Graphics.hpp>
#include <protagonista.h>






//para tema de enemigos clase villano y supervillano hacer stateMachine con IA, buscar tutorial para los diferentes estados, perseguir, idle, buscar, etc
class UIManager                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
{
public:
    //constructor por defecto
    UIManager();
    ~UIManager();

    void update(float deltaMS, sf::RenderWindow& window);


    void render(float deltaMS, sf::RenderWindow& window);



private:


public:
    static UIManager instance;
    static UIManager& getInstance();




};
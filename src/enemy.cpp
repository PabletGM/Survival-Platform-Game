#include "enemy.h"
#include <SFML/Graphics.hpp>

enemy::enemy()
{
}

void enemy::update()
{
}

void enemy::render()
{
    //dibujamos pelota
    sf::CircleShape shape(300.f);
    //le pones un color a la forma
    shape.setFillColor(sf::Color::Green);
    //haces metodo dibujar
    window.draw(shape);
}

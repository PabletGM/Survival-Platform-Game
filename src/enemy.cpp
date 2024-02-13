#include "enemy.h"


enemy::enemy(): maxLife{3}, actualLife{4}
{
}

void enemy::update()
{
}

void enemy::render(sf::RenderWindow& window)
{
    //dibujamos pelota
    sf::CircleShape shape(300.f);
    //le pones un color a la forma
    shape.setFillColor(sf::Color::Green);
    //haces metodo dibujar
    window.setFramerateLimit(144);
    window.draw(shape);
}

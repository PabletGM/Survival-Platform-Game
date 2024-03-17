#include <SFML/Graphics.hpp>
#include <game.h>
#include <screenSize.h>

int main()
{
    //creamos ventana con tamaño
    screenSize screen{ 1920,1080 };
    sf::RenderWindow window = sf::RenderWindow{ { screen.screenSizeX, screen.screenSizeY }, "CMake SFML Project" };
    window.setFramerateLimit(144);
    //creamos instancia game
    Game* game = new Game(window, screen);
    ////para uso de time entre frames 
    sf::Clock clock;

    //if you dont lose or esc button
    while (game->wantsExit() == false)
    {
        //tiempo transcurrido entre frames
        sf::Time elapsed = clock.restart();

        game->update(elapsed.asMilliseconds(), window); // Update input, physcis, etc..
        game->render(elapsed.asMilliseconds(), window);
    }

    return 0;
}
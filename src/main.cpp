#include <SFML/Graphics.hpp>
#include <game.h>
#include <screenSize.h>

//int main()
//{
//    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
//    window.setFramerateLimit(144);
//
//    while (window.isOpen())
//    {
//        for (auto event = sf::Event{}; window.pollEvent(event);)
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
//        }
//
//        window.clear();
//        window.display();
//    }
//}

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

    while (game->wantsExit() == false)
    {
        //tiempo transcurrido entre frames
        sf::Time elapsed = clock.restart();

        game->update(elapsed.asMilliseconds(), window); // Update input, physcis, etc..
        game->render(elapsed.asMilliseconds(), window);
    }

    /*while (window.isOpen())
    {
    }*/
    return 0;
}
#include "game.h"


//constructor to initialise enemyManager, gameManager and initScene
Game::Game(sf::RenderWindow& window, screenSize screenParam)
{
   
    //inicializamos pantalla con tamaño jugable
    limitOffsetX = 80;
    limitOffsetY = 80;
    spaceXPlayable = screenParam.screenSizeX - limitOffsetX;
    spaceYPlayable = screenParam.screenSizeY - limitOffsetY;
    //definimos espacio jugable
    limits limits{(spaceXPlayable),(limitOffsetX),(limitOffsetY),(spaceYPlayable) };
    //inicializar enemyManager
    m_enemyManager = new enemyManager(window, limits);
    m_gameManager = new gameManager(window, screenParam, limitOffsetX, limitOffsetY, spaceXPlayable, spaceYPlayable);
    m_initScene = new InitScene();
    //music
   
}


Game::~Game()
{
}


//update the position of the scene Game or the scene init or mainMenu
void Game::update(float deltaMS, sf::RenderWindow& window)
{
    //miramos si esta activa InitScene
    if (m_initScene->isActiveInitScene)
    {
        //renderizamos solo initScene
        m_initScene->update(window);
    }
    else
    {
        m_gameManager->update(deltaMS, window);
        m_enemyManager->update();
        ObjectPooler::getInstance().update();

        // Verificar si el jugador ha muerto o si se ha pulsado la tecla de escape
        if (m_gameManager->playerIsDead() || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            finishGame = true;
        }
    }
    
}

//render the initScene or the gameScene
void Game::render(float deltaMS, sf::RenderWindow& window)
{
    
        window.clear();

        //miramos si esta activa InitScene
        if (m_initScene->isActiveInitScene)
        {
            //renderizamos solo initScene
            m_initScene->render(window);
        }
        else
        {

            m_gameManager->render(deltaMS, window);
            ObjectPooler::getInstance().render(window);
        }

        window.display();
}

//wants to exit
bool Game::wantsExit()
{
    return finishGame;
}

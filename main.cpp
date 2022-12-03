#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "ball.hpp"

void renderingThread(sf::RenderWindow* window)
{
    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
    // activate the window's context
    window->setActive(true);

    Game game = Game();
    // define the level with an array of tile indices
    // const int level[] =
    // {
    //     0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    //     0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
    //     1, 1, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2,
    //     0, 1, 0, 0, 2, 0, 2, 2, 2, 0, 1, 1, 1, 0, 0, 0,
    //     0, 1, 1, 0, 2, 2, 2, 0, 0, 0, 1, 1, 1, 2, 0, 0,
    //     0, 0, 1, 0, 2, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
    //     2, 0, 1, 0, 2, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
    //     0, 0, 1, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    // };

    // // create the tilemap from the level definition
    // TileMap map;
    // if (!map.load("assets/d1.gif", sf::Vector2u(32, 32), level, 16, 8))
    //     return;
    sf::Texture texture;
    // Ball ball(&texture, 50, sf::Color::Green);
    game.update();
    // the rendering loop
    while (window->isOpen())
    {
        // draw...
        window->clear(sf::Color(220, 220, 220));
        // window->draw(map);
        // ball.draw(*window);
        // texture.update(*window);
        // end the current frame -- this is a rendering function (it requires the context to be active)
        window->display();
    }
}


int main()
{

    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;

    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Lines 98");
    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(1);
    // deactivate its context
    window.setActive(true);

    // launch the rendering thread
    // sf::Thread thread(&renderingThread, &window);
    // thread.launch();

    Game game = Game();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            std::cout << "Down key" << std::endl;
            game.printConsole();
        }

        game.update();

        // draw...
        window.clear(sf::Color(220, 220, 220));
        // window.draw(game);
        game.draw(window);
        // texture.update(*window);
        // end the current frame -- this is a rendering function (it requires the context to be active)
        window.display();
    }

    return 0;
}
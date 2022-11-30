#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "game.hpp"

void renderingThread(sf::RenderWindow* window)
{
    // activate the window's context
    window->setActive(true);
    sf::Texture texture;
    if (!texture.loadFromFile("assets/ball.png", sf::IntRect(-20, -100, 50, 50)))
    {
        // error...
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    Game game = Game();
    game.update();
    // the rendering loop
    while (window->isOpen())
    {
        // draw...
        window->draw(sprite);

        // texture.update(*window);
        // end the current frame -- this is a rendering function (it requires the context to be active)
        window->display();
    }
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Lines 98");
    window.setVerticalSyncEnabled(true);
    // deactivate its context
    window.setActive(false);

    // launch the rendering thread
    sf::Thread thread(&renderingThread, &window);
    thread.launch();
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
// check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "ball.hpp"


int main()
{

    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Lines 98");
    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(1);
    window.setActive(true);


    Game game = Game();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
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
        game.draw(window);
        // end the current frame -- this is a rendering function (it requires the context to be active)
        window.display();
    }

    return 0;
}
#ifndef  _BALL_HPP_
#define _BALL_HPP_
#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(sf::Texture* texture, int radius, sf::Color color);
    ~Ball();

    void update(float delta_time);
    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape circle;
};

#endif // _BALL_HPP_

#ifndef  _BALL_HPP_
#define _BALL_HPP_
#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {
public:
    Ball(float radius, sf::Color color, sf::Vector2f pos);
    Ball(sf::Texture* texture, float radius, sf::Color color, sf::Vector2f pos);
    ~Ball();

    void update(float delta_time);

    void setSelect(bool enable);
private:
    bool selected;
};

#endif // _BALL_HPP_

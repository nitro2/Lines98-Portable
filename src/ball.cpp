#include <iostream>
#include "ball.hpp"

Ball::Ball(float radius, sf::Color color, sf::Vector2f pos) {
    this->setRadius(radius);
    this->setOutlineColor(color);
    this->setOutlineThickness(5);
    this->setPosition(pos.x, pos.y);
}

Ball::Ball(sf::Texture* texture, float radius, sf::Color color, sf::Vector2f pos) {
    this->setRadius(radius);
    this->setOutlineColor(color);
    this->setOutlineThickness(5);
    this->setPosition(pos.x, pos.y);
    this->setTexture(texture);
}
// Destructor
Ball::~Ball() {

}

void Ball::update(float delta_time) {

};

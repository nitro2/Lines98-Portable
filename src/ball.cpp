#include <iostream>

#include "ball.hpp"

Ball::Ball(float radius, sf::Color color, sf::Vector2f pos) {
    this->setRadius(radius);
    this->setFillColor(color);
    // this->setOutlineColor(color);
    // this->setOutlineThickness(5);
    this->setPosition(pos.x, pos.y);
}

// Destructor
Ball::~Ball() {

}

void Ball::update(float delta_time) {

};

void Ball::setSelect(bool enable) {
    this->selected = enable;
    if (this->selected) {
        this->setOutlineColor(sf::Color::Black);
        this->setOutlineThickness(5);
    }
    else {
        this->setOutlineColor(sf::Color::Transparent);
        this->setOutlineThickness(0);
    }
}

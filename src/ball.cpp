#include "ball.hpp"

// Constructor
Ball::Ball(sf::Texture* texture, int radius, sf::Color color) {
    circle.setRadius(radius);
    circle.setOutlineColor(color);
    circle.setOutlineThickness(5);
    circle.setPosition(10, 20);
    circle.setTexture(texture);
}
// Destructor
Ball::~Ball() {

}

void Ball::update(float delta_time) {

};

void Ball::draw(sf::RenderWindow& window) {
    window.draw(circle);
};
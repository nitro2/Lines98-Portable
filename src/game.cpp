#include <iostream>

#include "game.hpp"

// Constructor
Game::Game() {
    init();
}
// Destructor
Game::~Game() {

}


void Game::init() {
    std::fill_n(&matrix[0][0], sizeof(matrix) / sizeof(matrix[0][0]),
        Cell{ .state = BallState::EMPTY, .type = BallType::BALL_TYPE_NONE });
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COL_NUM; j++) {
            matrix[i][j].pos.x = i * TILE_SIZE;
            matrix[i][j].pos.y = j * TILE_SIZE;

            // auto texture = std::make_shared<sf::Texture>();
            // auto texture = new sf::Texture();
            // auto ball = std::make_shared<Ball>(texture, BALL_SIZE / 2, sf::Color::Green, matrix[i][j].pos);
            // auto ball = std::make_shared<Ball>(BALL_SIZE / 2, sf::Color::Green, matrix[i][j].pos);
            Ball* ball = new Ball(BALL_SIZE / 2, sf::Color::Green, matrix[i][j].pos);
            object_list.push_back(ball);
        }
    }
}

void Game::update() {
    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
    std::cout << sizeof(matrix) << std::endl;

}

void Game::printConsole() {
    for (auto& row : matrix) {
        for (auto& elem : row) {
            std::cout << elem.state << " ";
        }
        std::cout << std::endl;
    }
}

void Game::draw(sf::RenderWindow& window) {
    // std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
    // std::cout << "Size of object_lsit" << object_list.size() << std::endl;
    for (auto& obj : object_list) {
        if (obj) {
            window.draw(*obj);
            // std::cout << obj->getPosition().x << "." << obj->getPosition().y << std::endl;
        }
        else {
            std::cout << "Null object" << std::endl;
        }
    }
    // std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
}
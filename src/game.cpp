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
    // TODO set this srand to time for more randomly
    srand(0);
    std::fill_n(&matrix[0][0], sizeof(matrix) / sizeof(matrix[0][0]),
        Cell{ .state = BallState::EMPTY, .type = BallType::BALL_TYPE_NONE });
    // Init cell value
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COL_NUM; j++) {
            matrix[i][j].pos.x = i * TILE_SIZE;
            matrix[i][j].pos.y = j * TILE_SIZE;
            // Randomly generate a ball in each cell
            // If random value is not empty then create a ball
            int r = rand() % BallState::MAX_BALLSTATE;
            // std::cout << "r=" << r << std::endl;
            matrix[i][j].state = static_cast<BallState>(r);
            if (matrix[i][j].state != BallState::EMPTY) {
                // Randomly create color for the ball
                int t = rand() % (BallType::MAX_BALLTYPE - 1) + 1;
                // std::cout << "t=" << t << std::endl;
                matrix[i][j].type = static_cast<BallType>(t);
                auto ball = std::make_shared<Ball>(BALL_SIZE / 2, ColorDict[matrix[i][j].type], matrix[i][j].pos);
                object_list.push_back(ball);
            }

            std::cout << std::endl;
        }
    }

    // Add tile map
    auto tile_map = std::make_shared<TileMap>(sf::Vector2f(0.0f, 0.0f), ROW_NUM + 1, COL_NUM + 1, 1.0 * TILE_SIZE);
    object_list.push_back(tile_map);
}

void Game::update() {
    // std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
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
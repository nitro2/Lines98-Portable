#include <iostream>

#include "game.hpp"

// Constructor
Game::Game() {
    init();
    this->selecting_cell = std::make_pair(-1, -1);
    this->clock.restart();
    this->selecting_position = sf::Vector2i(0, 0);
}
// Destructor
Game::~Game() {

}


void Game::init() {
    // TODO set this srand to time for more randomly
    srand(0);
    std::fill_n(&matrix[0][0], sizeof(matrix) / sizeof(matrix[0][0]),
        Cell{ BallState::EMPTY, BallType::BALL_TYPE_NONE, sf::Vector2f(0, 0), nullptr });
    // Init cells value
    auto adjust_mid = (TILE_SIZE - BALL_SIZE) / 2;
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COL_NUM; j++) {
            matrix[i][j].pos.x = i * TILE_SIZE;
            matrix[i][j].pos.y = j * TILE_SIZE;
            // Randomly generate a ball in each cell
            // If random value is not empty then create a ball
            int r = rand() % 2; // Have or not have a ball
            // std::cout << "r=" << r << std::endl;
            matrix[i][j].state = static_cast<BallState>(r);
            if (matrix[i][j].state != BallState::EMPTY) {
                // Randomly create color for the ball
                int t = rand() % (BallType::MAX_BALLTYPE - 1) + 1;
                // std::cout << "t=" << t << std::endl;
                matrix[i][j].type = static_cast<BallType>(t);
                auto new_ball = std::make_shared<Ball>(BALL_SIZE / 2, ColorDict[matrix[i][j].type],
                    sf::Vector2f(matrix[i][j].pos.x + adjust_mid, matrix[i][j].pos.y + adjust_mid));
                object_list.push_back(new_ball);
                matrix[i][j].p_ball = new_ball;
            }
            else {
                matrix[i][j].p_ball = nullptr;
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
    for (auto& obj : object_list) {
        if (obj) {
            window.draw(*obj);
        }
        else {
            std::cout << "Null object" << std::endl;
        }
    }
}

void Game::setClickPosition(int x, int y) {
    std::cout << typeid(this).name() << "-" << __FUNCTION__ << " " << __LINE__ << std::endl
        << x << " " << y << " " << this->object_list.size()
        << "clock=" << this->clock.getElapsedTime().asMilliseconds() << std::endl;
    if (((0 < x) && (x < COL_NUM * TILE_SIZE))
        && ((0 < y) && (y < ROW_NUM * TILE_SIZE)))
    {
        int i = x / TILE_SIZE;
        int j = y / TILE_SIZE;

        sf::Time bounding = clock.getElapsedTime();
        if (((x != this->selecting_position.x) || (y != this->selecting_position.y))
            || (bounding.asMilliseconds() > this->CLICK_DELAY))
        {
            if (matrix[i][j].state == BallState::ACTIVE_BALL) {
                matrix[i][j].state = BallState::INACTIVE_BALL;
                matrix[i][j].p_ball->setSelect(false);
                this->selecting_cell = std::make_pair(-1, -1);
            }
            else if (matrix[i][j].state == BallState::INACTIVE_BALL) {
                matrix[i][j].state = BallState::ACTIVE_BALL;
                matrix[i][j].p_ball->setSelect(true);
                this->selecting_cell = std::make_pair(i, j);
            }
            this->clock.restart();
            this->selecting_position.x = x;
            this->selecting_position.y = y;
        }
    }

}

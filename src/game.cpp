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
    // Init A* algorithm
    // Set 2d map size.
    this->generator.setWorldSize({ COL_NUM, ROW_NUM });
    // You can use a few heuristics : manhattan, euclidean or octagonal.
    this->generator.setHeuristic(AStar::Heuristic::euclidean);
    this->generator.setDiagonalMovement(false);

    // TODO set this srand to time for more randomly
    srand(0);
    std::fill_n(&matrix[0][0], sizeof(matrix) / sizeof(matrix[0][0]),
        Cell{ BallState::EMPTY, BallType::BALL_TYPE_NONE, sf::Vector2f(0, 0), nullptr });
    // Init cells value
    auto adjust_mid = (TILE_SIZE - BALL_SIZE) / 2;
    // i -> x, j -> y
    for (int i = 0; i < COL_NUM; i++) {
        for (int j = 0; j < ROW_NUM; j++) {
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
                this->object_list.push_back(new_ball);
                matrix[i][j].p_ball = new_ball;
                this->generator.addCollision({ i, j });
            }
            else {
                matrix[i][j].p_ball = nullptr;
            }

            std::cout << std::endl;
        }
    }

    // Add tile map
    auto tile_map = std::make_shared<TileMap>(sf::Vector2f(0.0f, 0.0f), ROW_NUM + 1, COL_NUM + 1, 1.0 * TILE_SIZE);
    this->object_list.push_back(tile_map);
}

void Game::update() {
    // std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
}

void Game::printConsole() {
    for (auto& col : matrix) {
        for (auto& elem : col) {
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
        << "clock=" << this->clock.getElapsedTime().asMilliseconds() << std::endl
        << "pre.x=" << this->selecting_cell.first
        << "pre.y=" << this->selecting_cell.second << std::endl;
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
                // Remove previous active ball
                if ((this->selecting_cell.first != -1) && (this->selecting_cell.second != -1)) {
                    auto p = matrix[this->selecting_cell.first][this->selecting_cell.second].p_ball;
                    if (p) {
                        p->setSelect(false);
                    }
                    else {
                        std::cout << "NULL" << std::endl;
                    }
                }
                matrix[i][j].state = BallState::ACTIVE_BALL;
                matrix[i][j].p_ball->setSelect(true);
                this->selecting_cell = std::make_pair(i, j);
            }
            else { // BallState::EMPTY
                this->updateMovingPath(this->selecting_cell.first, this->selecting_cell.second, i, j);
            }
            this->clock.restart();
            this->selecting_position.x = x;
            this->selecting_position.y = y;
        }
    }
}

void Game::updateMovingPath(int start_x, int start_y, int end_x, int end_y)
{
    std::cout << "Generate path from " << start_x << "." << start_y << " to "
        << end_x << "." << end_y << std::endl;
    // This method returns vector of coordinates from target to source.
    auto result_path = this->generator.findPath({ start_x, start_y }, { end_x, end_y });

    for (auto& coordinate : result_path) {
        std::cout << coordinate.x << " " << coordinate.y << "\n";
    }

    auto result_node = result_path.begin();
    if ((result_node->x == end_x) && result_node->y == end_y) {
        this->moving_path = result_path;
    }
    else {
        std::cout << "Cannot find path to destination" << std::endl;
    }
}

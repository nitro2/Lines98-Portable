#include <iostream>

#include "game.hpp"

// Constructor
Game::Game() {
    std::vector<std::vector<CellState> > matrix(ROW_NUM, std::vector<CellState>(COL_NUM, CellState::EMPTY));
}
// Destructor
Game::~Game() {

}


void Game::init() {
    // std::fill(matrix.begin(), matrix.end(), CellState::BALL);
}

void Game::update() {
    std::cout << "nngo debug";
    for (auto elem: matrix) {
        std::cout << "d"  << " ";
    }
}


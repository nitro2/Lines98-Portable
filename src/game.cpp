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
    std::fill_n(&matrix[0][0], sizeof(matrix)/sizeof(matrix[0][0]), CellState::EMPTY);
}

void Game::update() {
    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
    std::cout << sizeof(matrix) << std::endl;
    for (auto& row: matrix) {
        for (auto& elem: row) {
            std::cout << elem  << " " << std::endl;
        }
    }
}


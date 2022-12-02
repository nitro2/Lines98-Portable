#ifndef  _GAME_HPP_
#define _GAME_HPP_

#include <vector>
#include <memory>

#include "ball.hpp"
#include "map.hpp"
// Game class
class Game {
public:
    // Constructor
    Game();
    // Destructor
    ~Game();

    // Initilize bitmap and game states
    void init();
    // Game logic update
    void update();
    int* getMatrix();
    void printConsole();

    void draw(sf::RenderWindow& window);

private:
    static const int COL_NUM = 2;
    static const int ROW_NUM = 2;
    static const int TILE_SIZE = 50;
    static const int BALL_SIZE = 40;

    enum BallState {
        EMPTY = 0,
        BALL,
    };
    enum BallType {
        BALL_TYPE_NONE,
        BALL_TYPE_1,
        BALL_TYPE_2,
        BALL_TYPE_3,
        BALL_TYPE_4,
        BALL_TYPE_5,
        BALL_TYPE_6,
    };

    typedef struct Cell {
        BallState state;
        BallType type;
        sf::Vector2f pos;
    } Cell;

    Cell matrix[ROW_NUM][COL_NUM];

    // std::vector<std::shared_ptr<Ball>> object_list;
    std::vector<Ball*> object_list;

};

#endif // _GAME_HPP_

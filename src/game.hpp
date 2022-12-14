#ifndef  _GAME_HPP_
#define _GAME_HPP_

#include <vector>
#include <memory>
#include <map>

#include <SFML/Graphics.hpp>

#include "a_star.hpp"
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
    void setClickPosition(int x, int y);
    void printConsole();

    void draw(sf::RenderWindow& window);

private:
    static const int COL_NUM = 10;
    static const int ROW_NUM = 10;
    static const int TILE_SIZE = 100;
    static const int BALL_SIZE = 70;

    enum BallState {
        EMPTY = 0,
        INACTIVE_BALL,
        ACTIVE_BALL
    };
    enum BallType {
        BALL_TYPE_NONE,
        BALL_TYPE_1,
        BALL_TYPE_2,
        BALL_TYPE_3,
        BALL_TYPE_4,
        BALL_TYPE_5,
        BALL_TYPE_6,
        MAX_BALLTYPE
    };

    typedef struct Cell {
        BallState state;
        BallType type;
        sf::Vector2f pos;
        std::shared_ptr<Ball> p_ball;
    } Cell;

    Cell matrix[COL_NUM][ROW_NUM];

    std::map<BallType, sf::Color> ColorDict = {
        {BALL_TYPE_NONE, sf::Color::White},
        {BALL_TYPE_1, sf::Color::Red},
        {BALL_TYPE_2, sf::Color::Yellow},
        {BALL_TYPE_3, sf::Color::Green},
        {BALL_TYPE_4, sf::Color::Blue},
        {BALL_TYPE_5, sf::Color::Cyan},
        {BALL_TYPE_6, sf::Color::Magenta},
    };


    std::vector<std::shared_ptr<sf::Drawable>> object_list;

    static const int CLICK_DELAY = 500; // 100ms
    std::pair<int, int> selecting_cell;
    sf::Vector2i selecting_position;

    sf::Clock clock;

    AStar::Generator generator;
    AStar::CoordinateList moving_path;
    void updateMovingPath(int start_x, int start_y, int end_x, int end_y);
};

#endif // _GAME_HPP_

#ifndef  _GAME_HPP_
#define _GAME_HPP_


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

private:
    static const int COL_NUM = 10;
    static const int ROW_NUM = 10;

    enum CellState {
        EMPTY = 0,
        BALL,
        SELECT_BALL
    };

    CellState matrix[ROW_NUM][COL_NUM];

};

#endif // _GAME_HPP_

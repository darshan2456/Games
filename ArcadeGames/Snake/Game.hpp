#pragma once

#include "Position.hpp"
#include "Ground.hpp"
#include "Snake.hpp"

class Game{
    private:
        static constexpr int CELL_SIZE=20;
        static constexpr double MOVE_INTERVAL=0.15;

        Ground ground;
        Snake snake;

        bool gameOver;
        int score;

        double lastMoveTime;

        void handleInput();
        void update();
        void draw();

    public:

        Game();
        void run();
};

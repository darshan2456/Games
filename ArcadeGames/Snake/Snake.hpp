#pragma once

#include "Position.hpp"
#include <deque>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake{
    private:
        std::deque<Position> body;
        Direction direction;
    public:
        Snake();

        void move(bool shouldGrow=false);
        void changeDirection(Direction newDirection);
        bool checkSelfCollision() const;
        void reset();

        const std::deque<Position>& getBody() const;
};

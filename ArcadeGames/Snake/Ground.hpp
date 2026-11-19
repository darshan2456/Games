#pragma once

#include "Position.hpp"

#include <deque>
#include <random>


class Ground{
    private:
        int columns;
        int rows;

        Position food;
        std::mt19937 rng;

    public:
        Ground(int columns=40, int rows=30);
        bool spawnFood(const std::deque<Position>& snakeBody);

        Position getFoodPosition() const;

        int getColumns() const;
        int getRows() const;

        bool isInside(Position position) const;
};

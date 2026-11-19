
#include "Ground.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

Ground::Ground(int columns, int rows)
    : columns(columns), rows(rows), food{0, 0}, rng(std::random_device{}()) {

    if (columns <= 0 || rows <= 0) {
        throw std::invalid_argument("Ground dimensions must be positive");
    }
}

bool Ground::spawnFood(const std::deque<Position>& snakeBody) {
    std::vector<Position> availableCells;

    // Find every cell that isn't occupied by the snake.
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < columns; x++) {

            Position candidate{x, y};

            bool occupied = std::any_of(
                snakeBody.begin(),
                snakeBody.end(),
                [&candidate](const Position& segment) {
                    return segment.x == candidate.x &&
                           segment.y == candidate.y;
                }
            );

            if (!occupied) {
                availableCells.push_back(candidate);
            }
        }
    }

    // No available cells means the board is full.
    if (availableCells.empty()) {
        return false;
    }

    // Select a random available cell.
    std::uniform_int_distribution<std::size_t> distribution(
        0, availableCells.size() - 1
    );

    food = availableCells[distribution(rng)];

    return true;
}

bool Ground::isInside(Position position) const {
    return position.x >= 0 &&
           position.x < columns &&
           position.y >= 0 &&
           position.y < rows;
}

Position Ground::getFoodPosition() const {
    return food;
}

int Ground::getColumns() const {
    return columns;
}

int Ground::getRows() const {
    return rows;
}

#pragma once

#include <array>

class Board{
    private:
        std::array<std::array<char, 7>, 6> grid;
    public:
        bool makeMove(int col, char symbol);
        void display() const;
        bool checkWinner(char symbol) const;
}

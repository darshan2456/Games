#pragma once

#include <array>

class Board{
    private:
        std::array<std::array<char, 3>, 3> grid;
    public:
        Board();

        //board operations
        void display() const;
        bool makeMove(int row,int col,char symbol);
        bool checkWinner(char symbol) const;
        bool isFull() const;
        void reset();
};

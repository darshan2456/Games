#pragma once

#include <array>

class Board{
    private:
        std::array<std::array<char, 3>, 3> board;
    public:
        Board();

        //board operations
        void display() const;
        bool make_move(int row,int col,char symbol);
        bool check_winner(char symbol) const;
        bool is_full() const;
        void reset();
};

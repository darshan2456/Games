#pragma once

#include <array>

namespace  ConnectFourGame {

    class Board{
    private:
            std::array<std::array<char, 7>, 6> grid;
            int lastPlacedRow = -1;
            int lastPlacedColumn = -1;

            int countConnected(int row, int col, int dr, int dc) const;
    public:
            Board();
            void display() const;
            bool dropDisk(int col, char symbol);
            bool isFull() const;
            char checkWin() const;
            void reset();
    };

}

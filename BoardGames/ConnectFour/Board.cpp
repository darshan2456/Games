#include "Board.hpp"
#include <iostream>

Board::Board(){
    reset();
}

void Board::reset(){
    lastPlacedColumn=-1;
    lastPlacedRow=-1;

    std::array<char, 7> dummy;
    dummy.fill(' ');

    grid.fill(dummy);
}


void Board::display() const{
    for(const auto& row:grid){
        for(const auto& cell:row){
            std::cout << "| " << cell << " |";
        }

        std::cout<<"_____________________\n";
    }
}

bool Board::isFull() const{
    for(int col=0; col<7; col++){
        if(grid[0][col]==' '){
            return false;
        }
    }

    return true;
}


bool Board::dropDisk(int col, char symbol){

    if(col<0 || col>6){
        return false;
    }

    for(int i=5;i>=0;i--){
        if(grid[i][col]==' '){
            grid[i][col]=symbol;

            lastPlacedColumn=col;
            lastPlacedRow=i;
            return true;
        }
    }

    return false;
}

//helper function for checkWin
int Board::countConnected(int row, int col, int dr, int dc) const {
    if (row < 0 || row >= 6 || col < 0 || col >= 7) {
        return 0;
    }

    int counter = 0;
    char symbol = grid[row][col];

    while (1) {
        int nextRow = row + dr;
        int nextCol = col + dc;

        if (nextRow < 0 || nextRow >= 6 ||
            nextCol < 0 || nextCol >= 7) {
            break;
        }

        if (grid[nextRow][nextCol] != symbol) {
            break;
        }

        row = nextRow;
        col = nextCol;
        counter++;
    }

    return counter;
}

char Board::checkWin() const{
    // case1 = north + south
    // case 2 = east + west
    // case 3 = southeast + northwest
    // case 4 = southwest + northeast

    if(lastPlacedRow==-1 || lastPlacedColumn==-1){
        return ' ';
    }

    char symbol = grid[lastPlacedRow][lastPlacedColumn];

    int north=countConnected(lastPlacedRow, lastPlacedColumn, -1, 0);
    int south=countConnected(lastPlacedRow, lastPlacedColumn, 1, 0);

    int case1=1+north+south;

    if(case1>=4){
        return symbol;
    }

    int east=countConnected(lastPlacedRow, lastPlacedColumn, 0, 1);
    int west=countConnected(lastPlacedRow, lastPlacedColumn, 0, -1);

    int case2=1+east+west;

    if(case2 >=4){
        return symbol;
    }

    int southeast=countConnected(lastPlacedRow, lastPlacedColumn, 1, 1);
    int northwest=countConnected(lastPlacedRow, lastPlacedColumn, -1, -1);

    int case3=1+southeast+northwest;

    if(case3 >=4){
        return symbol;
    }

    int southwest=countConnected(lastPlacedRow, lastPlacedColumn, 1, -1);
    int northeast=countConnected(lastPlacedRow, lastPlacedColumn, -1, 1);

    int case4=1+southwest+northeast;

    if(case4 >=4){
        return symbol;
    }


    return ' ';
}

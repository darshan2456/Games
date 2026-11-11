#include <iostream>

#include "Board.hpp"

//constructor
Board::Board(){
    reset();
}

void Board::display() const{
    std::cout<<"---------------\n";

    for(const auto& row:grid){
        for(const auto& cell:row){
            if(cell=='O'){
                std::cout<< "|\033[33m O \033[0m|";
            }
            else if(cell=='X'){
                std::cout<< "|\033[32m X \033[0m|";
            }
            else{
                std::cout<< "| " << cell << " |";
            }
        }

        std::cout<<"\n---------------\n";
    }
}

//return false if invalid position or position already occupied, otherwise places the symbol and return true;
bool Board::makeMove(int row, int col, char symbol){
    if(row<0 || row>2 || col<0 || col>2){       //invalid position
        return false;
    }

    if(grid[row][col]=='X' || grid[row][col]=='O'){            //position already occupied
        return false;
    }

    grid[row][col]=symbol;

    return true;
}

bool Board::checkWinner(char symbol) const{

    //row wise checking
    for(int i=0;i<3;i++){
        if(grid[i][0]==symbol && grid[i][1]==symbol && grid[i][2]==symbol){
            return true;
        }
    }

    //column wise checking
    for(int i=0;i<3;i++){
        if(grid[0][i]==symbol && grid[1][i]==symbol && grid[2][i]==symbol){
            return true;
        }
    }

    //diagonal wise checking
    if((grid[0][0]==symbol && grid[1][1]==symbol && grid[2][2]==symbol) || (grid[0][2]==symbol && grid[1][1]==symbol && grid[2][0]==symbol)){
        return true;
    }

    return false;
}


bool Board::isFull() const{
    for(const auto& row:grid){
        for(const auto& cell:row){
            if(cell!='X' && cell!='O'){
                return false;
            }
        }
    }

    return true;
}

void Board::reset(){
    char pos='1';

    for(auto& row:grid){
        for(auto& cell:row){
            cell=pos++;
        }
    }
}

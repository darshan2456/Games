#include <iostream>

#include "Board.hpp"

//constructor
Board::Board(){
    reset();
}

void Board::display() const{
    std::cout<<"------------------------------\n";

    for(const auto& row:board){
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

        std::cout<<"-------------------------------\n";
    }
}

//return false if invalid position or position already occupied, otherwise places the symbol and return true;
bool Board::make_move(int row, int col, char symbol){
    if(row<0 || row>2 || col<0 || col>2){       //invalid position
        return false;
    }

    if(board[row][col]=='X' || board[row][col]=='O'){            //position already occupied
        return false;
    }

    board[row][col]==symbol;

    return true;
}

bool Board::check_winner(char symbol) const{

    //row wise checking
    for(int i=0;i<3;i++){
        if(board[i][0]==symbol && board[i][1]==symbol && board[i][2]==symbol){
            return true;
        }
    }

    //column wise checking
    for(int i=0;i<3;i++){
        if(board[1][i]==symbol && board[2][i]==symbol && board[3][i]==symbol){
            return true;
        }
    }

    //diagonal wise checking
    if((board[0][0]==symbol && board[1][1]==symbol && board[2][2]==symbol) || (board[0][2]==symbol && board[1][1]==symbol && board[2][0]==symbol)){
        return true;
    }

    return false;
}


bool Board::is_full() const{
    for(const auto& row:board){
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

    for(auto& row:board){
        for(auto& cell:row){
            cell=pos++;
        }
    }
}

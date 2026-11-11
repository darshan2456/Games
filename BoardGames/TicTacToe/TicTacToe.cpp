#include <iostream>
#include <string>
#include "clearScreen.hpp"
#include "safeInput.hpp"
#include "TicTacToe.hpp"


TicTacToe::TicTacToe() : player1("Player1",'X'), player2("Player2",'O'){
    this->gameover=false;
}

void TicTacToe::displayInstructions() const{
    std::cout << "\n===================================\n\n";
    std::cout << "Welcome to tic tac toe multiplayer\n\n";

    std::cout << "These are the positions corresponding to the given numbers:-\n";

    std::cout << "-------------\n";
    std::cout << "| 1 | 2 | 3 |\n";
    std::cout << "-------------\n";
    std::cout << "| 4 | 5 | 6 |\n";
    std::cout << "-------------\n";
    std::cout << "| 7 | 8 | 9 |\n";
    std::cout << "-------------\n";

    std::cout << "Rules are the same as normal. Enjoy the game!!!\n\n";
}

bool TicTacToe::getPlayerNames(){
    std::string name1;
    std::string name2;

    while(1){

        //infinite loop to take first player name
        while(1){
            int status=safeInputString(name1, "Enter name of first player (20 chars max, enter 'X' to exit):- ", 20);

            if(status==0){
                continue;
            }

            if(status==INPUT_EOF_SIGNAL || status==INPUT_EXIT_SIGNAL){
                std::cout<<"\nExiting tic tac toe multiplayer....\n\n";
                return false;
            }

            break;
        }

        //infinite loop to take second player name
        while(1){
            int status=safeInputString(name2, "Enter name of second player (20 chars max, enter 'X' to exit):- ", 20);

            if(status==0){
                continue;
            }

            if(status==INPUT_EOF_SIGNAL || status==INPUT_EXIT_SIGNAL){
                std::cout<<"\nExiting tic tac toe multiplayer....\n\n";
                return false;
            }

            break;
        }


        if(name1==name2){
            std::cout<<"Both player names cannot be same. Try again.\n\n";
            continue;
        }

        player1 = Player(name1, 'X');
        player2 = Player(name2, 'O');

        return true;
    }
}


bool TicTacToe::playTurn(const Player &curr_player){
    while(1){
        int choice;

        std::cout<<curr_player.getName() << "'s turn:- ";

        int status=safeInputInt(choice, "\nEnter here:- ", 1, 9);

        if(status==INPUT_EXIT_SIGNAL || status==INPUT_EOF_SIGNAL){
            std::cout<<"\nExiting tic tac toe multiplayer....\n\n";
            return false;
        }

        if(status==0){
            std::cout<<"Invalid input. Try again\n";
            continue;
        }

        //convert choice into rows and columns
        int row=(choice-1)/3;
        int col=(choice-1)%3;

        if(!board.makeMove(row, col, curr_player.getSymbol())){
            std::cout << "Position already filled. Try again.\n\n";
            continue;
        }

        clearScreen();
        board.display();

        return true;
    }
}


void TicTacToe::playComputer(){
    std::cout<<"\nComing soon.....\n\n";
}

void TicTacToe::playMultiplayer(){
    while(1){
        board.reset();
        gameover=false;

        displayInstructions();

        if(!getPlayerNames()){
            return;
        }

        clearScreen();
        board.display();

        //true=player1's turn
        //false=player2's turn
        bool player1Turn=true;

        //game loop
        while(!gameover && !board.isFull()){
            const Player& currentPlayer = player1Turn ? player1 : player2;

            if(!playTurn(currentPlayer)){
                return;
            }

            //check whether current player won
            if(board.checkWinner(currentPlayer.getSymbol())){
                std::cout<<"\n"<<currentPlayer.getName()<<" won!!!\n";
                gameover=true;
                break;
            }

            //toggle variable to pass turns between each player
            player1Turn=!player1Turn;
        }

        if(!gameover){
            std::cout<<"\nGame Draw\n";
        }

        std::cout<<"----------------------------------";
    }
}

//main TicTacToe launcher
void TicTacToe::startGame(){
    while(1){
        int mode;

        int status=safeInputInt(mode, "\nEnter 1 for computer and 2 for multiplayer:- ", 1, 2);

        if(status==0){
            continue;
        }

        if(status==INPUT_EXIT_SIGNAL || status==INPUT_EOF_SIGNAL){
            std::cout<<"\nExiting tic tac toe.....\n\n";
            return;
        }

        if(mode==1){
            playComputer();
        }
        else if(mode==2){
            playMultiplayer();
        }
    }
}

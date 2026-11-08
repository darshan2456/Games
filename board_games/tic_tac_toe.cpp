#include <array>
#include <iostream>
#include <string>
#include "clear_screen.hpp"
#include "safe_input.hpp"
#include "tic_tac_toe.hpp"


void display_board_ttt(const Board& board){
    std::cout << "---------------\n";
    for (const auto& row : board) {

            for (char cell : row) {

                if (cell == 'O') {
                    std::cout << "|\033[33m O \033[0m|";
                }
                else if (cell == 'X') {
                    std::cout << "|\033[32m X \033[0m|";
                }
                else {
                    std::cout << "| " << cell << " |";
                }
            }

            std::cout << "\n--------------\n";
        }
}

int who_won(const Board& arr){
    //row wise checking for player 1
    if( (arr[0][0]=='X' && arr[0][1]=='X' && arr[0][2]=='X') || (arr[1][0]=='X' && arr[1][1]=='X' && arr[1][2]=='X') || (arr[2][0]=='X' && arr[2][1]=='X' && arr[2][2]=='X') ){
        return 1;
    }
    //col wise checking for player 1
    else if( (arr[0][0]=='X' && arr[1][0]=='X' && arr[2][0]=='X') || (arr[0][1]=='X' && arr[1][1]=='X' && arr[2][1]=='X') || (arr[0][2]=='X' && arr[1][2]=='X' && arr[2][2]=='X') ){
        return 1;
    }
    //diagonal checking for player 1
    else if( (arr[0][0]=='X' && arr[1][1]=='X' && arr[2][2]=='X') || (arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X') ){
        return 1;
    }


    //row wise checking for player 2
    if( (arr[0][0]=='O' && arr[0][1]=='O' && arr[0][2]=='O') || (arr[1][0]=='O' && arr[1][1]=='O' && arr[1][2]=='O') || (arr[2][0]=='O' && arr[2][1]=='O' && arr[2][2]=='O') ){
        return 2;
    }
    //col wise checking for player 2
    else if( (arr[0][0]=='O' && arr[1][0]=='O' && arr[2][0]=='O') || (arr[0][1]=='O' && arr[1][1]=='O' && arr[2][1]=='O') || (arr[0][2]=='O' && arr[1][2]=='O' && arr[2][2]=='O') ){
        return 2;
    }
    //diagonal checking for player 2
    else if( (arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O') || (arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O') ){
        return 2;
    }

    return 0;
}

void ttt_launcher(){
    while(1){
        int mode;
        while(1){
            std::cout << "\n==============================\n\nWelcome to tic tac toe!!!\n";
            int mode_status=safe_input_int(mode,"\nEnter 1 for computer and 2 for multiplayer:- ",1,2);
            if(mode_status==0){
                continue;
            }
            else if(mode_status==INPUT_EXIT_SIGNAL || mode_status==INPUT_EOF_SIGNAL){
                std::cout << "\nExiting tic tac toe.....\n\n";
                return;
            }
            break;
        }

        if(mode==1){
            ttt_computer();
        }
        else if(mode==2){
            ttt_multiplayer();
        }
    }
}

void ttt_computer(){
    std::cout << "\nComing soon....\n\n" ;
    return;
}

void ttt_multiplayer(){

    while (1)
    {

        Board board{{
            {{'1', '2', '3'}},
            {{'4', '5', '6'}},
            {{'7', '8', '9'}}
        }};

        std::cout << "\n===================================\n\nWelcome to tic tac toe multiplayer\n\n";
        std::cout << "These are the positions corresponding to the given numbers:-\n";
        std::cout << "-----------\n";
        std::cout << "- 1  2  3 -\n";
        std::cout << "- 4  5  6 -\n";
        std::cout << "- 7  8  9 -\n";
        std::cout << "-----------\n";
        std::cout << "Rules are the same as normal. Enjoy the game!!!\n\n";



        //taking name of the players
        std::string player1;
        std::string player2;

        input_start:

        while(1){
            int player_1_status=safe_input_string(player1,"enter name of first player, (20 chars max, enter 'X' to exit):-",19);

            if(player_1_status==0){
                continue;
            }

            if(player_1_status==INPUT_EXIT_SIGNAL || player_1_status==INPUT_EOF_SIGNAL){
                std::cout << "\nExiting tic tac toe multiplayer....\n\n";
                return;
            }

            break;
        }

        while(1){
            int player_2_status=safe_input_string(player2,"enter name of second player, (20 chars max, enter 'X' to exit):-",19);

            if(player_2_status==0){
                continue;
            }

            if(player_2_status==INPUT_EXIT_SIGNAL || player_2_status==INPUT_EOF_SIGNAL){
                std::cout << "\nExiting tic tac toe multiplayer....\n\n";
                return;
            }

            break;
        }

        if(player1==player2){
            std::cout << "both player names cant be same. Try again\n\n";
            goto input_start;
        }



        //setting up state variables
        bool gameover=false;
        int winner=0;


        clear_screen();
        display_board_ttt(board);

        //actual game loop
        for(int i=0;i<9;i++){

            if(gameover)    break;
            retry:
            int choice;
            char xo;

            if(i%2==0){
                xo='X';
                std::cout << player1 << "'s turn:- ";
            }
            else{
                xo='O';
                std::cout << player2 << "'s turn:- ";
            }

            int choice_status=safe_input_int(choice,"\nenter here:- ",1,9);

            if(choice_status==INPUT_EXIT_SIGNAL || choice_status==INPUT_EOF_SIGNAL){
                std::cout << "\nExiting tic tac toe multiplayer....\n\n";
                return;
            }
            else if(choice_status==0){
                std::cout << "Invalid input, Try again";
                goto retry;
            }

            int row=(choice-1)/3;
            int col=(choice-1)%3;

            if(board[row][col]=='X' || board[row][col]=='O'){
                std::cout << "Position already filled. Try again\n\n";
                goto retry;
            }

            //marks X or O on the actual board
            board[row][col]=xo;

            clear_screen();
            display_board_ttt(board);

            winner=who_won(board);
            if(winner==1){
                std::cout << player1 << " won!!!";
                gameover=true;
            }
            else if(winner==2){
                std::cout << player2 << " won!!!";
                gameover=true;
            }

        }

        if(!gameover)   std::cout << "\nGame draw\n";

        std::cout << "\n\n========================================";

    }
}

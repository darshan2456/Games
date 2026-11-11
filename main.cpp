#include <iostream>

#include "BoardGames/TicTacToe/TicTacToe.hpp"
#include "BoardGames/ConnectFour/ConnectFour.hpp"
#include "safeInput.hpp"

int main() {

    while (1) {

        int game_choice;

        int game_status = safeInputInt(
            game_choice,
            "Welcome to Games by Darshan Mukul Parekh\n"
            "(At any point, press '-1' to exit that particular stage)\n\n"
            "Press '1' to play Tic Tac Toe\n"
            "Press '2' to play Connect Four\n"
            "Press '-1' to exit\n"
            "Enter here:- ",
            1,
            2
        );

        if (game_status == INPUT_EXIT_SIGNAL ||
            game_status == INPUT_EOF_SIGNAL) {
            return 0;
        }

        if (game_status == 0) {
            continue;
        }

        switch (game_choice) {

            case 1: {
                TicTacToe game;
                game.startGame();
                break;
            }

            case 2:
                launcher();
                break;

            default:
                std::cout<<"\nInvalid choice lol. Try again\n\n";
        }
     }

}

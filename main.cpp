#include <iostream>

#include "board_games/tic_tac_toe/Player.hpp"
#include "board_games/tic_tac_toe/tic_tac_toe.hpp"
#include "love.hpp"
#include "safe_input.hpp"
#include "Player.hpp"

int main() {

//     while (true) {
//
//         int game_choice;
//
//         int game_status = safe_input_int(
//             game_choice,
//             "Welcome to 'Games' by Darshan Mukul Parekh\n"
//             "(At any point, press '-1' to exit that particular stage)\n\n"
//             "Press '1' to play tic tac toe\n"
//             "Press '2' to play the love game\n"
//             "Press '-1' to exit\n"
//             "Enter here:- ",
//             1,
//             2
//         );
//
//         if (game_status == INPUT_EXIT_SIGNAL ||
//             game_status == INPUT_EOF_SIGNAL) {
//             return 0;
//         }
//
//         if (game_status == 0) {
//             continue;
//         }
//
//         switch (game_choice) {
//
//             case 1:
//                 ttt_launcher();
//                 break;
//
//             case 2:
//                 love();
//                 break;
//         }
//      }

        Player p1("akash", 'O');
        std::cout<<p1.getName()<<std::endl;
        std::cout<<p1.getSymbol()<<std::endl;
}

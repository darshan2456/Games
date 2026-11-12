#include <iostream>
#include <string>
#include "ConnectFour.hpp"
#include "Player.hpp"
#include "clearScreen.hpp"
#include "safeInput.hpp"

namespace ConnectFourGame {

ConnectFour::ConnectFour(): player1("Player1", 'R'), player2("Player2", 'Y'){

}

void ConnectFour::displayInstructions() {
    std::cout << "\n===================================\n\n";
    std::cout << "Welcome to Connect Four Multiplayer!\n\n";

    std::cout << "Players take turns dropping discs into columns.\n";
    std::cout << "Connect four consecutive discs horizontally,\n";
    std::cout << "vertically or diagonally to win!\n\n";

    std::cout << "Column positions:\n\n";
    std::cout << "0   1   2   3   4   5   6\n\n";

    std::cout << "Player 1: R (Red)\n";
    std::cout << "Player 2: Y (Yellow)\n\n";

    std::cout << "Enter -1 anytime to exit.\n\n";
}

bool ConnectFour::getPlayerNames() {
    std::string name1;
    std::string name2;

    while (true) {

        while (true) {
            int status = safeInputString(
                name1,
                "Enter name of first player: ",
                20
            );

            if (status == 0) {
                continue;
            }

            if (status == INPUT_EXIT_SIGNAL ||
                status == INPUT_EOF_SIGNAL) {
                return false;
            }

            break;
        }

        while (true) {
            int status = safeInputString(
                name2,
                "Enter name of second player: ",
                20
            );

            if (status == 0) {
                continue;
            }

            if (status == INPUT_EXIT_SIGNAL ||
                status == INPUT_EOF_SIGNAL) {
                return false;
            }

            break;
        }

        if (name1 == name2) {
            std::cout << "Names cannot be identical. Try again.\n\n";
            continue;
        }

        player1 = Player(name1, 'R');
        player2 = Player(name2, 'Y');

        return true;
    }
}

void ConnectFour::playMultiplayer(){
    while(1){
        board.reset();

        displayInstructions();

        if(!getPlayerNames()){
            return;
        }

        clearScreen();
        board.display();

        bool player1Turn=true;
        bool gameover=false;

        //main game loop
        while(!gameover && !board.isFull()){
            const Player& currentplayer=player1Turn? player1 : player2;

            int col;

            std::cout<<"\n"<<currentplayer.getName()<<"'s turn"<<"\n\n";

            int status=safeInputInt(col,  "\nEnter column (0-6): ", 0, 6);

            if (status == INPUT_EXIT_SIGNAL || status == INPUT_EOF_SIGNAL) {
                std::cout << "\nExiting Connect Four...\n";
                return;
            }

            if (status == 0) {
                std::cout << "Invalid input. Try again.\n";
                continue;
            }

            if(!board.dropDisk(col, currentplayer.getSymbol())){
                std::cout<< "\nColumn is full. Choose another column\n\n";
                continue;
            }

            clearScreen();
            board.display();

            char winner = board.checkWin();

            if(winner!=' '){
                std::cout << "\n" << currentplayer.getName() << " won";
                gameover=true;
                break;
            }

            //switch turns with a boolean variable toggle
            player1Turn = !player1Turn;
        }

        if(!gameover){
            std::cout<< "\nGame Draw!\n";
        }

        std::cout << "\n----------------------------------\n";

    }
}

void ConnectFour::playComputer() {
    std::cout << "\nComputer mode coming soon...\n\n";
}



void ConnectFour::startGame() {

    while (true) {

        int mode;

        int status = safeInputInt(
            mode,
            "\nEnter 1 for computer and 2 for multiplayer: ",
            1,
            2
        );

        if (status == 0) {
            continue;
        }

        if (status == INPUT_EXIT_SIGNAL ||
            status == INPUT_EOF_SIGNAL) {
            std::cout << "\nExiting Connect Four...\n";
            return;
        }

        if (mode == 1) {
            playComputer();
        }
        else {
            playMultiplayer();
        }
    }
}

}

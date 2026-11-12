#pragma once

#include "Player.hpp"
#include "Board.hpp"

namespace ConnectFourGame {

    class ConnectFour{
        private:
            Board board;
            Player player1;
            Player player2;
        public:
            ConnectFour();
            void startGame();
            void displayInstructions();
            bool getPlayerNames();
            void playMultiplayer();
            void playComputer();
    };

}

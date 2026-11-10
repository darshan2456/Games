#pragma once

#include <string>

#include "Player.hpp"
#include "Board.hpp"

class TicTacToe{
    private:
        Board board;
        Player player1;
        Player player2;

        //boolean variable to maintain state of the game
        bool gameover;

        void  displayInstructions() const;
        bool getPlayerNames();
        bool playTurn(const Player& curr_player);
        void playMultiplayer();
        void playComputer();

    public:
        TicTacToe();
        void startGame();
};

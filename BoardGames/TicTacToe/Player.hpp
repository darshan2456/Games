#pragma once

#include <string>

namespace TicTacToeGame {


    class Player{
        private:
            std::string name;
            char symbol;
        public:
            Player(const std::string& name, char symbol);
            //getter methods
            std::string getName() const;
            char getSymbol() const;
    };

}

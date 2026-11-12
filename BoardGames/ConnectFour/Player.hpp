#pragma once

#include <string>

namespace ConnectFourGame {

    class Player{
        private:
            std::string name;
            char symbol;
        public:
            Player(const std::string& name, char symbol);
            std::string getName() const;
            char getSymbol() const;
    };

}

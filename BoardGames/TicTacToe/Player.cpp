#include <string>

#include "Player.hpp"

namespace TicTacToeGame {

    Player::Player(const std::string& name, char symbol){
        this->name=name;
        this->symbol=symbol;
    }

    //getter functions for name and symbol

    std::string Player::getName() const{
        return name;
    }

    char Player::getSymbol() const{
        return symbol;
    }

}

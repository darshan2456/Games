#include <string>

#include "Player.hpp"

Player::Player(const std::string& name, char symbol){
    this->name=name;
    this->symbol=symbol;
}

std::string Player::getName() const{
    return name;
}

char Player::getSymbol() const{
    return symbol;
}

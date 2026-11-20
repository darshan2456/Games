#include "Snake.hpp"
#include "Position.hpp"
#include <cstddef>
#include <deque>

Snake::Snake(){
    reset();
}

void Snake::move(bool shouldGrow){
    Position newhead=body.front();

    switch (direction) {
        case Direction::UP:
            newhead.y--;
            break;
        case Direction::DOWN:
            newhead.y++;
            break;
        case Direction::LEFT:
            newhead.x--;
            break;
        case Direction::RIGHT:
            newhead.x++;
            break;
    }

    body.push_front(newhead);

    if(!shouldGrow){
        body.pop_back();
    }
}

void Snake::changeDirection(Direction newDirection){

    //prevents snake from reversing direction directly
    if ((direction == Direction::UP && newDirection == Direction::DOWN) ||
        (direction == Direction::DOWN && newDirection == Direction::UP) ||
        (direction == Direction::LEFT && newDirection == Direction::RIGHT) ||
        (direction == Direction::RIGHT && newDirection == Direction::LEFT)) {
        return;
    }

    direction=newDirection;
}

bool Snake::checkSelfCollision() const{
    const Position& head=body.front();

    //start from index 1 because 0 index is the head itself
    for(int i=1;i<body.size();i++){
        if(head.x==body[i].x && head.y==body[i].y){
            return true;
        }
    }

    return false;
}

void Snake::reset(){
    body.clear();

    body.push_back({10,10});
    body.push_back({9,10});
    body.push_back({8,10});

    direction=Direction::RIGHT;
}

const std::deque<Position>& Snake::getBody() const{
    return body;
}

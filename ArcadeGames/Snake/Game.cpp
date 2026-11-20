#include "Game.hpp"
#include "raylib.h"
#include <cstddef>

Game::Game() : ground(40,30), snake(), gameOver(false), score(0), lastMoveTime(0.0){
    ground.spawnFood(snake.getBody());
}

void Game::run(){
    InitWindow(800, 600, "Snake");

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        handleInput();

        if(!gameOver){
            update();
        }

        draw();
    }

    CloseWindow();
}

void Game::handleInput(){
    if(gameOver){
        return;
    }

    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
    snake.changeDirection(Direction::UP);
    }
    else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
        snake.changeDirection(Direction::DOWN);
    }
    else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
        snake.changeDirection(Direction::LEFT);
    }
    else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
        snake.changeDirection(Direction::RIGHT);
    }
}

void Game::update(){
    double currentTime=GetTime();

    if(currentTime-lastMoveTime < MOVE_INTERVAL){
        return;
    }

    lastMoveTime=currentTime;

    snake.move();

    const Position& head=snake.getBody().front();

    //check whether snake hit a wall
    if(!ground.isInside(head)){
        gameOver=true;
        return;
    }

    //check if snake ate the food
    if(head.x==ground.getFoodPosition().x && head.y==ground.getFoodPosition().y){
        score+=10;

        //we pass true to the shouldGrow argument so snake size grows.
        snake.move(true);

        //this means no cell available to generate food
        if(!ground.spawnFood(snake.getBody())){
            gameOver=true;
        }
    }


    //check for collision of snake with itself
    if(snake.checkSelfCollision()){
        gameOver=true;
    }
}

void Game::draw(){
    BeginDrawing();

    ClearBackground(BLACK);

    //draw ground grid
    for(int i=0;i<ground.getColumns();i++){
        for(int j=0;j<ground.getRows();j++){
            DrawRectangleLines(i*CELL_SIZE, j*CELL_SIZE, CELL_SIZE, CELL_SIZE, DARKGRAY);
        }
    }

    //retrieve food location and colour the cell red
    Position food=ground.getFoodPosition();
    DrawRectangle(food.x * CELL_SIZE, food.y * CELL_SIZE, CELL_SIZE, CELL_SIZE, RED);

    const auto& body=snake.getBody();

    //draw the snake.
    for(std::size_t i=0;i<body.size();i++){
        DrawRectangle(body[i].x * CELL_SIZE, body[i].y * CELL_SIZE, CELL_SIZE, CELL_SIZE, i==0 ? LIME : GREEN);
    }


    DrawText(TextFormat("Score: %d", score), 10, 10, 20, WHITE);

    if(gameOver){
        DrawText("Game Over", 330, 280, 30, RED);
    }

    EndDrawing();
}

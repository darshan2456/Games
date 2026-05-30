#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void display_board(char arr[3][3]){
    printf("---------\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("|%c|",arr[i][j]);
        }
        printf("\n---------\n");
    }
}

int who_won(char arr[3][3]){
    //row wise checking for player 1
    if(arr[0][0]=='X' && arr[0][1]=='X' && arr[0][2]=='X' || arr[1][0]=='X' && arr[1][1]=='X' && arr[1][2]=='X' || arr[2][0]=='X' && arr[2][1]=='X' && arr[2][2]=='X'){
        return 1;
    }
    //col wise checking for player 1
    else if(arr[0][0]=='X' && arr[1][0]=='X' && arr[2][0]=='X' || arr[0][1]=='X' && arr[1][1]=='X' && arr[2][1]=='X' || arr[0][2]=='X' && arr[1][2]=='X' && arr[2][2]=='X'){
        return 1;
    }
    //diagonal checking for player 1
    else if(arr[0][0]=='X' && arr[1][1]=='X' && arr[2][2]=='X' || arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X'){
        return 1;
    }


    //row wise checking for player 2
    if(arr[0][0]=='0' && arr[0][1]=='0' && arr[0][2]=='0' || arr[1][0]=='0' && arr[1][1]=='0' && arr[1][2]=='0' || arr[2][0]=='0' && arr[2][1]=='0' && arr[2][2]=='0'){
        return 2;
    }
    //col wise checking for player 1
    else if(arr[0][0]=='0' && arr[1][0]=='0' && arr[2][0]=='0' || arr[0][1]=='0' && arr[1][1]=='0' && arr[2][1]=='0' || arr[0][2]=='0' && arr[1][2]=='0' && arr[2][2]=='0'){
        return 2;
    }
    //diagonal checking for player 1
    else if(arr[0][0]=='0' && arr[1][1]=='0' && arr[2][2]=='0' || arr[0][2]=='0' && arr[1][1]=='0' && arr[2][0]=='0'){
        return 2;
    }
    
    return 0;
}

int main(){

    while (1)
    {
        int exit;
        printf("\n\n\nWelcome to tic tac toe game created by Darshan Mukul Parekh\n");
        printf("These are the marking positions:-\n");
        printf("-----------\n");
        printf("- 1  2  3 -\n");
        printf("- 4  5  6 -\n");
        printf("- 7  8  9 -\n");
        printf("-----------\n");
        printf("First one to play is Player no, 1 and has 'X'\n");
        printf("Rules are the same as normal. Enjoy the game!!!\n\n(To exit enter '-1', to continue enter any number)\n\n");
        printf("Enter here:- ");
        scanf("%d",&exit);

        if(exit==-1)    break;

        char board[3][3];
        int player=0;
        int winner=0;
        bool gameover=false;

        memset(board,' ',sizeof(board));

        for(int i=0;i<9;i++){
            if(gameover==true)    break;
            retry:
            int choice;
            char xo;

            if(i%2==0){
                xo='X';
                player=1;
            }
            else{
                xo='0';
                player=2;
            }

            printf("Player no %d's turn:- ",player);
            scanf("%d",&choice);

            switch(choice){
                case 1:
                    if(board[0][0]!=' '){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[0][0]=xo;
                    display_board(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("Player 1 won!!!");
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("Player 2 won!!!");
                        gameover=true;
                    }

                    break;

                case 2:
                    if(board[0][1]!=' '){
                        printf("position already filled. try again\n");
                        goto retry;
                    }


                    board[0][1]=xo;
                    display_board(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("Player 1 won!!!");
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("Player 2 won!!!");
                        gameover=true;
                    }

                    break;

                case 3:
                    if(board[0][2]!=' '){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[0][2]=xo;
                    display_board(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("Player 1 won!!!");
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("Player 2 won!!!");
                        gameover=true;
                    }

                    break;

                case 4:
                    if(board[1][0]!=' '){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[1][0]=xo;
                    display_board(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("Player 1 won!!!");
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("Player 2 won!!!");
                        gameover=true;
                    }

                    break;

                case 5:
                    if(board[1][1]!=' '){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[1][1]=xo;
                    display_board(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("Player 1 won!!!");
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("Player 2 won!!!");
                        gameover=true;
                    }

                    break;

                case 6:
                    if(board[1][2]!=' '){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[1][2]=xo;
                    display_board(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("Player 1 won!!!");
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("Player 2 won!!!");
                        gameover=true;
                    }

                    break;

                case 7:
                    if(board[2][0]!=' '){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[2][0]=xo;
                    display_board(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("Player 1 won!!!");
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("Player 2 won!!!");
                        gameover=true;
                    }

                    break;

                case 8:
                    if(board[2][1]!=' '){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[2][1]=xo;
                    display_board(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("Player 1 won!!!");
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("Player 2 won!!!");
                        gameover=true;
                    }

                    break;

                case 9:
                    if(board[2][2]!=' '){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[2][2]=xo;
                    display_board(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("Player 1 won!!!");
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("Player 2 won!!!");
                        gameover=true;
                    }

            }
        }

        if(!gameover)   printf("Game draw\n");

        printf("\n\n========================================");

    }
}   
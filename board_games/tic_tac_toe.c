#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "clear_screen.h"
#include "safe_input.h"

void display_board_ttt(char arr[3][3]){
    printf("---------------\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("| %c |",arr[i][j]);
        }
        printf("\n--------------\n");
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
    if(arr[0][0]=='O' && arr[0][1]=='O' && arr[0][2]=='O' || arr[1][0]=='O' && arr[1][1]=='O' && arr[1][2]=='O' || arr[2][0]=='O' && arr[2][1]=='O' && arr[2][2]=='O'){
        return 2;
    }
    //col wise checking for player 2
    else if(arr[0][0]=='O' && arr[1][0]=='O' && arr[2][0]=='O' || arr[0][1]=='O' && arr[1][1]=='O' && arr[2][1]=='O' || arr[0][2]=='O' && arr[1][2]=='O' && arr[2][2]=='O'){
        return 2;
    }
    //diagonal checking for player 2
    else if(arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O' || arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O'){
        return 2;
    }
    
    return 0;
}

void tic_tac_toe(){

    while (1)
    {
        int exit;
        printf("\n\n\nWelcome to tic tac toe\n");
        printf("These are the positions corresponding to the given numbers:-\n");
        printf("-----------\n");
        printf("- 1  2  3 -\n");
        printf("- 4  5  6 -\n");
        printf("- 7  8  9 -\n");
        printf("-----------\n");
        printf("Rules are the same as normal. Enjoy the game!!!\n\n");
        


        //taking name of the players
        char player1[20];
        char player2[20];

        input_start:

        while(1){
            int player_1_status=safe_input_string(player1,sizeof(player1),"enter name of first player, (20 chars max, enter 'X' to exit):-");

            if(player_1_status==0){
                continue;
            }

            if(player_1_status==INPUT_EXIT_SIGNAL){
                printf("\nExiting tic tac toe....\n\n");
                return;
            }

            break;
        }

        while(1){
            int player_2_status=safe_input_string(player2,sizeof(player2),"enter name of second player, (20 chars max, enter 'X' to exit):-");

            if(player_2_status==0){
                continue;
            }

            if(player_2_status==INPUT_EXIT_SIGNAL){
                printf("\nExiting tic tac toe....\n\n");
                return;
            }

            break;
        }

        if(strncmp(player1,player2,20)==0){
            printf("both player names cant be same. Try again\n\n");
            goto input_start;
        }



        //setting up the matrix
        char board[3][3];
        int winner=0;
        bool gameover=false;


        //setting default value of the board
        
        board[0][0]='1';board[0][1]='2';board[0][2]='3';
        board[1][0]='4';board[1][1]='5';board[1][2]='6';
        board[2][0]='7';board[2][1]='8';board[2][2]='9';

        clear_screen();
        display_board_ttt(board);

        for(int i=0;i<9;i++){

            if(gameover)    break;
            retry:
            int choice;
            char xo;

            if(i%2==0){
                xo='X';
                printf("%s's turn:- ",player1);
            }
            else{
                xo='O';
                printf("%s's turn:- ",player2);
            }

            int choice_status=safe_input_int(&choice,NULL,1,9);
            
            if(choice_status==INPUT_EXIT_SIGNAL){
                printf("\nExiting tic tac toe and returning to menu....\n\n");
                return;
            }
            else if(choice_status==0){
                continue;
            }

            int row=(choice-1)/3;
            int col=(choice-1)%3;

            if(board[row][col]=='X' || board[row][col]=='O'){
                printf("Position already filled. Try again");
                continue;
            }

            //marks X or O on the actual board
            board[row][col]=xo;
            
            clear_screen();
            display_board_ttt(board);

            int winner=who_won(board);
            if(winner==1){
                printf("\n%s won!!!",player1);
                gameover=true;
            }
            else if(winner==2){
                printf("\n%s won!!!",player2);
                gameover=true;
            }

        }

        if(!gameover)   printf("\nGame draw\n");

        printf("\n\n========================================");

    }
}  
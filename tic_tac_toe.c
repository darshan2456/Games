#include<stdio.h>
#include<string.h>
#include<stdbool.h>

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
    //col wise checking for player 1
    else if(arr[0][0]=='O' && arr[1][0]=='O' && arr[2][0]=='O' || arr[0][1]=='O' && arr[1][1]=='O' && arr[2][1]=='O' || arr[0][2]=='O' && arr[1][2]=='O' && arr[2][2]=='O'){
        return 2;
    }
    //diagonal checking for player 1
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
        printf("Rules are the same as normal. Enjoy the game!!!\n\n(To exit enter '-1', to continue enter any number)\n\n");
        printf("Enter here:- ");
        scanf("%d",&exit);

        if(exit==-1)    break;


        //taking name of the players
        char player1[100];
        char player2[100];

        retry_name:
        printf("enter name of first player:- ");
        scanf("%s",player1);
        printf("enter name of second player:- ");
        scanf("%s",player2);

        if(strncmp(player1,player2,100)==0){
            printf("both player names cant be same. Try again\n\n");
            goto retry_name;
        }


        //setting up the matrix
        char board[3][3];
        int player=0;
        int winner=0;
        bool gameover=false;


        //setting default value of the board
        
        board[0][0]='1';board[0][1]='2';board[0][2]='3';
        board[1][0]='4';board[1][1]='5';board[1][2]='6';
        board[2][0]='7';board[2][1]='8';board[2][2]='9';


        for(int i=0;i<9;i++){
            if(gameover==true)    break;
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

            scanf("%d",&choice);

            if(choice<1 || choice>9){
                printf("Number must be between 1 and 9. Try againn\n");
                goto retry;
            }

            switch(choice){
                case 1:
                    if(board[0][0]!='1'){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[0][0]=xo;
                    display_board_ttt(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("\n%s won!!!",player1);
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("\n%s won!!!",player2);
                        gameover=true;
                    }

                    break;

                case 2:
                    if(board[0][1]!='2'){
                        printf("position already filled. try again\n");
                        goto retry;
                    }


                    board[0][1]=xo;
                    display_board_ttt(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("\n%s won!!!",player1);
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("\n%s won!!!",player2);
                        gameover=true;
                    }

                    break;

                case 3:
                    if(board[0][2]!='3'){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[0][2]=xo;
                    display_board_ttt(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("\n%s won!!!",player1);
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("\n%s won!!!",player2);
                        gameover=true;
                    }

                    break;

                case 4:
                    if(board[1][0]!='4'){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[1][0]=xo;
                    display_board_ttt(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("\n%s won!!!",player1);
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("\n%s won!!!",player2);
                        gameover=true;
                    }

                    break;

                case 5:
                    if(board[1][1]!='5'){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[1][1]=xo;
                    display_board_ttt(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("\n%s won!!!",player1);
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("\n%s won!!!",player2);
                        gameover=true;
                    }

                    break;

                case 6:
                    if(board[1][2]!='6'){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[1][2]=xo;
                    display_board_ttt(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("\n%s won!!!",player1);
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("\n%s won!!!",player2);
                        gameover=true;
                    }

                    break;

                case 7:
                    if(board[2][0]!='7'){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[2][0]=xo;
                    display_board_ttt(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("\n%s won!!!",player1);
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("\n%s won!!!",player2);
                        gameover=true;
                    }

                    break;

                case 8:
                    if(board[2][1]!='8'){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[2][1]=xo;
                    display_board_ttt(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("\n%s won!!!",player1);
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("\n%s won!!!",player2);
                        gameover=true;
                    }

                    break;

                case 9:
                    if(board[2][2]!='9'){
                        printf("position already filled. try again\n");
                        goto retry;
                    }

                    board[2][2]=xo;
                    display_board_ttt(board);

                    winner=who_won(board);
                    if(winner==1){
                        printf("\n%s won!!!",player1);
                        gameover=true;
                    }
                    else if(winner==2){
                        printf("\n%s won!!!",player2);
                        gameover=true;
                    }

            }
        }

        if(!gameover)   printf("\nGame draw\n");

        printf("\n\n========================================");

    }
}  
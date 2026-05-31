#include<stdio.h>

void display_board_tango(char arr[6][6]){
    printf("-------------------------------\n");
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(arr[i][j]<10){                           //for single digits
                printf("| %d  ",arr[i][j]);
            }
            else{                                       //for double digits
                printf("| %d ",arr[i][j]);
            }
            if(j==5)    printf("|");
        }
        printf("\n-------------------------------\n");
    }
}

void tango(){

    char board[6][6];
    printf("Welcome to tango\n");

    printf("--------------------------\n");
    printf("| 1   2   3   4   5   6  |\n");
    printf("| 7   8   9   10  11  12 |\n");
    printf("| 13  14  15  16  17  18 |\n");
    printf("| 19  20  21  22  23  24 |\n");
    printf("| 25  26  27  28  29  30 |\n");
    printf("| 31  32  33  34  35  36 |\n");
    printf("--------------------------\n");


    //initialization of board with position number of each block
    int num=1;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            board[i][j]=num++;
        }
    }

    display_board_tango(board);

    for(int i=0;i<36;i++){
        retry:
        int block_choice=0;
        printf("\nenter position of the block you want to fill:- ");
        scanf("%d",&block_choice);

        if(block_choice<1 || block_choice>36){
            printf("invalid choice. choose only from 1 to 36.");
            goto retry;
        }

        //determine block to be changed
        int row=(block_choice-1)/6;
        int col=(block_choice-1)%6;


        again:

        int choice;
        printf("\nenter 1 for moon and 2 for sun\n(and btw 66 is moon and 99 is sun, dont ask me why)\nenter here: ");
        scanf("%d",&choice);

        if(choice<1 || choice>2){
            printf("only choose between 1 and 2");
            goto again;
        }

        if(choice==1){
            board[row][col]='B';
            display_board_tango(board);
        }
        else if(choice==2){
            board[row][col]='c';
            display_board_tango(board);
        }
    }

}
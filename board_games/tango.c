#include<stdio.h>
#include<stdbool.h>
#include "clear_screen.h"

#define MOON 0
#define SUN 77

void display_board_tango(int arr[6][6]){
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

bool check_if_valid(int board[6][6], int row, int col, int choice){

    int obj;

    if(choice==1){
        obj=MOON;
    }
    else if(choice==2){
        obj=SUN;
    }


    //below cases check if there are three consecutive suns or moons (row-wise or column-wise)

    // //corner case
    // if(row==col)

    //first condition - upper two      ||      second condition - lower two
    if((row>=2 && row<=3) && board[row-1][col]==obj && board[row-2][col]==obj || board[row+1][col]==obj && board[row+2][col]==obj){
        return false;
    }
    //second condiiton - right two      ||      second condition - left two
    else if((col>=2 && col<=3) && board[row][col+1]==obj && board[row][col+2]==obj || board[row][col-1]==obj && board[row][col-2]==obj){
        return false;
    }
    //middle of two case:-                                               middle of two - vertical      ||        middle of two - horizontal
    else if((row>=1 && row<=4 && col>=1 && col<=4) && board[row-1][col]==obj && board[row+1][col]==obj || board[row][col-1]==obj && board[row][col+1]==obj){
        return false;
    }




    //below we check if there are total 3 or less suns or moons (objs) in given row/col

        int r_obj=0; int c_obj=0;

        for(int i=0;i<6;i++){           //checking if the row contains more than 3 moon
            if(board[row][i]==obj)     r_obj++;
        }

        for(int i=0;i<6;i++){           //checking if the colummn contains more than 3 moon
            if(board[i][col]==obj)     c_obj++;
        }

        if(r_obj==3 || c_obj==3){
            return false;
        }

    return true;
}

void tango(){

    int board[6][6];
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
        clear_screen();
        display_board_tango(board);

        retry:
        
        int block_choice;

        //loop to get the position of block
        do {
            printf("Enter position (1-36): ");
            scanf("%d", &block_choice);
            if(block_choice < 1 || block_choice > 36)
                printf("Invalid. Choose 1 to 36.\n");
        } while(block_choice < 1 || block_choice > 36);

        //determine block to be changed
        int row=(block_choice-1)/6;
        int col=(block_choice-1)%6;

        int choice;

        //loop to get one from sun and moon
        do{
            printf("\nenter 1 for moon and 2 for sun\n(and btw 66 is moon and 99 is sun, dont ask me why)\nenter here: ");
            scanf("%d",&choice);

            if(choice<1 || choice>2){
                printf("only choose between 1 and 2");
            }
        }while(choice<1 || choice>2);

        if(!check_if_valid(board,row,col,choice)){
            printf("\ninvalid row or col, cant place in that block, try again\n");
            display_board_tango(board);
            goto retry;
        }

        if(choice==1){
            board[row][col]=MOON;
            display_board_tango(board);
        }
        else if(choice==2){
            board[row][col]=SUN;
            display_board_tango(board);
        }
    }

}
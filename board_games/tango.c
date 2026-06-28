#include<stdio.h>
#include<stdbool.h>
#include "clear_screen.h"
#include "safe_input.h"
#include "cross_platform_timer.h"

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
    //third condition - rows adjacent to the borders
    else if(row==0 && board[row+1][col]==obj && board[row+2][col]==obj || row==5 && board[row-1][col]==obj && board[row-2][col]==obj){
        return false;
    }
    //fourth condition - columns adjacent to the borders
    else if(col==0 && board[row][col+1]==obj && board[row][col+2]==obj || col==5 && board[row][col-1]==obj && board[row][col-2]==obj){
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
    printf("\nWelcome to tango\n\n");


    //initialization of board with position number of each block
    int num=1;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            board[i][j]=num++;
        }
    }


    for(int i=0;i<36;i++){
        clear_screen();

        if(i==0){
            printf("\nWelcome to Tango\n\n");
        }

        display_board_tango(board);
        
        int block_choice;
        int block_choice_status;

        //loop to get the position of block
        while(1){
            block_choice_status=safe_input_int(&block_choice, "Enter position, between 1 and 36:- ",1,36);
    
            if(block_choice_status==INPUT_EXIT_SIGNAL){
                printf("\nExiting tango game and returning to menu....\n\n");
                return;
            }
            else if(block_choice_status==0){
                continue;
            }

            break;
        }

        //determine block to be changed
        int row=(block_choice-1)/6;
        int col=(block_choice-1)%6;

        int choice;
        int choice_status;

        //loop to get one from sun and moon
        while(1){
            choice_status=safe_input_int(&choice,"\nenter 1 for moon and 2 for sun\n(and btw 0 is moon and 77 is sun, dont ask me why)\nenter here: ",1,2);
            
            if(choice_status==INPUT_EXIT_SIGNAL){
                printf("\nExiting tango game and returning to menu....\n\n");
                return;
            }
            else if(choice_status==0){
                continue;
            }

            break;
        }

        if(!check_if_valid(board,row,col,choice)){
            printf("\ninvalid row or col, cant place in that block, try again\n");
            sleep_seconds(2);
            continue;
        }

        if(choice==1){
            board[row][col]=MOON;
        }
        else if(choice==2){
            board[row][col]=SUN;
        }

    }

}
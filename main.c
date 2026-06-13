#include<stdio.h>
#include "tic_tac_toe.h"
#include "tango.h"
#include "love.h"
void main(){

    while(1){

        int game_choice=0;
        printf("Welcome to 'Games' by Darshan Mukul Parekh\n"
               "Press '1' to play tic tac toe\n"
               "Press '2' to play tango\n"
               "Press '3' to play the love game\n"
               "Press '-1' to exit\n"
               "enter here:- ");
        
        if(scanf("%d",&game_choice)!=1){
            printf("\nInvalid input. Try again");
            continue;
        }

        if(game_choice==-1){
            printf("Exiting Games....");
            return;
        }

        switch (game_choice)
        {
        case 1:
            tic_tac_toe();
            break;
        
        case 2:
            tango();
            break;

        case 3:
            love();
            break;
        }

    }

}
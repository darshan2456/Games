#include<stdio.h>
#include "tic_tac_toe.h"
#include "tango.h"
#include "love.h"
#include "safe_input.h"
void main(){

    while(1){

        int game_choice;
        printf("Welcome to 'Games' by Darshan Mukul Parekh\n"
                "(at any point, press '-1' to exit that particular stage)\n"
                "Press '1' to play tic tac toe\n"
                "Press '2' to play tango\n"
                "Press '3' to play the love game\n"
                "Press '-1' to exit\n"
                "enter here:- ");
        
        int game_status=safe_input_int(&game_choice,NULL,1,3);

        if(game_status==INPUT_EXIT_SIGNAL){
            return;
        }
        if(game_status==0){
            continue;
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
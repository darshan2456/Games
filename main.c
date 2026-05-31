#include<stdio.h>
#include "tic_tac_toe.h"
#include "tango.h"
int main(){
    int game_choice=0;
    printf("Welcome to 'Games' by Darshan Mukul Parekh\n"
           "Press '1' to play tic tac toe\n"
           "Press '2' to play tango\n"
           "enter here:- ");
    scanf("%d",&game_choice);

    switch (game_choice)
    {
    case 1:
        tic_tac_toe();
        break;
    
    case 2:
        tango();
        break;
    }

}
#include<stdio.h>
#include<stdlib.h>

#ifdef _WIN32

    #define clear  system("cls")

#else

    #define clear  printf("\033[2J\033[H")

#endif

void clear_screen(){
    clear;
}
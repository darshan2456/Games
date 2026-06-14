#ifdef _WIN32

#include<stdlib.h>
    #define clrscr  system("cls")

#else

#include<stdlib.h>
    #define clrscr  system("clear")

#endif

void clear_screen(){
    clrscr;
}
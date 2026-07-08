#include <stdio.h>
#include <string.h>
#include <iostream>
#include "safe_input.hpp"

int safe_input_string(char* input, size_t size, const std::string prompt){
    if(prompt.length()!=0){
        std::cout<<prompt;
        fflush(stdout);
    }

    if(fgets(input,size,stdin)==NULL){
        clearerr(stdin);
        printf("\n\nEOF encountered.\n\n");
        return 0;
    }

    size_t len=strlen(input);

    //remove trailing newline
    if(len>0 && input[len-1]=='\n'){
        input[len-1]='\0';
        len--;
    }
    else{               //input was longer than buffer, discard remaining characters
        int c;
        while((c=getchar())!='\n' && c!=EOF);
        printf("\nInput longer than capacity\n");
        return 0;
    }

    if(len==0){
        printf("\ninput cannot be empty\n");
        return 0;
    }

    if(strcmp(input,"X")==0){
        return INPUT_EXIT_SIGNAL;
    }

    return 1;
}
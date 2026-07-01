#include <stdio.h>
#include <string.h>
#include "safe_input.h"

int safe_input_string(char* input, size_t size, const char* prompt){
    if(prompt){
        printf("%s",prompt);
        fflush(stdout);
    }

    if(fgets(input,size,stdin)==NULL){
        printf("\nEOF encountered.\n");
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
        while((c=getchar())!='\n' || c!=EOF);
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
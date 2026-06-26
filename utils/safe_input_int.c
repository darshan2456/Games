#include<stdio.h>

int safe_input_int(int* input, char* prompt, int min, int max){
    if(prompt){
        printf(prompt);
        fflush(stdout);
    }

    int val;
    char extra_char;

    if(scanf("%d",&val)!=1){
        goto cleanup;
    }

    if(scanf("%c",&extra_char)!=1 && extra_char!='\n'){
        printf("\nonly number, no extra characters please");
        goto cleanup;
    }

    if(val==-1){
        return -11;
    }
    if(val<min || val>max){
        printf("Value must be between %d and %d.",min,max);
        goto cleanup;
    }

    *input=val;

    return 1;

    cleanup:
        int c;
        while(c=getchar()!='\n' && c!=EOF);
        if(c==EOF){
            printf("EOF encountered");
            return 0;
        }
        return 0;
    
}
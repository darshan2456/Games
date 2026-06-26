#include <stdio.h>
#include "cross_platform_timer.h"
#include "safe_input.h"

void slow_print(char* word){
    int i = 0;
    printf("\n");
    while (word[i] != '\0') {
        printf("%c", word[i]);
        i++;
        fflush(stdout);
        sleep_seconds(0.2);
    }
    printf("\n");
}


void love() {

    while(1){

        int size;
        int size_status=safe_input_int(&size,
        "\nenter size of boobs between 1 and 3:- ",
        1,3);

        if(size_status==INPUT_EXIT_SIGNAL){
            return;
        }
        else if(size_status==0){
            continue;
        }

        switch (size) {
            case 1: {
                char ilu[] = "small boobs";
                slow_print(ilu);

                char one[] = "( . )( . )\n";
                printf(one);
                break;
            }

            case 2: {
                char ilu[] = "average boobs";
                slow_print(ilu);

                char two[] = "(  .  )(  .  )\n";
                printf(two);
                break;
            }

            case 3: {
                char ilu[] = "large boobs";
                slow_print(ilu);

                char three[] = "(   .   )(   .   )\n";
                printf(three);
                break;
            }

            default:
                printf("This size of boobs dont exist lol\n");
        }
    }

    return;
}
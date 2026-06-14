#include <stdio.h>
#include "cross_platform_timer.h"

void love() {

    while(1){

        int size;
        printf("\nEnter size of boobs (1,2 or 3 only) enter -1 to exit: ");
        if(scanf("%d", &size)!=1){
            printf("\ninvalid input, try again....");
            continue;
        }

        if(size==-1){
            printf("Exiting love game.....");
            return;
        }

        switch (size) {
            case 1: {
                char ilu[] = "i love your small boobs";
                int i = 0;
                while (ilu[i] != '\0') {
                    printf("%c", ilu[i]);
                    i++;
                    fflush(stdout);
                    sleep_seconds(0.2);
                }
                printf("\n");

                char one[4] = " . ";
                printf("(%s)(%s)\n", one, one);
                break;
            }

            case 2: {
                char ilu[] = "i love your average boobs";
                int i = 0;
                while (ilu[i] != '\0') {
                    printf("%c", ilu[i]);
                    i++;
                    fflush(stdout);
                    sleep_seconds(0.2);
                }
                printf("\n");

                char two[6] = "  .  ";
                printf("(%s)(%s)\n", two, two);
                break;
            }

            case 3: {
                char ilu[] = "i love your large boobs";
                int i = 0;
                while (ilu[i] != '\0') {
                    printf("%c", ilu[i]);
                    i++;
                    fflush(stdout);
                    sleep_seconds(0.2);
                }
                printf("\n");

                char three[8] = "   .   ";
                printf("(%s)(%s)\n", three, three);
                break;
            }

            default:
                printf("This size of boobs dont exist lol\n");
        }
    }

    return;
}
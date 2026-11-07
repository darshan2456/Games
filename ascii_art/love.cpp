#include <stdio.h>
#include <string>
#include <iostream>
#include "cross_platform_timer.hpp"
#include "clear_screen.hpp"
#include "safe_input.hpp"

void slow_print(const std::string& word){
    std::cout << "\n\n";

    for (char ch : word) {
        std::cout << ch;
        std::cout.flush();
        sleep_seconds(0.2);
    }

    std::cout << "\n";
}


void love() {

    while(1){

        int size;
        int size_status=safe_input_int(&size,
        "\nenter size of boobs between 1 and 3:- ",
        1,3);

        if(size_status==INPUT_EXIT_SIGNAL || size_status==INPUT_EOF_SIGNAL){
            std::cout<< "\nExiting love game and returning to menu.....\n\n";
            return;
        }
        else if(size_status==0){
            continue;
        }

        switch (size) {
            case 1: {
                clear_screen();
                std::string ilu = "small boobs";
                slow_print(ilu);

                std::cout << "( . )( . )\n";
                sleep_seconds(2);
                clear_screen();
                break;
            }

            case 2: {
                clear_screen();
                std::string ilu = "average boobs";
                slow_print(ilu);

                std::cout << "(  .  )(  .  )\n";
                sleep_seconds(2);
                clear_screen();
                break;
            }

            case 3: {
                clear_screen();
                std::string ilu = "large boobs";
                slow_print(ilu);

                std::cout << "(   .   )(   .   )\n";
                sleep_seconds(2);
                clear_screen();
                break;
            }

            default:
                std::cout<<"This size of boobs dont exist lol\n";
        }
    }

    return;
}

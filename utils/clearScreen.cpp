#include <iostream>

#ifdef _WIN32

#include <cstdlib>

void clear_screen() {
    std::system("cls");
}

#else

void clear_screen() {
    std::cout << "\033[2J\033[H";
    std::cout.flush();
}

#endif

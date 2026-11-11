#include <iostream>

#ifdef _WIN32

#include <cstdlib>

void clearScreen() {
    std::system("cls");
}

#else

void clearScreen() {
    std::cout << "\033[2J\033[H";
    std::cout.flush();
}

#endif

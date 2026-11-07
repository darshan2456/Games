#include <iostream>
#include <sstream>
#include <string>

#include "safe_input.hpp"

int safe_input_int(int& input, const std::string& prompt, int min, int max)
{

    std::cout << prompt;

    std::string line;

    if (!std::getline(std::cin, line)) {
        return INPUT_EOF_SIGNAL;
    }

    std::istringstream stream(line);

    int val;
    char extra_char;

    if (!(stream >> val) || (stream >> extra_char)) {
        std::cout << "\nOnly numbers are allowed.\n";
        return 0;
    }

    if (val == -1) {
        return INPUT_EXIT_SIGNAL;
    }

    if (val < min || val > max) {
        std::cout << "\nValue must be between "
                  << min << " and " << max << ".\n";

        return 0;
    }

    input = val;

    return 1;
}

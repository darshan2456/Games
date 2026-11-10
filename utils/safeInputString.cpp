#include <iostream>
#include <string>

#include "safeInput.hpp"

int safe_input_string(std::string& input, const std::string& prompt, std::size_t max_length)
{

    std::cout << prompt;

    std::string line;

    if (!std::getline(std::cin, line)) {
        return INPUT_EOF_SIGNAL;
    }

    if (line.empty()) {
        std::cout << "\nInput cannot be empty.\n";
        return 0;
    }

    if (line.length() > max_length) {
        std::cout << "\nInput exceeds maximum length.\n";
        return 0;
    }

    if (line == "X") {
        return INPUT_EXIT_SIGNAL;
    }

    input = line;

    return 1;
}

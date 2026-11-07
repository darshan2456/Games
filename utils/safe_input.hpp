#include <cstddef>
#include<string>

#define INPUT_EXIT_SIGNAL -11
#define INPUT_EOF_SIGNAL -12

int safe_input_int(int* input, const std::string& prompt, int min, int max);
int safe_input_string(std::string& input, const std::string& prompt, std::size_t max_length=20);

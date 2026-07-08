#include<string>

int safe_input_int(int* input, const std::string prompt, int min, int max);
int safe_input_string(char* input, size_t size, const std::string prompt);
#define INPUT_EXIT_SIGNAL -11
int safe_input_int(int* input, char* prompt, int min, int max);
int safe_input_string(char* input, size_t size, const char* prompt);

#define INPUT_EXIT_SIGNAL -11
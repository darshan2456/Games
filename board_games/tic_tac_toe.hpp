#include <array>

using Board = std::array<std::array<char, 3>, 3>;

void display_board_ttt(const Board& board);

int who_won(const Board& board);

void ttt_multiplayer();

void ttt_computer();

void ttt_launcher();

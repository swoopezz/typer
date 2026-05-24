#pragma once

#define COLOR_RST "\x1B[0m"

#define COLOR_RED "\x1B[1;31m"
#define COLOR_GRN "\x1B[1;32m"
#define COLOR_YEL "\x1B[1;33m"
#define COLOR_BLU "\x1B[1;34m"
#define COLOR_MAG "\x1B[1;35m"
#define COLOR_CYN "\x1B[1;36m"
#define COLOR_WHT "\x1B[1;37m"

#define CLEAR_SCR "\x1B[2J"

#define MOVE_CURS(X, Y) std::cout << "\033[" << Y << ";" << X << "H";

#define ALTER_SCR "\033[?1049h\033[H"
#define E_ATLER_SCR "\033[?1049l"

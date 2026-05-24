
#pragma once
#include "../escape/escape.h"
#include <string>

namespace tui { 
    class Window {
    public:
        Window();
        Window(int width, int height); 
        
        auto disable_echo() -> void;
        auto enable_echo() -> void;

        auto enter_alter_screen() -> void;
        auto exit_alter_screen() -> void;

        auto clear_screen() -> void;
        auto move_cursor(int x, int y) -> bool;

        auto write(std::string& str) -> void;
        auto write(std::string& str, int x, int y) -> void;
        auto write(char c) -> void;
        auto write(char c, int x, int y) -> void;

        auto get_width() -> int;
        auto get_height() -> int;
    private:
        int width;
        int height;
    };
}

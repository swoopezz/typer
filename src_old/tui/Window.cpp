#include "Window.h"
#include <asm-generic/ioctl.h>
#include <asm-generic/ioctls.h>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/ioctl.h>
#include <termios.h>

tui::Window::Window() {
    struct winsize size;
    ioctl(1, TIOCGWINSZ, &size);

    width = size.ws_col;
    height = size.ws_row;
} 

tui::Window::Window(int width, int height) :
    width(width), height(height){}

auto tui::Window::clear_screen() -> void {
    std::cout << CLEAR_SCR << std::endl;
}

auto tui::Window::move_cursor(int x, int y) -> bool {
    MOVE_CURS(x, y);
    return true;
}

auto tui::Window::write(std::string& str) -> void {
    std::cout << str;
}

auto tui::Window::write(std::string& str, int x, int y) -> void {
    move_cursor(x, y);
    write(str);
}

auto tui::Window::write(char c) -> void {
    std::cout << c;
}

auto tui::Window::write(char c, int x, int y) -> void {
    move_cursor(x, y);
    write(c);
}

auto tui::Window::enter_alter_screen() -> void {
    std::cout << ALTER_SCR << std::endl;
}

auto tui::Window::exit_alter_screen() -> void {
    std::cout << E_ATLER_SCR << std::endl;
}

auto tui::Window::disable_echo() -> void {
    struct termios term;
   
    tcgetattr(1, &term);
    term.c_lflag &= -ECHO;
    tcsetattr(1, TCSANOW, &term);
}

auto tui::Window::enable_echo() -> void {
    struct termios term;
   
    tcgetattr(1, &term);
    term.c_lflag |= ECHO;
    tcsetattr(1, TCSANOW, &term);
}

auto tui::Window::get_width() -> int { return width; }
auto tui::Window::get_height() -> int { return height; }

#include "escape/escape.h"
#include "tui/Window.h"
#include "tui/Window.cpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

auto is_correct_key(std::string& str, char key, int index) -> bool;
auto change_char_color(tui::Window& w, char c, const char* color, int x, int y) -> void;
auto write_current_key(tui::Window&, char) -> void;
auto move_cursor_when_write(tui::Window&, int&, int&) -> void;
auto exit(tui::Window& w) -> void;

int main (int argc, char *argv[]) {

    std::string text = "Very long ewir hewrieshgdsfkg hfgk hdfg sfw hrewihr";
    tui::Window window = tui::Window();

    window.disable_echo();
    window.enter_alter_screen();
    
    int text_size = text.size();
    int center_width = (window.get_width() - text_size) / 2;
    int center_height = window.get_height() / 2;

    window.clear_screen();
    window.move_cursor(center_width, center_height);
    
    window.write(text);
    window.move_cursor(center_width, center_height);

    char key;
    
    int cursor_x = center_width;
    int cursor_y = center_height;
    int cursor_index = 0; 

    while (true) {
        std::cin >> key;

        if (key == 'q' || cursor_index + 1 >= text_size) {
            exit(window);
            break;
        }
        if (key == 127 && cursor_index > 0) { // backspace
            continue;
        }        

        write_current_key(window, key);
        move_cursor_when_write(window, cursor_x, cursor_y);

        if (is_correct_key(text, key, cursor_index)) {
            change_char_color(window, key, COLOR_BLU, 
                    cursor_x, cursor_y);
        } else {
            change_char_color(window, key, COLOR_RED, 
                    cursor_x, cursor_y);
        }
        
        if (text[cursor_index + 1] == ' ')  {
            cursor_index+=2;
            cursor_x += 1;
            window.move_cursor(cursor_x, cursor_y);
            continue;
        }

        cursor_index++;
    }
    const double wpm = 10.0;
    const double accuracy = 50;
    std::cout << "WPM: " << wpm << "; Accuracy: " << accuracy << "%" << std::endl << std::endl;
    
    return 0;
}

auto write_current_key(tui::Window& w, char key) -> void {
    w.write(key, 1, w.get_height()); 
}

auto move_cursor_when_write(
        tui::Window& w, 
        int& cursor_x, 
        int& cursor_y) 
-> void {
    w.move_cursor(++cursor_x, cursor_y);
    if (cursor_x > w.get_width()) {
        cursor_x = 1;
        w.move_cursor(cursor_x, ++cursor_y);
    } 
}

auto is_correct_key(std::string& str, char key, int index) -> bool {
    return str[index] == key;
}

auto change_char_color(tui::Window& w, char c, const char* col, int x, int y) -> void {
    w.move_cursor(x - 1, y);
    std::cout << col << c << COLOR_RST;
}

auto exit(tui::Window& w) -> void {
    w.exit_alter_screen();
    w.enable_echo();
}

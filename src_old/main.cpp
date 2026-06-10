#include "escape/escape.h"
#include "tui/Window.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <chrono>

using namespace std::string_literals;
const std::string DICT_DIR = "/home/user"s + "/.config/typer/dict.txt";

auto read_dict_file(const std::string& path) -> std::vector<std::string>;
auto generate_text(std::vector<std::string>& word_dict, int) -> std::string;

auto word_count(std::string& str) -> unsigned int;
auto is_correct_key(std::string& str, char key, int index) -> bool;
auto change_char_color(tui::Window& w, char c, const char* color, int x, int y) -> void;
auto write_current_key(tui::Window&, char) -> void;
auto move_cursor_when_write(tui::Window&, int&, int&) -> void;
auto exit(tui::Window& w) -> void;

int main (int argc, char *argv[]) {

    std::string text;
    std::vector<std::string> dict;

    try { 
        dict = read_dict_file(DICT_DIR);
        text = generate_text(dict, 6);

    } catch (std::runtime_error& e) {
        std::cout << "ERROR: " << e.what();
        return 1;
    }
    
    tui::Window window = tui::Window();

    window.disable_echo();
    window.enter_alter_screen();
    
    int text_size = text.size();
    int center_width = (window.get_width() - text_size) / 2;
    int center_height = window.get_height() / 2;
    auto start_time = std::chrono::system_clock::now().time_since_epoch();

    window.clear_screen();
    window.move_cursor(center_width, center_height);
    
    window.write(text);
    window.move_cursor(center_width, center_height);

    char key;
    
    int cursor_x = center_width;
    int cursor_y = center_height;
    int cursor_index = 0; 
   
    int correct = 0;
    
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
            correct++;
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
    auto end_time = std::chrono::system_clock::now().time_since_epoch() - start_time;
    auto mill = std::chrono::duration_cast<std::chrono::milliseconds>(end_time);
    const int word = word_count(text);
    const int wpm = word * 60000 / mill.count();
    //                                                spaces
    const int accuracy = correct * 100 / (text_size - word);
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

auto word_count(std::string& text) -> unsigned int {
    std::stringstream stream(text);
    return std::distance(
            std::istream_iterator<std::string>(stream),
            std::istream_iterator<std::string>()
    );
}

auto exit(tui::Window& w) -> void {
    w.exit_alter_screen();
    w.enable_echo();
}


auto read_dict_file(const std::string& path) -> std::vector<std::string> {
    std::vector<std::string> result;
    std::ifstream file = std::ifstream(path);
    
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open dict file.");
    }

    std::string line;

    while (std::getline(file, line)) {
        result.push_back(line);
    }

    return result;
}

auto generate_text(std::vector<std::string>& word_dict, int word_count) -> std::string {
    if (word_dict.empty()) {
        throw std::runtime_error("Empty word_dict.");
    }
    
    std::random_device random_device;
    std::mt19937 mers_enigne = std::mt19937(random_device());
    std::uniform_int_distribution<int> dist {0, static_cast<int>(word_dict.size() - 1)};

    auto gen = [&dist, &mers_enigne](){
        return dist(mers_enigne);
    };

    std::string result; 

    for (int i = 0; i <= word_count; i++) {
        result += word_dict[gen()];

        if (i != word_count) {
            result += " ";
        }
    }
    
    return result;
}

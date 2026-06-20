#include "Elements.hpp"
#include "Input.hpp"
#include "WinSize.hpp"
#include "Window.hpp"
#include "Util.hpp"
#include "Dict.hpp"
#include <filesystem>
#include <memory>
#include <optional>
#include <pwd.h>

bool fileExists(const std::string& path) {
	std::ifstream f(path);
	return f.good();
}

void mkdir(std::filesystem::path& path) {
	namespace fs = std::filesystem;
    fs::create_directories(path);
}

void copy(std::filesystem::path& from, std::filesystem::path& to) {
	std::filesystem::copy_file(from, to);
}

std::optional<std::filesystem::path> getHome() {
	if (const char* home = getenv("HOME")) {
		if (home[0] != '\0')
			return std::filesystem::path(home);
	}

	struct passwd* pw = getpwuid(getuid());
	if (pw && pw->pw_dir && pw->pw_dir[0] != '\0') {
        return std::filesystem::path(pw->pw_dir);
    }
		
	return std::nullopt;
}

void initSettings() {
	const std::string p = getHome()->string() + "/.local/share/kbchad";
	std::filesystem::path settingPath(p);

	mkdir(settingPath);
	copy(std::filesystem::path("static/english.txt"), 
			std::filesystem::path(p + "/"));
}

using namespace tui;
int main() {	
	/*if (!fileExists(getHome()->string() + "/.local/share/kbchad"))
        initSettings();

	auto window= Window(std::make_shared<size::FullScreen>());
	Dict dict = Dict( getHome()->string() 
            + "/.local/share/kbchad/english.txt");	
	auto input = std::make_shared<Input>(
			dict.generateSentence(dict, 10));

	window.setContent({
		text("KeyboadChad") | centerX,
		input | centerX | centerY,
		text("[esc] exit [entr] restart") | centerX | buttom
	});
	
	util::enableAlterScr();
	util::hideCursor();
	while (true) {
		window.render();
		char ch = util::getch();

		if (ch == Key::ESC) {
			util::disablAnterScr();
			util::showCursor();
			break;
		}

		if (ch == Key::ENTER) {
			input->updateInput(
					dict.generateSentence(dict, 10));	
			continue;
		}
		input->press(ch);
	}*/

    auto window = Window(std::make_shared<size::FullScreen>());
    window.setContent({
        graphic({1, 2, 3, 4, 5, 6, 7})
    });

    window.render();

	return 0;
}


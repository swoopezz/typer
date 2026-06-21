#include "Elements.hpp"
#include "Input.hpp"
#include "WinSize.hpp"
#include "Window.hpp"
#include "Util.hpp"
#include "WordList.hpp"
#include "Keys.hpp"
#include "FileUtil.hpp"

void initSettings();

int main() {
    
    using namespace tui;
    using namespace utils;

	if (!fileExists(getHome()->string() + "/.local/share/kbchad/wordlist"))
        initSettings();

	auto window = Window(std::make_shared<size::FullScreen>());

	WordList dict = WordList(utils::getHome()->string() 
            + "/.local/share/kbchad/wordlist/english.txt");
	auto input = std::make_shared<Input>(
			dict.generateSentence(dict, 10));

	window.setContent({
		text("KeyboadChad") | centerX,
		input | centerX | centerY,
		text("[esc] exit [entr] restart") | centerX | buttom
	});
	
	util::enableAlterScr();
	while (true) {
		window.renderDiff();
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
	}
    return 0;
}

void initSettings() {
	const std::string p = utils::getHome()->string() + "/.local/share/kbchad/wordlist";
	std::filesystem::path settingPath(p);

    utils::mkdir(settingPath);
    if (!utils::fileExists("static/english.txt"))
        return;
	copy(std::filesystem::path("static/english.txt"), 
			std::filesystem::path(p + "/"));
}


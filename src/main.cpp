#include "Elements.hpp"
#include "Input.hpp"
#include "WinSize.hpp"
#include "Window.hpp"
#include "Util.hpp"
#include "WordList.hpp"
#include "FileUtil.hpp"
#include "TextWidget.hpp"
#include <chrono>
#include <functional>

namespace constants {
    constexpr int WORD_COUNT = 10;
    constexpr long TIME_UNDEFINED = -1l;
}

void initSettings();
void setCurrentTimeMs(long& time);

int main() {
    using namespace tui;
    using namespace utils;

	if (!fileExists(getHome()->string() +
	"/.local/share/kbchad/wordlist"))
        initSettings();

	WordList dict = WordList(utils::getHome()->string() +
	"/.local/share/kbchad/wordlist/english.txt");
	auto input = std::make_shared<Input>
	(dict.generateSentence(constants::WORD_COUNT));
	auto statText = std::make_shared<TextWidget>("");	

	Window main = Window(std::make_shared<size::FullScreen>());	
	Window stats= Window(std::make_shared<size::FullScreen>());	

	main.setContent({
		text("KeyboardChad") | centerX,
		input | centerX | centerY, 
		text("[esc] exit [entr] restart") | buttom | centerX
	});
	
	stats.setContent({
		text("KeyboardChad") | centerX,
		statText | centerX | centerY, 
		text("[esc] exit [entr] restart") | buttom | centerX
	});
	const std::function<void(Key)> updateInput = [&](Key k) {
		input->updateInput(dict.generateSentence(
			constants::WORD_COUNT)
		);
	};
	main.mapping(Key::ENTER, updateInput);
	stats.mapping(Key::ENTER, updateInput);	
	util::enableAlterScr();
	util::hideCursor();
	int test = 0;
	for (;;) {
		if (!input->isEnd()) {
			main.renderDiff();
			char ch = util::getch();
			main.pressOrDefault((Key)ch, [&](Key k){
				input->press(ch);
			});
		} else {
			test++;
			statText->updateText(std::to_string(test));
			stats.render();
			char ch = util::getch();
			stats.press((Key)ch);
		}
	}

	util::disablAlterScr();
	util::showCursor();
    return 0;
}

void initSettings() {
	const std::string p = utils::getHome()->string() +
		"/.local/share/kbchad/wordlist";
	std::filesystem::path settingPath(p);

    utils::mkdir(settingPath);
    if (!utils::fileExists("static/english.txt"))
        return;
	copy(std::filesystem::path("static/english.txt"), 
			std::filesystem::path(p + "/"));
}

void setCurrentTimeMs(long& time) {
    time = std::chrono::duration_cast<std::chrono::milliseconds>(
       std::chrono::system_clock::now().time_since_epoch() 
    ).count();
}

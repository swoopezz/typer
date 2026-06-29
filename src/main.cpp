#include "Elements.hpp"
#include "Input.hpp"
#include "WinSize.hpp"
#include "Window.hpp"
#include "Util.hpp"
#include "WordList.hpp"
#include "FileUtil.hpp"
#include "TextWidget.hpp"
#include "Config.hpp"
#include <string>


void initSettings();
void setCurrentTimeMs(long& time);
float ms2min(long ms);

using namespace tui;
using namespace utils;

int main() {
   	if (!fileExists(getHome()->string() +
	"/.local/share/kbchad/wordlist"))
        initSettings();

	WordList dict = WordList(utils::getHome()->string() +
	"/.local/share/kbchad/wordlist/english.txt");

	auto input = std::make_shared<Input>
	(dict.generateSentence(config::WORD_COUNT));
	auto statText = std::make_shared<TextWidget>("");	
	long startTypeTime = 0;
	long endTypeTime = 0;

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
			config::WORD_COUNT)
		);
		startTypeTime = 0;
		endTypeTime = 0;
	};
	main.mapping(Key::ENTER, updateInput);
	stats.mapping(Key::ENTER, updateInput);	

	util::enableAlterScr();
	util::hideCursor();

	for (;;) {
		if (!input->isEnd()) {
			main.renderDiff();
			char ch = util::getch();
			
			if (ch == Key::ESC) break;
			main.pressOrDefault((Key)ch, [&](Key k){
				input->press(ch);
				if (startTypeTime == 0)
					setCurrentTimeMs(startTypeTime);
			});
		} else {
			if (endTypeTime == 0) setCurrentTimeMs(endTypeTime);
			
			float wpm = config::WORD_COUNT * 60000.0 / 
				(endTypeTime - startTypeTime);
			float acc = input->getMisses();

			statText->updateText(
				"WPM: " + std::to_string(wpm) + " "
			);

			stats.render();
			char ch = util::getch();
			if (ch == Key::ESC) break;
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

float ms2min(long ms) {
	return ms/1000.0;
}

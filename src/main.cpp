#include "Elements.hpp"
#include <Input.hpp>
#include "Keys.hpp"
#include "Window.hpp"
#include "Util.hpp"
#include "Dict.hpp"
#include <memory>

std::string generate(Dict& dict, int len) {
	std::string words;

	for (int i = 0; i <= len; i++) {
		if (i == len) {
			words.append(dict.randomWord());
			continue;
		}
		std::string space = dict.randomWord() + " ";
		words.append(space);
	}

	return words;
}

using namespace tui;
int main() {	
		
	auto window = Window(std::make_shared<size::FullScreen>());
	Dict dict = Dict("/home/user/.dict.txt");	

	auto input = std::make_shared<Input>(generate(dict, 10));

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
			input->updateInput(generate(dict, 10));	
			continue;
		}
		input->press(ch);
	}
	return 0;
}


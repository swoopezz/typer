#include <Window.hpp>
#include <Input.hpp>

namespace tui {
	Input::Input(const std::string& text) : text(text){};

	void Input::inputLogic(Window& w, int current, int x, int y) {
		if (current == cursorPosition) {
			w.pixelAt(x, y).isUnderl = true;
			if (x != 0 && x < w.getWidth()) {
				w.pixelAt(x-1, y).isUnderl = false;
				w.pixelAt(x+1, y).isUnderl = false;
			}
		}

		if (input.size() <= current) return;
		
		if (text[current] == input[current])
			w.pixelAt(x, y).isBold = true;
		else 
			w.pixelAt(x, y).isStrike = true;
	}

	void Input::render(Window& w, int& x, int& y) {
		for (int i = 0; i < text.size(); i++) {
			w.pixelAt(x, y).pixelContent = text[i];
			
			inputLogic(w, i, x, y);

			x++;
			if (x > w.getWidth()) {
				x = 0;
				y += 1;
			}
		}
	}

	void Input::press(Window& w, char c) {
		if (cursorPosition == text.size() - 1)
			return;
		
		if (c == 127) { // backspace
			cursorPosition--;	
			input = input.substr(0, input.size()-1);
			return;
		}

		cursorPosition++;
		input += c;
	}
	bool Input::isEnd() {
		return input.size() == text.size() - 1;
	}
	std::string Input::toString(Window& w) const {
		return text;
	}
}

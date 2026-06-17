#include <Window.hpp>
#include <Input.hpp>
#include <chrono>
#include <iterator>

namespace tui {
	Input::Input(const std::string& text) : text(text){};

	long Input::startTime() {
		return startTimeMs;
	}
	
	int wordCount(const std::string& input) {
		std::stringstream stream(input);
    	return std::distance(std::istream_iterator<std::string>(stream),
				std::istream_iterator<std::string>());
	}

	double Input::getWpm() {
		using namespace std::chrono;

		if (startTimeMs == 0) return 0;

		return ((double) wordCount(input) / (
			(duration_cast<milliseconds>(
				system_clock::now().time_since_epoch()).count() / 60000.0
			) - (startTimeMs / 60000.0) ));
	}

	long Input::endTime() {
		return endTimeMs;
	}

	int Input::getMissCount() {
		return missCount;
	}

	const std::string& Input::getText() const {
		return text;
	}
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
		else {
			w.pixelAt(x, y).isStrike = true;
			missCount++;
		}
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
		using namespace std::chrono;
		if (startTimeMs == 0)
			startTimeMs = duration_cast<milliseconds>
				(system_clock::now().time_since_epoch()).count();

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
		using namespace std::chrono;
		bool end = input.size() == text.size() - 1;

		if (end) {
			endTimeMs = duration_cast<milliseconds>
				(system_clock::now().time_since_epoch()).count();
			return true;
		} else return false;

	}
	std::string Input::toString(Window& w) const {
		return text;
	}
}

#include <Loop.hpp>
#include <iostream>

namespace tui {
	void Loop::startLoop() {

		std::cout << "\x1B[?1049h";

		while (!toQuit) {
			window.render();
		}		
	}

	void Loop::stopLoop() {
		toQuit = true;
		std::cout << "\x1B[?1049l";
	}

	char Loop::getChNonBlock() {
		return 'd';
	}
}

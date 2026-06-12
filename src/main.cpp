#include "Elements.hpp"
#include "WinSize.hpp"
#include "Window.hpp"
#include "Util.hpp"
#include <memory>

int main() {	
	
	using namespace tui;

	Window window = Window(std::make_shared<size::FullScreen>());
	const std::string generated = 
		"some text edit fact new object "
		"light window crow elbrus cow "
		"comma delete fork evil corporation";
	
	window.setContent({
		centerX(text("KeyboardChad")),

		centerABS(text(generated)),

		buttom(centerX(text("[esc] exit    [enter] restart")))
	});

	char key;

	util::enableAlterScr();
	util::hideCursor();

	while (true) {
		window.render();
		
		key = util::getch();
		if (key == 27) {
			util::disablAnterScr();
			util::showCursor();
			break;
		}
	}
	return 0;
}

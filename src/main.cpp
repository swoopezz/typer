#include "Elements.hpp"
#include "WinSize.hpp"
#include "Window.hpp"
#include "Util.hpp"
#include "Input.hpp"
#include <memory>

using namespace tui;

Window initEndWindow() {
	Window endWin = Window(std::make_shared<size::FullScreen>());	

	endWin.setContent({
		centerX(text("KeyboardChad")),	
		centerABS(text("[graphic] WPM: 200; ACC: 100%")),
		buttom(centerX(text("[esc] exit    [enter] restart")))
	});

	return endWin;
}

int main() {	
	
	using namespace tui;
	Window typeWin = Window(std::make_shared<size::FullScreen>());
	const std::string generated = 
		"make each through begin buttom but think encrease live";
	
	auto input = std::make_shared<Input>(generated);

	typeWin.setContent({
		centerX(text("KeyboardChad")),	
		centerABS(input),
		buttom(centerX(text("[esc] exit    [enter] restart")))
	});

	Window endWin = initEndWindow();
	char key;

	util::enableAlterScr();
	util::hideCursor();
	
	while (true) {

		if (input->isEnd()) {	
			endWin.render();
		} else {
			typeWin.render();
		}	
		key = util::getch();
		if (key == 27) {
			util::disablAnterScr();
			util::showCursor();
			break;
		}
		
		if (!input->isEnd())
			input->press(typeWin, key);	
	}
	return 0;
}

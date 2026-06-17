#include "Elements.hpp"
#include "WinSize.hpp"
#include "Window.hpp"
#include "Util.hpp"
#include "Input.hpp"
#include <string>

using namespace tui;

int main() {	
	
	using namespace tui;
	Window typeWin = Window(std::make_shared<size::FullScreen>());
	const std::string generated = 
		"make each through begin buttom but think encrease live";
	
	auto input = std::make_shared<Input>(generated);
	typeWin.setContent({
		centerX(text("KeyboardChad")),
		centerABS(input),
		centerX(text(std::to_string(input->getWpm()))),
		buttom(centerX(text("[esc] exit    [enter] restart")))
	});

	char key;

	util::enableAlterScr();
	util::hideCursor();
	while (true) {

		if (input->isEnd()) {
			goto naxyi;
		} else {
			typeWin.setContent({
				centerX(text("KeyboardChad")),
				centerABS(input),
				centerX(text(std::to_string(input->getWpm()))),
				buttom(centerX(text("[esc] exit    [enter] restart")))
			});
			typeWin.render();
		}	
		key = util::getch();
		if (key == 27) {
			naxyi:
			util::disablAnterScr();
			util::showCursor();
			break;
		}
		
		if (!input->isEnd())
			input->press(typeWin, key);	
	}
	return 0;
}

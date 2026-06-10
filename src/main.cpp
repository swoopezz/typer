#include "WinSize.hpp"
#include "Window.hpp"
#include "Elements.hpp"
#include <memory>

int main() {	
	
	using namespace tui;

	Window window = Window(std::make_shared<size::FullScreen>());
	
	window.setContent({
		text("Zalypa"),
		text("Vtoraya zalypa very long zalpa")
	});
	
	window.render();
	return 0;
}

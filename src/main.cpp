#include "WinSize.hpp"
#include "Window.hpp"
#include "Elements.hpp"

int main() {	
	
	using namespace tui;

	Window window = Window(std::make_shared<size::FullScreen>());
	
	window.setContent({
		centerX(text("im centered")),
		centerX(text("Second texwot six seven eight forty tfasljfalk fj;jdfdsafas")),
		text("Forty two eleven six twelve")
	});

	window.render();
	return 0;
}

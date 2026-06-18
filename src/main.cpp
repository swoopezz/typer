#include "Elements.hpp"
#include "Window.hpp"
#include "Util.hpp"

using namespace tui;
int main() {	
	
	auto window = Window(std::make_shared<size::FullScreen>());
	window.setContent({
		text("Some text") | centerY,
		text("Some text") | centerY,
		text("Some text") | centerY,
	});

	window.render();

	return 0;
}


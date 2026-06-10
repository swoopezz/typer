
#include "Content.hpp"
#include "WinSize.hpp"
#include "Window.hpp"
#include "elements/Text.cpp"
#include <iostream>
#include <memory>

int main() {
	/* 
	 * Window w(size::fullscreen);
	 * w.content = {
	 * 		text("H") | abs_center,
	 * };
	 *
	 * while (true) {
	 * 		w.render();
	 * }
	*/
	
	using namespace tui;
	
	std::shared_ptr<size::WinSize> sz = std::make_shared<size::FullScreen>(size::FullScreen{});
	Window w = Window(sz);

	Elements elems = {
		std::make_shared<Text>(Text{"Zalupo zhui"}),
		std::make_shared<Text>(Text{"Another text"}),
		std::make_shared<Text>(Text{"Fcuk society"}),
	};
	w.setContent(Content(elems));
	std::cout << w.toString() << std::endl;
	return 0;
}

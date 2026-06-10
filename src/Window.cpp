#include "Window.hpp"
#include "Content.hpp"
#include "WinSize.hpp"

namespace tui {

	Window::Window(std::shared_ptr<size::WinSize>& size) : size(size), content() {}
	
	const std::string Window::toString() {
		std::string result = "";

		for (auto el : content.getElements()) {
			result += el->toString(size->get_width(), size->get_height());
		}

		return result;
	}


	void Window::setContent(const Content& c) {
		 content = c;
	}
	
}

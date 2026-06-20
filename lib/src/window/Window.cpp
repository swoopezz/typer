#include "Pixel.hpp"
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <Window.hpp>

namespace tui { 

	Window::Window(WinSize size) : 
		sz(size), 
		content(size->get_width() * size->get_height()), 
		elements({}) {
			lastWidht  = size->get_width();
			lastHeight = size->get_height();
		}

	int Window::getWidth() {
		return sz->get_width();
	}

	int Window::getHeight() {
		return sz->get_height();
	}

	bool Window::needUpdate() {
		return !(lastWidht  == sz->get_width()
			  && lastHeight == sz->get_height());
	}

	Pixel& Window::pixelAt(int x, int y) {	
		int loc = (sz->get_width() * y) + x;
		if (loc >= content.size())
			throw std::runtime_error("pixelAt: out of range!");

		return content[loc];
	}
	
	void renderPixelWithStyle(const Pixel& pixel) {

		if (pixel.isBold) std::cout << "\x1B[1m";
		if (pixel.isInvert) std::cout << "\x1B[7m";
		if (pixel.isUnderl) std::cout << "\x1B[4m";
		if (pixel.isItal) std::cout << "\x1B[3m";
		if (pixel.isStrike) std::cout << "\x1B[9m";

		std::cout << pixel.pixelContent;
		std::cout << "\x1B[0m";
	}

	void Window::render() {	
		int x = 0; int y = 1;

		if (needUpdate()) {
			content.clear();
			content = std::vector<Pixel>(
					sz->get_width()*sz->get_height()
			);
		} 

		for (auto& pixel : content) {
			pixel.clearStyles();
			pixel.pixelContent = ' ';
		}

		lastWidht = sz->get_width();
		lastHeight = sz->get_height();
		
		for (int i = 0; i < elements.size(); i++) {
			elements[i]->render(*this, x, y);
			if (y <= getHeight()) y += 1;
			x = 0;
		}

		for (const Pixel& p : content) renderPixelWithStyle(p);
		std::cout << std::endl;
	}

	void Window::setContent(Elements& newElems) {
		elements = newElems;
	}

	void Window::setContent(std::initializer_list<Element> newElems) {
		elements = newElems;
	}

}

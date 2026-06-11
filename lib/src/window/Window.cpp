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
		elements({}) {}

	int Window::getWidth() {
		return sz->get_width();
	}

	int Window::getHeight() {
		return sz->get_height();
	}

	Pixel& Window::pixelAt(int x, int y) {
		
		int loc = (sz->get_width() * y) + x;
		if (loc >= content.size())
			throw std::runtime_error("pixelAt: out of range!");

		return content[loc];
	}
	
	void Window::render() {
		
		int x = 0;
		int y = 1;

		for (int i = 0; i < elements.size(); i++) {
			elements[i]->render(*this, x, y);

			if (y <= getHeight()) {
				y += 1;
			}
			x = 0;
		}

		for (const Pixel& p : content) {
			std::cout << p.pixelContent;
		}	

		std::cout << std::endl;
	}

	void Window::setContent(Elements& newElements) {
		elements = newElements;
	}
	void Window::setContent(std::initializer_list<Element> newElements) {
		elements = newElements;
	}

}

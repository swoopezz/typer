#include "Pixel.hpp"
#include <initializer_list>
#include <iostream>
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
		return content[y * sz->get_width() + x];
	}
	
	void Window::render() {
		
		for (const Element e : elements) {
			e->render(*this);
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

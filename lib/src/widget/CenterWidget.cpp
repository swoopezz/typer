#include "Window.hpp"
#include <CenterWidget.hpp>
#include <string>

namespace tui {

	CenterWidgetX::CenterWidgetX(Element& element) : element(element){}

	std::string padding(const std::string& str, int padd) {
		const int newSize = str.size() + (padd * 2);
		std::string result(newSize, ' ');
		std::copy(str.begin(), str.end(), result.begin() + padd);

		return result;
	}

	std::string center(const std::string& str, int width) {
		return padding(str, (width - str.size()) / 2);
	}

	void CenterWidgetX::render(Window& w, int& x, int& y) {
		int size = element->toString(w).size();

		if (w.getWidth() > size) {	
			x = (w.getWidth() - size) / 2;
			element->render(w, x, y);
		} else {
			x = 0;
			element->render(w, x, y);
		}
	}	

	std::string CenterWidgetX::toString(Window& w) const {
		return center(element->toString(w), w.getWidth());
	}

	
	CenterWidgetY::CenterWidgetY(Element& element) : element(element){}

	void CenterWidgetY::render(Window& w, int& x, int& y) {
		y = w.getHeight() / 2;
		element->render(w, x, y);
	}

	std::string CenterWidgetY::toString(tui::Window& w) const {
		return element->toString(w);		
	}
}	

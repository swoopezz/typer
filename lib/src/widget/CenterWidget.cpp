#include "Window.hpp"
#include <CenterWidget.hpp>

namespace tui {

	CenterWidgetX::CenterWidgetX(Element& element) : element(element){}

	std::string padding(const std::string& str, int padd) {
		const int newSize = str.size() + (padd * 2);
		std::string result(newSize, ' ');
		std::copy(str.begin(), str.end(), result.begin() + padd);

		return result;
	}

	 std::string center(const std::string& str, int width) {
		if (str.size() > width)
			throw std::runtime_error("center: str is too long");

		return padding(str, (width - str.size()) / 2);	
	}


	void CenterWidgetX::render(Window& w, int& x, int& y) {
		std::string str = element->toString(w);
		int cachedWidth = w.getWidth();	
		for (int i = 0; i < str.size(); i+= cachedWidth) {
			for (char ch : center(str.substr(i, cachedWidth), cachedWidth)) {
				w.pixelAt(x, y).pixelContent = ch;	
				x++;
				if (x >= cachedWidth && y < w.getHeight()) {
					x = 0;
					y += 1;
				}
			}
		}

	}	

	std::string CenterWidgetX::toString(Window& w) const {
		return center(element->toString(w), w.getWidth());
	}

	
	CenterWidgetY::CenterWidgetY(Element& element) : element(element){}

	void CenterWidgetY::render(Window& w, int& x, int& y) {
		y = w.getHeight() / 2;

		for (char ch : element->toString(w)) {
			w.pixelAt(x, y).pixelContent = ch;	
			x++;
			if (x >= w.getWidth() && y < w.getHeight()) {
				x = 0;
				y += 1;
			}
		}
	}

	std::string tui::CenterWidgetY::toString(tui::Window& w) const {
		return element->toString(w);		
	}
}	

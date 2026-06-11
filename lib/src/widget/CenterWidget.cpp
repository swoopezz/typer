#include <CenterWidget.hpp>
#include <stdexcept>
#include <string>
#include <vector>

namespace tui {

	CenterWidget::CenterWidget(Element& element) : element(element){}

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


	void CenterWidget::render(Window& w, int& x, int& y) {
		std::string str = element->toString();
		
		for (int i = 0; i < str.size(); i+= w.getWidth()) {
			for (char ch : center(str.substr(i, w.getWidth()), w.getWidth())) {
				w.pixelAt(x, y).pixelContent = ch;	
				x++;
				if (x > w.getWidth()) {
					x = 0;
					y += 1;
				}
			}
		}

	}	

	// fix: get window width 
	std::string CenterWidget::toString() const {
		return center(element->toString(), 50);
	}
}

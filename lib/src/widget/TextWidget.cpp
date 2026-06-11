#include <Window.hpp>
#include <TextWidget.hpp>

namespace tui {
	TextWidget::TextWidget(const std::string& text) : text(text){};
	void TextWidget::render(Window& w, int& x, int& y) {
		for (char ch : text) {
			w.pixelAt(x, y).pixelContent = ch;
			x++;
			if (x > w.getWidth()) {
				x = 0;
				y += 1;
			}
		}
	}

	std::string TextWidget::toString(Window& w) const {
		return text;
	}
}

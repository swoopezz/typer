#include <Window.hpp>
#include <TextWidget.hpp>

namespace tui {
	TextWidget::TextWidget(const std::string& text) : text(text){};
	
	void TextWidget::render(Window& w, int& x, int& y) {
		for (char ch : text) {
			w.pixelAt(x, y).pixelContent = ch;
			x++;
			if (x > w.getWidth()) {
				x = 1; y += 1;
			}
		}
	}

	int TextWidget::getWidth() {
		return text.size();
	}

	int TextWidget::getHeight() {
		return text.size();
	}

}

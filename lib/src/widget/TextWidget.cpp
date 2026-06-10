#include <Window.hpp>
#include <TextWidget.hpp>

namespace tui {
	TextWidget::TextWidget(const std::string& text) : text(text){};
	void TextWidget::render(Window& w) {
		int counter = 0;
		for (char ch : text) {
			w.pixelAt(counter, 0).pixelContent = ch;
			counter++;
		}
	}
	const std::string& TextWidget::toString() const {
		return "fuck";
	}
}

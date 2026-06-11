#include "CenterWidget.hpp"
#include "TextWidget.hpp"
#include <Elements.hpp>
#include <memory>

namespace tui {
	Element text(const std::string& text) {
		return std::make_shared<TextWidget>(text);
	}

	Element centerX(Element elem) {
		return std::make_shared<CenterWidgetX>(elem);
	}

	Element centerY(Element elem) {
		return std::make_shared<CenterWidgetY>(elem);
	}

	Element padding(Element&, int);
	Element padding(Element&, int, int);
}

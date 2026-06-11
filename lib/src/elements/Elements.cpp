#include "CenterWidget.hpp"
#include "TextWidget.hpp"
#include <Elements.hpp>

namespace tui {
	Element text(const std::string& text) {
		return std::make_shared<TextWidget>(text);
	}

	Element centerX(Element elem) {
		return std::make_shared<CenterWidget>(elem);
	}

	Element centerY(Element&);

	Element padding(Element&, int);
	Element padding(Element&, int, int);
}

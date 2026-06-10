#include "TextWidget.hpp"
#include <Elements.hpp>
#include <Window.hpp>
#include <memory>

namespace tui {
	Element text(const std::string& text) {
		return std::make_unique<TextWidget>(text);
	}

	Element centerX(Element&);
	Element centerY(Element&);

	Element padding(Element&, int);
	Element padding(Element&, int, int);
}

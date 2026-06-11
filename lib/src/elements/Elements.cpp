#include "CenterWidget.hpp"
#include "Separator.hpp"
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
	
	Element centerABS(Element elem) {
		return centerY(centerX(elem));
	}

	Element separator() {
		return std::make_shared<Separator>();
	}
}

#include "Buttom.hpp"
#include "CenterWidget.hpp"
#include "Separator.hpp"
#include "TextWidget.hpp"
#include "Input.hpp"
#include "Graphic.hpp"
#include "Elements.hpp"
#include <memory>

namespace tui {
	Element text(const std::string& text) {
		return std::make_shared<TextWidget>(text);
	}

	Element input(const std::string& text) {
		return std::make_shared<Input>(text);
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
	
	Element buttom(Element elem) {
		return std::make_shared<Buttom>(elem);
	}

    Element graphic(std::vector<int> values) {
        return std::make_shared<Graphic>(values);
    }

    Element graphic(const std::string& title, std::vector<int> values) {
        return std::make_shared<Graphic>(title, values);
    }



	Element operator|(Element elem, Element(*func)(Element)) {
		return func(elem);
	}
}

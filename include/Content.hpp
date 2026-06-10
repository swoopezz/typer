#pragma once

#include "Element.hpp"
#include <memory>
#include <vector>

namespace tui {
using Elements = std::vector<std::shared_ptr<Element>>;

class Content {
private:
	Elements elements;

public:
	Content(Elements& elements) : elements(elements){};	

	Content() = default;

	Elements& getElements() {
		return elements;
	}
};
}

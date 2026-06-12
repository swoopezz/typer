#pragma once

#include "Widget.hpp"
#include <memory>
#include <vector>

namespace tui {

using Element = std::shared_ptr<Widget>;
using Elements = std::vector<Element>;

Element text(const std::string&);

Element centerX(Element);
Element centerY(Element);
Element centerABS(Element);

Element separator();
Element buttom(Element);

}

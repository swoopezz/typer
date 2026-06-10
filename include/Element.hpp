#pragma once 

#include <string>

namespace tui {
class Element {
public:
	virtual const std::string toString(int width, int height) = 0;
	virtual ~Element() = default;
};
}

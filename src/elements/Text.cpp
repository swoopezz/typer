#include "Element.hpp"
#include <string>
#include <string_view>

namespace tui {

class Text : public virtual Element {

private:
	std::string text;

public:
	Text(std::string_view str) : text(str){};

	const std::string toString(int width, int height) override {
		return text;
	}	
};
}

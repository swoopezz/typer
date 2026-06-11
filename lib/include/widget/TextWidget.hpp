#pragma once

#include <Widget.hpp>
#include <string>

namespace tui {

class TextWidget : public Widget {
private:
	const std::string text;
public:
	TextWidget(const std::string& text);
	void render(Window& w, int& x, int& y) override;
	virtual std::string toString(Window& w) const override;
	~TextWidget() {}
};
}

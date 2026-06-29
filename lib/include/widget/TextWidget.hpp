#pragma once

#include <Widget.hpp>
#include <string>

namespace tui {

class TextWidget : public Widget {
private:
	std::string text;
public:
	TextWidget(const std::string& text);
	void render(Window& w, int& x, int& y) override;	
	int getWidth() override;
	int getHeight() override;

	void updateText(const std::string& s) { text = s; }
	~TextWidget() {}
};
}

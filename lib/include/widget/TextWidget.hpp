#pragma once

#include <Widget.hpp>
#include <string>


namespace tui {

class TextWidget : public Widget {
private:
	const std::string text;
public:
	TextWidget(const std::string& text);
	void render(Window& w) override;
	virtual const std::string& toString() const override;
	~TextWidget() {}
};
}

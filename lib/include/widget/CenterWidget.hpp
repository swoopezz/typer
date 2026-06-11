#pragma once

#include "Window.hpp"
#include <Widget.hpp>
#include <string>

namespace tui {

class CenterWidgetX : public Widget {
private:
	const Element element;
public:
	CenterWidgetX(Element& element);
	void render(Window& w, int& x, int& y) override;
	std::string toString(Window& w) const override;
	~CenterWidgetX() {}
};

class CenterWidgetY : public Widget {
private:
	const Element element;	
public:
	CenterWidgetY(Element& element);
	void render(Window& w, int& x, int& y) override;
 	std::string toString(Window& w) const override;
	~CenterWidgetY() {}
};
}

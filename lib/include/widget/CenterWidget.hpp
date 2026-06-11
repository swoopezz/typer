#pragma once

#include "Window.hpp"
#include <Widget.hpp>
#include <string>

namespace tui {

class CenterWidget : public Widget {
private:
	const Element element;
public:
	CenterWidget(Element& element);
	void render(Window& w, int& x, int& y) override;
	virtual std::string toString() const override;
	~CenterWidget() {}
};

}

#pragma once
#include "WinSize.hpp"
#include <Pixel.hpp>
#include <Widget.hpp>
#include <initializer_list>
#include <memory>
#include <vector>

namespace tui {

class Widget;

using WinSize = std::shared_ptr<size::WinSize>;

class Window {
private:
	Elements elements;
	WinSize sz;
	
	std::vector<Pixel> content;

	int lastWidht  = 0;
	int lastHeight = 0;
public:
	Window(): sz(std::make_shared<size::FullScreen>()){};
	Window(WinSize);

	int getWidth();
	int getHeight();
	
	bool needUpdate();
	Pixel& pixelAt(int x, int y);

	void setContent(std::initializer_list<Element> content);
	void setContent(Elements& content);
	
	void render();
	const std::string& toString() const;
	
};
} // namespace tui

#pragma once

#include "Content.hpp"
#include "WinSize.hpp"
#include <memory>

namespace tui {
class Window {

private:
	Content content;
	std::shared_ptr<size::WinSize> size;

public:
	Window(std::shared_ptr<size::WinSize>& size);
	void setContent(const Content& content);
	
	const std::string toString();

	~Window() = default;
};
} // namespace tui

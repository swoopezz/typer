#pragma once 

#include <string>

namespace tui {
class Window;

class Widget {
public:
	Widget() = default;

	virtual void render(Window& w) = 0 ;
	virtual const std::string& toString() const  = 0;
	
	virtual ~Widget() = default;
};
}

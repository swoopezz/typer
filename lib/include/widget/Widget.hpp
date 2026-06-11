#pragma once 

#include <memory>
#include <vector>

namespace tui {

class Window;

class Widget {
public:
	Widget() = default;

	virtual void render(Window& w, int& x, int& y) = 0 ;
	virtual std::string toString() const  = 0;
	
	virtual ~Widget() = default;
};

using Element = std::shared_ptr<Widget>;
using Elements = std::vector<Element>;

}

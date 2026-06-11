#include <Separator.hpp>
#include <Window.hpp>
namespace tui {
	Separator::Separator(){}; 

	void Separator::render(Window& w, int& x, int& y) {
		if (w.getHeight() > y) y++;
	}

	std::string Separator::toString(Window& w) const {
		return "";
	}
}

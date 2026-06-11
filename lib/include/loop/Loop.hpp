



#include "Window.hpp"
namespace tui {
class Loop {
private:
	Window& window;
	bool toQuit = false;

public:
	Loop(Window& w) : window(w){};
	void startLoop();
	void stopLoop();
	char getChNonBlock();
};
}

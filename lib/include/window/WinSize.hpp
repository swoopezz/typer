#pragma once
#include <sys/ioctl.h>
#include <unistd.h>

namespace tui::size {
// TODO
class WinSize {
public:
	virtual int get_width() = 0;
	virtual int get_height() = 0;
};	

class FullScreen : public WinSize {
private:
	struct winsize w;

public:
	int get_width() override {
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		return w.ws_col;
	}

	int get_height() override {
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		return w.ws_row;
	}
};
}

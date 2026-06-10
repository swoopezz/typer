#pragma once

namespace tui::size {

	// TODO
	//
class WinSize {
public:
	virtual int get_width() = 0;
	virtual int get_height() = 0;
};	

class FullScreen : public WinSize {
public:
	int get_width() override {
		return 50;
	}

	int get_height() override {
		return 30;
	}
};

class WrapContent : public WinSize {
public:
	int get_width() override {
		return 50;
	}
		
	int get_height() override {
		return 30;
	}
};

}

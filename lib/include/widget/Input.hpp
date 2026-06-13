
#include <Widget.hpp>
#include <string>

namespace tui {

class Input: public Widget {
private:
	const std::string text;
	
	int cursorPosition = 0;
	std::string input = "";

	void inputLogic(Window& w, int current, int x, int y);
public:
	Input(const std::string& text);
	void render(Window& w, int& x, int& y) override;
	bool isEnd();
	virtual std::string toString(Window& w) const override;
	void press(Window& w, char c);
	~Input() {}
};
}

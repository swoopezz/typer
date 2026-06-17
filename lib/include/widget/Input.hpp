
#include <Widget.hpp>
#include <string>

namespace tui {

class Input: public Widget {
private:
	const std::string text;
	
	int cursorPosition = 0;
	std::string input = "";

	long startTimeMs = 0;
	long endTimeMs = 0;
	int missCount = 0;
	void inputLogic(Window& w, int current, int x, int y);
public:
	Input(const std::string& text);
	void render(Window& w, int& x, int& y) override;
	
	double getWpm();
	long startTime();
	long endTime();
	const std::string& getText() const;	

	int getMissCount();
	bool isEnd();
	virtual std::string toString(Window& w) const override;
	void press(Window& w, char c);
	~Input() {}
};
}

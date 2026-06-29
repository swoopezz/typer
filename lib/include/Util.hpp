
#pragma once

namespace tui::util {
	char getch();
	void enableAlterScr();
	void disablAlterScr();
	void clearScr();
	void hideCursor();
	void showCursor();
    void moveCursor(int x, int y);
}

#include "Window.hpp"
#include <algorithm>
#include "Graphic.hpp"

namespace tui {
    void Graphic::render(Window& w, int& x, int& y) {
        
        int height = w.getHeight() / 2;
        int width = params.size();

        //  0, 1, 2
        for (int _x = 0; _x < width; _x++) {
            // 1, 2, 3
            int value = std::min(params.at(_x), height);
            int counter = 0;
            for (int _y = height; _y >= value; _y--) {
                if (counter >= value) continue;
                w.pixelAt(_x, _y).isInvert = true;
                counter++;
            }
        }
    }

    int Graphic::getWidth() { return 0; }
    int Graphic::getHeight() { return 0; }
}

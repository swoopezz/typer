#include "Widget.hpp"
#include <vector>

namespace tui {

class Graphic : public Widget {
private:
    const std::string title = "";
    std::vector<int> params;

public:
    Graphic(std::vector<int>& v) : params(v) {};
    Graphic(const std::string& title, std::vector<int>& v) : 
        title(title), params(v) {};

    void render(Window& w, int& x, int& y) override;

    int getWidth() override;
    int getHeight() override;
};

}

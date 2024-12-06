#ifndef BUTTON_CLASS_HPP
#define BUTTON_CLASS_HPP

#include <ncurses.h>

class Button {
public:
    Button(int x, int y, const std::string& label) : x(x), y(y), label(label) {}

    void draw() {
        mvprintw(y, x, label.c_str());
    }

private:
    int x, y;
    std::string label;
};

#endif

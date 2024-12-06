#ifndef COLOR_CLASS_HPP
#define COLOR_CLASS_HPP

#include <ncurses.h>

class ColorClass {
public:
    static void init_colors() {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_BLUE, COLOR_BLACK);
    }

    static void set_color(int color) {
        attron(COLOR_PAIR(color));
    }

    static void reset_color() {
        attroff(COLOR_PAIR(1) | COLOR_PAIR(2) | COLOR_PAIR(3));
    }
};

#endif

#include "grid.hpp"
#include <iostream>

Grid::Grid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cells[i][j] = 0;
        }
    }
}

bool Grid::place_dice(int row, int col, int value) {
    if (cells[row][col] == 0) {
        cells[row][col] = value;
        return true;
    }
    return false;
}

int Grid::get_cell_value(int row, int col) const {
    return cells[row][col];
}

bool Grid::is_full() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (cells[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void Grid::display_grid() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << cells[i][j] << " ";
        }
        std::cout << "\n";
    }
}

#ifndef GRID_HPP
#define GRID_HPP

class Grid {
public:
    Grid();
    bool place_dice(int row, int col, int value);
    int get_cell_value(int row, int col) const;
    bool is_full() const;
    void display_grid() const;

private:
    int cells[3][3];  // 3x3 grid for the game
};

#endif

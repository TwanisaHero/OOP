// Include necessary libraries
#include <iostream>
#include <string>
#include <cstdlib> // For random number generation
#include <ctime>   // For seeding the random number generator
#include <ncurses.h> // Ncurses library for UI

// Forward declarations
class Grid;
class Dice;
class Player;

// === Dice Class ===
class Dice {
public:
    Dice() {}
    int roll() { return (std::rand() % 6) + 1; }
};

// === Grid Class ===
class Grid {
public:
    Grid() { clear_grid(); }

    bool place_dice(int col, int value) {
        for (int row = 2; row >= 0; --row) {
            if (cells[row][col] == 0) {
                cells[row][col] = value;
                return true;
            }
        }
        return false; // Column is full
    }

    void remove_matching_dice(int col, int value) {
        for (int row = 0; row < 3; ++row) {
            if (cells[row][col] == value) {
                cells[row][col] = 0;
                break;
            }
        }
    }

    int calculate_score() const {
        int score = 0;
        for (int col = 0; col < 3; ++col) {
            int col_score = 0;
            int multiplier = 1;
            for (int row = 0; row < 3; ++row) {
                if (cells[row][col] != 0) {
                    col_score += cells[row][col];
                }
            }
            score += col_score * multiplier;
        }
        return score;
    }

    void display() const {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                printw(cells[row][col] == 0 ? ". " : "%d ", cells[row][col]);
            }
            printw("\n");
        }
    }

    int get_cell_value(int row, int col) const {
        return cells[row][col];
    }

private:
    int cells[3][3];

    void clear_grid() {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                cells[row][col] = 0;
            }
        }
    }
};

// === Player Class ===
class Player {
public:
    Player(const std::string& name = "") : name(name), score(0) {}

    void take_turn(Grid& grid, Dice& dice) {
        int die_value = dice.roll();
        printw("%s rolled a %d\n", name.c_str(), die_value);

        int col;
        printw("Enter column (0, 1, 2) to place your die: ");
        scanw("%d", &col);
        while (col < 0 || col > 2 || !grid.place_dice(col, die_value)) {
            printw("Invalid column. Try again: ");
            scanw("%d", &col);
        }
    }

    void add_to_score(int points) { score += points; }

    int get_score() const { return score; }

    const std::string& get_name() const { return name; }

private:
    std::string name;
    int score;
};

// === Game Class ===
class Game {
public:
    Game() : current_player_index(0) {}

    void start() {
        std::srand(std::time(0)); // Seed random number generator
        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);

        printw("Welcome to Knucklebones!\n");

        initialize_players();

        while (!is_game_over()) {
            play_turn();
            switch_turn();
        }

        end_game();
        endwin();
    }

private:
    Dice dice;
    Grid grids[2];
    Player players[2] = { Player("Player 1"), Player("Player 2") };
    int current_player_index;

    void initialize_players() {
        printw("Enter name for Player 1: ");
        char name1[50];
        getstr(name1);
        players[0] = Player(name1);

        printw("Enter name for Player 2: ");
        char name2[50];
        getstr(name2);
        players[1] = Player(name2);
    }

    void play_turn() {
        clear();
        printw("%s's turn\n\n", players[current_player_index].get_name().c_str());

        printw("Player 1's Grid:\n");
        grids[0].display();
        printw("\nPlayer 2's Grid:\n");
        grids[1].display();

        players[current_player_index].take_turn(grids[current_player_index], dice);
    }

    void switch_turn() { current_player_index = 1 - current_player_index; }

    bool is_game_over() const {
        for (const auto& grid : grids) {
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    if (grid.get_cell_value(row, col) == 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void end_game() {
        clear();
        int score1 = grids[0].calculate_score();
        int score2 = grids[1].calculate_score();

        printw("Game Over!\n");
        printw("%s's Score: %d\n", players[0].get_name().c_str(), score1);
        printw("%s's Score: %d\n", players[1].get_name().c_str(), score2);

        if (score1 > score2) {
            printw("%s wins!\n", players[0].get_name().c_str());
        } else if (score2 > score1) {
            printw("%s wins!\n", players[1].get_name().c_str());
        } else {
            printw("It's a tie!\n");
        }

        printw("Press any key to exit.");
        getch();
    }
};

// === Main Function ===
int main() {
    Game game;
    game.start();
    return 0;
}

#ifndef GAME_HPP
#define GAME_HPP

#include "dice.hpp"
#include "grid.hpp"
#include "player.hpp"

class Game {
public:
    Game();
    void start();
    void take_turn();
    bool check_win();
    void initialize_players(std::string player1_name, std::string player2_name);
    void roll_dice();
    void display_game_state();
    void end_game();

private:
    Dice dice;
    Grid grid;
    Player* current_player;
    Player players[2];

    void switch_turn();
};

#endif

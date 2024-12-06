#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "game.hpp"

class Player {
public:
    Player(std::string name);
    void take_turn(Game& game);
    void add_to_score(int points);
    std::string get_name() const;
    int get_score() const;

private:
    std::string name;
    int score;
};

#endif

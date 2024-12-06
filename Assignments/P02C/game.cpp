#include "game.hpp"
#include "dice.hpp"
#include "grid.hpp"
#include "player.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game() : current_player(nullptr) {
    srand(time(0)); // Seed for random number generation
    players[0] = Player("Player 1");
    players[1] = Player("Player 2");
    grid = Grid();
}

void Game::start() {
    display_game_state();
    while (true) {
        take_turn();
        if (check_win()) {
            end_game();
            break;
        }
        switch_turn();
    }
}

void Game::take_turn() {
    std::cout << current_player->get_name() << "'s turn:\n";
    roll_dice();
    // Here you can add logic to place dice on the grid
    // For simplicity, we'll simulate placing a die
    int row = rand() % 3;
    int col = rand() % 3;
    grid.place_dice(row, col, dice.roll());
    current_player->add_to_score(dice.roll());
    display_game_state();
}

bool Game::check_win() {
    // Game ends when all grid cells are filled
    return grid.is_full();
}

void Game::initialize_players(std::string player1_name, std::string player2_name) {
    players[0] = Player(player1_name);
    players[1] = Player(player2_name);
}

void Game::roll_dice() {
    dice.roll();
}

void Game::display_game_state() {
    std::cout << "\nGame state:\n";
    grid.display_grid();
    for (int i = 0; i < 2; i++) {
        std::cout << players[i].get_name() << "'s score: " << players[i].get_score() << "\n";
    }
}

void Game::end_game() {
    int winner = (players[0].get_score() > players[1].get_score()) ? 0 : 1;
    std::cout << players[winner].get_name() << " wins!\n";
}

void Game::switch_turn() {
    current_player = (current_player == &players[0]) ? &players[1] : &players[0];
}

# P02C Knucklebones 

## Description
Knucklebones is a dice-based game played between two players, each having a 3x3 grid. The goal is to score more points than the opponent by placing dice on the grid and following specific rules. The game uses the Ncurses library to create a fun and interactive console experience with animations, color, and organized gameplay.

## Rules
1. **Players**: Two players, each with their own 3x3 grid.
2. **Dice Rolling**: Players roll a six-sided die each turn.
3. **Placing Dice**: Players can place a die in one of the three columns of their grid. Dice stack vertically.
4. **Scoring**:
    - Score equals the sum of the values in each column.
    - If multiple dice of the same value are placed in a column, they are multiplied together for scoring.
    - If a player places a die where the opponent already has one in the same column, the opponent's die is removed.
5. **End of Game**: The game ends when both grids are full. The player with the higher score wins.

## Components
### 1. **Game Class**:
The `Game` class manages the flow of the game, tracks player turns, and interacts with the dice and grid.
- **Responsibilities**:
    - Start, run, and end the game.
    - Roll dice and manage grid interactions.
    - Switch turns between players.
    - Display the game state using the Ncurses library.
    - Check win conditions.

```cpp
class Game {
public:
    Game();

    // Main gameplay methods
    void start();
    void take_turn();
    bool check_win();

    // Game setup and utility methods
    void initialize_players(std::string player1_name, std::string player2_name);
    void roll_dice();

    // UI-oriented methods for Ncurses
    void display_game_state();
    void end_game();

private:
    Dice dice;
    Grid grid;
    Player* current_player;
    Player players[2];

    void switch_turn();
};

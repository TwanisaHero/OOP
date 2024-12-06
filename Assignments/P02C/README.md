# P02C - KnuckleBones Game 

## Overview
KnuckleBones is a simple dice game featured in "Cult of the Lamb." The game is played on a 3x3 grid where two players take turns rolling dice and placing them on their respective grids. The goal is to score more points than your opponent by strategically placing dice and using various game mechanics. The game ends when all spaces are filled, and the player with the highest score wins.

## Game Rules
- **Two Players**: Each player has their own 3x3 grid.
- **Dice Rolling**: Players roll a six-sided die each turn.
- **Placing Dice**: Players place dice in one of the three columns of their grid.
- **Scoring**: Players score based on the sum of dice in each column. If multiple dice of the same value are placed in the same column, they are multiplied for extra points.
- **Opponent's Dice Removal**: If a player places a die that matches one of their opponent's dice in the same column, the opponent’s die is removed.
- **End of Game**: The game ends when all 9 grid spaces are filled. The player with the highest score wins.

## Game Flow
1. **Start Game**: Initialize the game and set up players.
2. **Turn Mechanics**: Players take turns rolling dice, placing them, and scoring.
3. **End Game**: After all spaces are filled, the game ends and the player with the highest score wins.

## Features
- **Ncurses**: This game uses the Ncurses library to display the game in an interactive console window, featuring colors and animated effects for a fun gameplay experience.
- **Gameplay**: Dice rolls, grid placements, and score updates are displayed in real-time.
  
## Classes
- **Game Class**: Manages the overall game flow, including players, dice, and grid.
- **Player Class**: Represents each player with their own score and name.
- **Dice Class**: Handles dice rolling.
- **Grid Class**: Manages the 3x3 grid where dice are placed.

## Setup
To run the game, ensure that Ncurses is installed. Compile the program using a C++ compiler that supports C++11 or later.

## Running the Game
1. Compile the program:
    ```bash
    g++ -o knucklebones game.cpp -lncurses
    ```
2. Run the game:
    ```bash
    ./knucklebones
    ```

---

### Program Description

KnuckleBones is an interactive dice game inspired by "Cult of the Lamb," developed using the Ncurses library. The game is implemented with object-oriented programming (OOP) principles to separate concerns, making the code modular and easier to maintain.

- **Game Class**: Responsible for the overall game flow, including controlling turns, managing the grid and dice, and determining the winner.
- **Player Class**: Handles each player's actions, such as rolling dice and managing their score.
- **Dice Class**: Manages dice rolling, returning random values between 1 and 6.
- **Grid Class**: Manages a 3x3 grid for each player where dice are placed.

This program is a fun and interactive console-based game where players can challenge each other to see who can score the most points by strategically placing dice on their grid. 

# Files

| #  | Name                                  | Description                                                |
|----|---------------------------------------|------------------------------------------------------------|
| 1  | [button_class.hpp](./button_class.hpp)       | Use to add a button to your game.                         |
| 2  | [color_class.hpp](./color_class.hpp)         | Use to easily make color pairs and use colors.             |
| 3  | [dice_class.hpp](./dice_class.hpp)           | Animate a cheesy dice square (rectangle).                  |
| 4  | [game.cpp](./game.cpp)                     | Example usage of helper classes.                           |
| 5  | [grid_class.hpp](./grid_class.hpp)           | Where you place dice values.                               |
| 6  | [input_class.hpp](./input_class.hpp)         | Captures input from users like a text box.                 |
| 7  | [log.txt](./log.txt)                       | Log file to help debug programs.                           |
| 8  | [logger_class.hpp](./logger_class.hpp)       | Class to assist logging debug statements.                  |
| 9  | [game.hpp](./game.hpp)                     | Header for the Game class that manages the overall flow.   |
| 10 | [player.cpp](./player.cpp)                 | Implementation of the Player class.                        |
| 11 | [player.hpp](./player.hpp)                 | Header for the Player class with methods for player actions. |
| 12 | [dice.cpp](./dice.cpp)                     | Implementation of the Dice class for rolling functionality. |
| 13 | [grid.cpp](./grid.cpp)                     | Implementation of the Grid class for managing the grid layout. |



---

### Notes
- This game is designed for two players, and the turns alternate between them.
- Ncurses enhances the visual experience by providing colorful outputs and animation effects.
- The game is played in a terminal, so ensure your environment supports Ncurses.

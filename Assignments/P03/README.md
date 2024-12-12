# P03 Knucklebones Game

A console-based implementation of **Knucklebones**, a dice game where players roll dice and strategically place them in a grid to maximize their scores. Built in C++ using the Ncurses library for UI.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Rules of the Game](#rules-of-the-game)
- [How to Run](#how-to-run)
- [Code Structure](#code-structure)
- [Screenshots](#screenshots)
- [Future Improvements](#future-improvements)
- [License](#license)

---

## Overview
The game consists of two players who take turns rolling a die and placing the result into one of three columns in their 3x3 grid. The goal is to outscore the opponent by strategically placing dice and leveraging multipliers. The Ncurses library is used to handle the console-based UI, providing a simple and engaging gameplay experience.

---

## Features
- Two-player mode
- Dice rolling mechanism
- Strategic grid placement
- Score calculation
- Ncurses-based UI

---

## Rules of the Game
1. Each player has a 3x3 grid.
2. On their turn, a player rolls a die (1-6).
3. The player chooses a column (0, 1, or 2) to place the rolled die.
4. Dice placed in the same column as the opponent's matching values cancel out those values.
5. The game ends when all cells in both grids are filled.
6. Scores are calculated based on the sum of each column, multiplied by the number of dice in that column.
7. The player with the higher score wins.

---

## How to Run

### Prerequisites
- **C++ Compiler**: Ensure you have `g++` or an equivalent compiler installed.
- **Ncurses Library**: Install the Ncurses library using the following command (Linux):
  ```bash
  sudo apt-get install libncurses5-dev libncursesw5-dev

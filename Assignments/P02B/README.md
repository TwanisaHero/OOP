## P02B

Here's a potential class design for the "Knucklebones" game based on the guidelines you've provided:

### 1. **Dice Class**
**Data (Attributes):**
- `sides`: (int) The number of sides on the dice (default: 6).
- `current_value`: (int) The value after a dice roll.

**Actions (Methods):**
- `roll()`: Roll the dice and randomly generate a value between 1 and `sides`.
- `get_value()`: Return the `current_value` of the dice.

**Relationships:**
- Dice will be used by the Player class for rolling during their turn.

### 2. **Player Class**
**Data (Attributes):**
- `name`: (String) The player's name.
- `score`: (int) The player's current score.
- `grid`: (3x3 list) The player's 3x3 grid for placing dice.
- `dice`: (Dice object) The dice used for rolling.
- `player_stats`: (Dict) Stats such as total rolls, wins, losses.

**Actions (Methods):**
- `roll_dice()`: Roll the dice and return the value.
- `place_dice(column, value)`: Place the rolled dice in the specified column on the grid.
- `get_score()`: Calculate and return the current score based on the grid and scoring rules.
- `update_score()`: Update the score based on any dice placement or multipliers.

**Relationships:**
- A Player HAS-A Dice (composition).
- A Player is a participant in the Game.

### 3. **Board Class**
**Data (Attributes):**
- `player1_grid`: (3x3 list) Grid for Player 1.
- `player2_grid`: (3x3 list) Grid for Player 2.

**Actions (Methods):**
- `place_die(player, column, value)`: Place a die in the specified player's column.
- `remove_opponent_die(player, column, value)`: Remove the opponent’s dice if the rolled value matches.
- `is_full()`: Check if the board is full (both players' grids are filled).
  
**Relationships:**
- The Board HAS two grids for each player (composition).
- Players place dice on the Board.

### 4. **Game Class**
**Data (Attributes):**
- `players`: (List of Player objects) The two players.
- `current_round`: (int) Tracks the current round.
- `max_rounds`: (int) Maximum number of rounds (9).

**Actions (Methods):**
- `start_game()`: Initialize the game and begin player turns.
- `end_game()`: Declare the game as finished once all rounds are complete.
- `get_winner()`: Determine the player with the highest score.

**Relationships:**
- The Game controls Player objects and manages the gameplay.

### 5. **Knucklebones Class**
**Inherits from Game**
**Data (Attributes):**
- `board`: (Board object) The playing board.
- `rules`: Specific Knucklebones game rules, including dice removal and scoring.

**Actions (Methods):**
- `start_round()`: Begin a new round of play.
- `end_round()`: End the current round, check the board status.
- `calculate_winner()`: Determine the winner based on scores.

**Relationships:**
- Knucklebones IS-A Game (inheritance).
- Knucklebones HAS-A Board (composition).


### Keywords:

- **Necessary**:
  - `player stats`
  - `score`
  - `winner`
  - `first name`

- **Possible**:
  - `high score`
  - `leaderboard`
  - `team stats`
  - `userid`

- **Wishful**:
  - `chat`
  - `coins`
  - `levels`
  - `messaging`
  - `streak`
  - `teams`
  - `last name`

### **Explanation of Inheritance and Composition:**
- **Inheritance**: The `Knucklebones` class is a specific version of a general `Game` class, meaning that Knucklebones IS-A type of Game, which justifies using inheritance here.
  
- **Composition**: A `Player` HAS-A `Dice`, and the `Knucklebones` game HAS-A `Board`, meaning they are built from these objects. The `Game` and `Player` classes also use composition because the game controls players, and players use dice.
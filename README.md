# Snake-Game-by-Venomous-Bytes

## Overview
This is a classic Snake Game implemented in C++ using the Windows console. The game features dynamic or constant speed modes, a high-score tracking system, and colorful console-based graphics using Unicode characters.

## Features
- **Dynamic and Constant Speed Modes**: Players can choose between a fixed-speed mode and a progressively increasing speed mode.
- **High Score Tracking**: The game saves and loads the highest score from a file (`high_score.txt`).
- **Wall Collision Detection**: The game ends if the snake collides with the walls.
- **Self-Collision Detection**: The game ends if the snake collides with itself.
- **Smooth Controls**: Players can control the snake using `W`, `A`, `S`, and `D` keys.
- **Console-Based Graphics**: Uses Unicode characters for visual elements like the snake, walls, and food.

## How to Play
1. Run the executable file in the Windows console.
2. Choose a game mode:
   - Press `(A)` for Constant Speed Mode.
   - Press any other key for Dynamic Speed Mode.
3. Use the following controls to move the snake:
   - `W` - Move Up
   - `A` - Move Left
   - `S` - Move Down
   - `D` - Move Right
4. The goal is to eat the **apple (`🍎`)** and grow longer while avoiding collisions.
5. The game ends if you hit the **walls (`🧱`)** or **bite** yourself (`🐍`).
6. If you achieve a new high score, it will be saved.

## Code Structure
### `gameBoard` Class
- Defines the dimensions of the game area.
- Responsible for rendering the game elements (walls, snake, food, and score).

### `Food` Class
- Generates food at a random position within the game board.
- Ensures that food is not generated on the snake's body.

### `Snake` Class
- Handles the movement and growth of the snake.
- Stores the head position in HeadX and HeadY variables and stores body positions in a `vector<pair<int, int>>`.

### `logic()` Function
- Updates the snake's position based on the player's input.
- Checks for collisions with walls and itself.
- Handles food consumption and growth logic.

### `input()` Function
- Detects keyboard inputs and updates the snake's direction.
- Prevents invalid movement (e.g., moving directly opposite to the current direction).

### `gameOverScreen()` Function
- Displays the final score and high score.
- Provides an option to replay or quit the game.

### `welcome()` Function
- It welcomes the user to the game with a colorful and beautiful ASCII art.
## Libraries Used
- `<iostream>`: For input and output operations.
- `<cstdlib>`: For random number generation.
- `<vector>`: To store the snake's body segments.
- `<windows.h>`: For console manipulation (cursor movement and visibility control).
- `<conio.h>`: For non-blocking keyboard input.
- `<algorithm>`: For handling vector operations like `rotate()`.

## Installation and Execution
1. Compile the C++ source file using a compiler that supports Windows API functions (e.g., MinGW g++ or MSVC).
2. Run the compiled executable in the Windows Command Prompt.

```sh
 g++ snake_game.cpp -o snake_game.exe
 ./snake_game.exe
```

## Credits
This project was developed by the following students:

- **Anghan Nena** - 202401053
- **Jay Lavingiya** - 202401105
- **Kureshi Ruhan** - 202401103
- **Manali Malani** - 202401111

## Future Improvements
- Add a pause and resume feature.
- Implement different difficulty levels.
- Make the game cross-platform by replacing Windows-specific functions with standard C++ alternatives.

---
This Snake Game was developed as part of a learning project. Contributions and suggestions for improvement are welcome!


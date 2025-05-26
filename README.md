# Terminal Snake Game

A classic Snake game implementation that runs in your terminal using the ncurses library.

## Description

Terminal Snake is a simple yet entertaining implementation of the classic Snake game that runs directly in your terminal. Control the snake, eat food to grow longer, and avoid colliding with your own tail!

## Features

- Smooth terminal-based graphics using ncurses
- Simple and intuitive controls
- Snake growth mechanics
- Score tracking
- Screen wrapping (snake can move through walls)
- Randomized food placement

## Dependencies

- C++ compiler (g++ or clang++)
- ncurses library

## Installation

### Installing ncurses

On Debian/Ubuntu:
```
sudo apt-get install libncurses5-dev libncursesw5-dev
```

On Fedora:
```
sudo dnf install ncurses-devel
```

On macOS (using Homebrew):
```
brew install ncurses
```

### Compiling the game

```
g++ -o snake main.cpp -lncurses
```

## How to Play

1. Run the compiled game:
```
./snake
```

2. Use the following controls to play:
   - `W` or `↑`: Move up
   - `A` or `←`: Move left
   - `S` or `↓`: Move down
   - `D` or `→`: Move right
   - `X` or `Q`: Quit the game

3. Eat the food (X) to grow your snake and increase your score
4. Avoid colliding with your own tail
5. The snake can move through walls and appear on the opposite side

## Game Elements

- `O`: Snake's head
- `o`: Snake's body
- `X`: Food
- `#`: Border
- Score is displayed at the bottom of the screen


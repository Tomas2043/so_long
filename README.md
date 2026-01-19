*This project has been created as part of the 42 curriculum by **toandrad**.*

# so_long

## Description

so_long is a small 2D game built using the MiniLibX graphics library. The objective is to navigate a player character through a map, collecting all collectibles and reaching the exit in the minimum number of moves.

The project introduces the basics of game development, including:
- Window management and event handling
- Sprite rendering and tile-based graphics
- Map parsing and validation
- Pathfinding algorithms (flood fill)

### Game Rules

- The player must collect all collectibles (`C`) before the exit (`E`) becomes accessible
- The player cannot walk through walls (`1`)
- Movement is controlled using `W`, `A`, `S`, `D` or arrow keys
- Press `ESC` or click the window's close button to exit
- The move count is displayed in the terminal after each movement

## Instructions

### Prerequisites

- GCC compiler
- Make
- X11 development libraries (Linux)

On Ubuntu/Debian, install dependencies with:
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### Compilation

Clone the repository and compile:
```bash
git clone <repository-url>
cd so_long
make
```

This will compile the MiniLibX library, libft, and the game executable.

### Execution

Run the game with a map file as argument:
```bash
./so_long maps/map.ber
```

### Map Format

Maps must be `.ber` files with the following format:
- `1` - Wall
- `0` - Empty space
- `P` - Player starting position (exactly one required)
- `C` - Collectible (at least one required)
- `E` - Exit (exactly one required)

Example map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

Maps must be:
- Rectangular
- Surrounded by walls
- Contain a valid path from the player to all collectibles and the exit

### Controls

| Key | Action |
|-----|--------|
| `W` / `Up Arrow` | Move up |
| `S` / `Down Arrow` | Move down |
| `A` / `Left Arrow` | Move left |
| `D` / `Right Arrow` | Move right |
| `ESC` | Exit game |

### Makefile Rules

| Rule | Description |
|------|-------------|
| `make` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executable |
| `make re` | Recompile the project |

## Resources

### Documentation

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42 Docs - so_long](https://harm-smits.github.io/42docs/projects/so_long)
- [X11 Programming Manual](https://tronche.com/gui/x/xlib/)

### Tutorials

- [MiniLibX Tutorial by 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- [Flood Fill Algorithm - Wikipedia](https://en.wikipedia.org/wiki/Flood_fill)

### AI Usage

AI was used as an assistance tool during this project for the following tasks:

- **Code Review**: AI was used to identify potential bugs, memory leaks, and edge cases in the codebase
- **Debugging**: AI helped diagnose issues such as the move counter incrementing on non-movement keypresses and the missing `validate_path()` function call
- **Documentation**: AI assisted in generating this README file following the 42 requirements

All code was written and understood by the student. AI was used as a learning and debugging aid, not as a code generator.

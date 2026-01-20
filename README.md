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

### Compilation

First off, extract the MiniLibX library:

```bash
tar -xf minilibx-linux.tgz
```

Then run:

```bash
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

```bash
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

Maps must be:

- Rectangular
- Surrounded by walls
- Solvable (all collectibles and exits are accessible to the player)

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

- [MiniLibX Tutorial by 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- [Flood Fill Algorithm - Wikipedia](https://en.wikipedia.org/wiki/Flood_fill)

### AI Usage

AI was used as an assistance tool during this project for the following tasks:

- **Project studying**: AI helped me understand basic concepts of the project before starting.
- **Code Review and testing**: AI was used to identify potential bugs, memory leaks, and edge cases in the project.`

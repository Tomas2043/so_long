/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:52:01 by toandrad          #+#    #+#             */
/*   Updated: 2025/11/10 11:58:22 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define TILE_SIZE 64

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectibles;
}	t_map;

typedef struct s_flood
{
	int	collectibles;
	int	exit_found;
}	t_flood;

typedef struct s_counter
{
	int	player_count;
	int	exit_count;
}	t_counter;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	exit_img;
	t_img	collectible;
	int		moves;
	int		collected;
}	t_game;

t_map	*parse_map(char *filename);
int		validate_map(t_map *map);
void	free_map(t_map *map);
void	print_map(t_map *map);
void	error_exit(char *message);
void	set_map_variables(t_map *map, t_counter *cnt, int x, int y);
int		validate_path(t_map *map);

t_game	*init_game(char *map_file);
void	load_textures(t_game *game);
void	init_window(t_game *game);

void	render_map(t_game *game);
void	put_img(t_game *game, t_img img, int x, int y);

int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);

#endif

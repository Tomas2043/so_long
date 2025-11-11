/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:34:34 by tomas             #+#    #+#             */
/*   Updated: 2025/11/10 12:35:36 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static t_img	load_image(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	if (!img.img)
	{
		ft_printf("Error\n Failed to load texture: %s\n", path);
		exit(1);
	}
	return (img);
}

void	load_textures(t_game *game)
{
	game->wall = load_image(game->mlx, "textures/wall.xpm");
	game->floor = load_image(game->mlx, "textures/floor.xpm");
	game->player = load_image(game->mlx, "textures/player.xpm");
	game->collectible = load_image(game->mlx, "textures/collectible.xpm");
	game->exit_img = load_image(game->mlx, "texture/exit.xpm");
}

void	init_window(t_game *game)
{
	int	min_width;
	int	min_height;

	min_width = game->map->width * TILE_SIZE;
	min_height = game->map->height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, min_width, min_height, "so_long");
	if (!game->win)
		error_exit("Error: Failed to create window");
}

t_game	*init_game(char *map_file)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		error_exit("Error: Memory allocation failed");
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error: MLX Initialization failed");
	game->map = parse_map(map_file);
	if (!validate_map(game->map))
		error_exit("Error: Invalid map");
	if (!validate_map(game->map))
		error_exit("Error: Map is not solvable");
	game->moves = 0;
	game->collected = 0;
	load_textures(game);
	init_window(game);
	return (game);
}

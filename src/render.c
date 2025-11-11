/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:33:48 by tomas             #+#    #+#             */
/*   Updated: 2025/11/10 13:27:56 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_img(t_game *game, t_img img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img.img,
		x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_tile(t_game *game, int x, int y)
{
	char	tile;
	
	tile = game->map->grid[y][x];
	put_img(game, game->floor, x, y);
	if (tile == WALL)
		put_img(game, game->wall, x, y);
	else if (tile == COLLECTIBLE)
		put_img(game, game->collectible, x, y);
	else if (tile == EXIT)
		put_img(game, game->exit_img, x, y);
	else if (tile == PLAYER, x, y)
		put_img(game, game->player, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

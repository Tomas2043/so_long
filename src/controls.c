/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:35:14 by tomas             #+#    #+#             */
/*   Updated: 2025/11/10 14:27:34 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	can_move(t_game *game, int new_x, int new_y)
{
	char	tile;

	if (new_x < 0 || new_x >= game->map->width
		|| new_y < 0 || new_y >= game->map->height)
		return (0);
	tile = game->map->grid[new_y][new_x];
	if (tile == WALL)
		return (0);
	if (tile == EXIT && game->collected < game->map->collectibles)
		return (0);
	return (1);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	char	tile;

	tile = game->map->grid[new_y][new_x];
	if (tile == COLLECTIBLE)
	{
		game->collected++;
		game->map->grid[new_y][new_x] = EMPTY;
	}
	else if (tile == EXIT && game->collected == game->map->collectibles)
	{
		ft_printf("\n🎉 YOU WIN! 🎉\n");
		ft_printf("Total moves: %d\n", game->moves + 1);
		handle_close(game);
	}
	game->map->grid[game->map->player_y][game->map->player_x] = EMPTY;
	game->map->grid[new_y][new_x] = PLAYER;
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:35:14 by tomas             #+#    #+#             */
/*   Updated: 2025/11/11 12:31:45 by toandrad         ###   ########.fr       */
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
	int	new_x;
	int	new_y;

	new_x = game->map->player_x;
	new_y = game->map->player_y;
	if (keycode == KEY_ESC)
		handle_close(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		new_x++;
	if (can_move(game, new_x, new_y))
		move_player(game, new_x, new_y);
	return (0);
}

int	handle_close(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

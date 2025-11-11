/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:51:32 by toandrad          #+#    #+#             */
/*   Updated: 2025/11/11 11:21:35 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_exit(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}

void	print_map(t_map *map)
{
	int	i;

	ft_printf("\n=== MAP INFO ===\n");
	ft_printf("Width: %d, Height: %d\n", map->width, map->height);
	ft_printf("Player: (%d, %d)\n", map->player_x, map->player_y);
	ft_printf("Exit: (%d, %d)\n", map->exit_x, map->exit_y);
	ft_printf("Collectibles: %d\n\n", map->collectibles);
	i = 0;
	while (i < map->height)
	{
		ft_printf("%s", map->grid[i]);
		i++;
	}
	ft_printf("============\n\n");
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->exit_img.img)
		mlx_destroy_image(game->mlx, game->exit_img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	free(game);
}

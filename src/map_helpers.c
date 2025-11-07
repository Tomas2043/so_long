/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:59:02 by toandrad          #+#    #+#             */
/*   Updated: 2025/10/30 13:39:59 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_map_variables(t_map *map, int player_count, int exit_count, int x,
	int y)
{
	if (map->grid[y][x] == PLAYER)
	{
		map->player_x = x;
		map->player_y = y;
		player_count++;
	}
	else if (map->grid[y][x] == EXIT)
	{
		map->exit_x = x;
		map->exit_x = y;
		exit_count++;
	}
	else if (map->grid[y][x] == COLLECTIBLE)
		map->collectibles++;
}

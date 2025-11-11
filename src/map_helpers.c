/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:59:02 by toandrad          #+#    #+#             */
/*   Updated: 2025/11/07 14:53:25 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_map_variables(t_map *map, t_counter *cnt, int x, int y)
{
	if (map->grid[y][x] == PLAYER)
	{
		map->player_x = x;
		map->player_y = y;
		cnt->player_count++;
	}
	else if (map->grid[y][x] == EXIT)
	{
		map->exit_x = x;
		map->exit_y = y;
		cnt->exit_count++;
	}
	else if (map->grid[y][x] == COLLECTIBLE)
		map->collectibles++;
}

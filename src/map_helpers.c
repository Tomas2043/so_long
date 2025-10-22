/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:59:02 by toandrad          #+#    #+#             */
/*   Updated: 2025/10/22 13:09:02 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_map_variables(t_map *map, int player_count, int exit_count, int x,
	int y)
{
	if (map->grid[y][x] == PLAYER)
	{
		map->player_x = x;
		map->player_x = y;
		player_count++;
	}
	else if (map->grid[y][x] == EXIT)
	{
		map->player_x = x;
		map->player_y = y;
		exit_count++;
	}
	else if (map->grid[y][x] == COLLECTIBLE)
		map->collectibles++;
}

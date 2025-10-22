/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:13:52 by toandrad          #+#    #+#             */
/*   Updated: 2025/10/22 12:51:16 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->grid[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != WALL)
			return (0);
		if (map->grid[map->height - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != WALL)
			return (0);
		if (map->grid[i][map->width - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	has_valid_characters(t_map *map)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->grid[y][x];
			if (c != WALL && c != EMPTY && c != COLLECTIBLE
				&& c != EXIT && c != PLAYER)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	if (!is_rectangular(map))
		error_exit("Error: Map must be rectangular");
	if (!is_surrounded_by_walls(map))
		error_exit("Error: Map must be surrounded by walls");
	if (!has_valid_characters(map))
		error_exit("Error: Map contains invalid characters");
}

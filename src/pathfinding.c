/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:10:14 by tomas             #+#    #+#             */
/*   Updated: 2025/10/30 14:48:43 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	**copy_grid(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **grid_copy, int x, int y, t_map *map,
	int	**collectibles, int *exit_found)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (grid_copy[y][x] == WALL || grid_copy[y][x] == 'v')
		return ;
	if (grid_copy[y][x] == COLLECTIBLE)
		(*collectibles)++;
	if (grid_copy[y][x] == EXIT)
		*exit_found = 1;
	grid_copy
}

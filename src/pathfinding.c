/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:10:14 by tomas             #+#    #+#             */
/*   Updated: 2025/11/10 10:51:53 by tomas            ###   ########.fr       */
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

static void	free_grid_copy(char **grid_copy, int height)
{
	int	i;

	if (!grid_copy)
		return ;
	i = 0;
	while (i < height)
	{
		free(grid_copy[i]);
		i++;
	}
	free(grid_copy);
}

static void	check_cell(char **grid, int x, int y, t_flood *data)
{
	if (grid[y][x] == COLLECTIBLE)
		data->collectibles++;
	if (grid[y][x] == EXIT)
		data->exit_found = 1;
	grid[y][x] = 'v';
}

static void	do_flood(char **grid, int xy[4], t_flood *data)
{
	if (xy[0] < 0 || xy[0] >= xy[2] || xy[1] < 0 || xy[1] >= xy[3])
		return ;
	if (grid[xy[1]][xy[0]] == WALL || grid[xy[1]][xy[0]] == 'v')
		return ;
	check_cell(grid, xy[0], xy[1], data);
	xy[0]++;
	do_flood(grid, xy, data);
	xy[0] -= 2;
	do_flood(grid, xy, data);
	xy[0]++;
	xy[1]++;
	do_flood(grid, xy, data);
	xy[1] -= 2;
	do_flood(grid, xy, data);
	xy[1]++;
}

int	validate_path(t_map *map)
{
	char	**grid_copy;
	t_flood	data;
	int		xy[4];

	grid_copy = copy_grid(map);
	if (!grid_copy)
		error_exit("Error: Memory allocation failed for pathfinding");
	data.collectibles = 0;
	data.exit_found = 0;
	xy[0] = map->player_x;
	xy[1] = map->player_y;
	xy[2] = map->width;
	xy[3] = map->height;
	do_flood(grid_copy, xy, &data);
	free_grid_copy(grid_copy, map->height);
	if (data.collectibles != map->collectibles)
	{
		ft_printf("Found %d/%d collectibles.\n", data.collectibles,
			map->collectibles);
		return (0);
	}
	if (!data.exit_found)
		return (ft_printf("Exit is unreachable.\n"), 0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:35:30 by toandrad          #+#    #+#             */
/*   Updated: 2025/11/07 15:20:27 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_lines(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error: Cannot open map file");
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

char	**read_map_lines(char *filename, int height)
{
	char	**grid;
	char	*line;
	int		fd;
	int		i;

	grid = malloc(sizeof(char *) * (height + 1));
	if (!grid)
		error_exit("Error: Memory allocation failed");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error: Cannot open map file");
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd);
		if (!line)
			error_exit("Error: Reading map failed");
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		grid[i] = line;
		i++;
	}
	grid[i] = NULL;
	close(fd);
	return (grid);
}

void	find_game_elements(t_map *map)
{
	int			x;
	int			y;
	t_counter	cnt;

	cnt.player_count = 0;
	cnt.exit_count = 0;
	map->collectibles = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			set_map_variables(map, &cnt, x, y);
			x++;
		}
		y++;
	}
	if (cnt.player_count != 1)
		error_exit("Error: Map must have exactly one player.");
	if (cnt.exit_count != 1)
		error_exit("Error: Map must have exactly one exit.");
	if (map->collectibles < 1)
		error_exit("Error: Map must have at least one collectible.");
}

t_map	*parse_map(char *filename)
{
	t_map	*map;

	if (ft_strlen(filename) < 4)
		error_exit("Error: Map file must be .ber");
	if (ft_strncmp (filename + ft_strlen(filename) - 4, ".ber", 4) != 0)
		error_exit("Error: Map file must be .ber");
	map = malloc(sizeof(t_map));
	if (!map)
		error_exit("Error: Memory allocation failed");
	map->height = count_lines(filename);
	map->grid = read_map_lines(filename, map->height);
	map->width = ft_strlen(map->grid[0]);
	find_game_elements(map);
	return (map);
}

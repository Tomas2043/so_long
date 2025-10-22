/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:52:01 by toandrad          #+#    #+#             */
/*   Updated: 2025/10/22 13:07:51 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectibles;
}	t_map;

t_map	*parse_map(char *filename);
int		validate_map(t_map *map);
void	free_map(t_map *map);
void	print_map(t_map *map);
void	error_exit(char *message);

void	set_map_variables(t_map *map, int player_count, int exit_count, int x, int y);

int		validate_path(t_map *map);
void	flood_fill(char **grid_copy, int x, int y, t_map *map, int *collectibles, int *exit_found);

#endif

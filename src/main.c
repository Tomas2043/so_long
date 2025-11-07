/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:50:19 by tomas             #+#    #+#             */
/*   Updated: 2025/10/30 13:55:37 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (ft_putstr_fd("Usage: ./so_long <map.ber>\n", 2), 1);
	ft_printf("Parsing map: %s\n", av[1]);
	map = parse_map(av[1]);
	ft_printf("Map parsed successfully!\n");
	print_map(map);
	ft_printf("Validating map structure...\n");
	validate_map(map);
	ft_printf("Map structure is valid\n");
	ft_printf("Checking if map is solvable\n");
	if (!validate_path(map))
		error_exit("Error: Map is not solvable - collectibles or exit unreachable");
	ft_printf("Map is solvable!\n");
	ft_printf("\n All checks passed! Map is ready to play!\n");
	free_map(map);
}
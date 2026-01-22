/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:50:19 by tomas             #+#    #+#             */
/*   Updated: 2026/01/22 10:54:37 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (ft_putstr_fd("Usage: ./so_long <map.ber>\n", 2), 1);
	game = init_game(av[1]);
	if (!game)
		return (1);
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	mlx_loop(game->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:30:33 by jumoncad          #+#    #+#             */
/*   Updated: 2023/06/28 17:01:57 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_finishable_map(t_game game, int x, int y, int *count)
{
	if (game.mapcopy[x][y] == 'C' || game.mapcopy[x][y] == 'E')
		(*count)++;
	if (game.mapcopy[x][y] != '1' && game.mapcopy[x][y] != 'K'
		&& game.mapcopy[x][y])
	{
		game.mapcopy[x][y] = '1';
		ft_finishable_map(game, x + 1, y, count);
		ft_finishable_map(game, x - 1, y, count);
		ft_finishable_map(game, x, y + 1, count);
		ft_finishable_map(game, x, y - 1, count);
	}
}

static int	argv_checker(char *argv)
{
	if (!argv)
		return (0);
	if (ft_strnstr(argv, ".ber"))
		return (1);
	return (0);
}

void	so_long(char *map)
{
	t_game	game;

	game.map = read_map(map);
	game.mapcopy = copy_map(game.map);
	game.row_map = count_rows(game.map);
	game.col_map = count_columns(game.map);
	game.p_x_player = search_position_x(game, 'P');
	game.p_y_player = search_position_y(game, 'P');
	ft_finishable_map(game, game.p_x_player, game.p_y_player, &game.count);
	if (map_checker(&game) && argv_checker(map) 
		&& game.count == game.n_colect + 1)
		init(game);
	else
	{
		if (game.map)
			free_map(game.map);
		ft_putstr_fd("Error: Map not playable", 1);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else
	{
		ft_putstr_fd("Error: Invalid Sytax", 1);
		exit(1);
	}
	return (0);
}

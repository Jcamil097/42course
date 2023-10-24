/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:30:33 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
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
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv [i - 3] == '.')
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
	game.count = 0;
	if (map_checker(&game))
	{
		ft_finishable_map(game, game.p_x_player, game.p_y_player, &game.count);
		if (game.count == game.n_colect + 1)
			init(game);
		else
			ft_putstr_fd("Error: Map not playable ", 1);
	}
	if (game.map)
		free_map(game.map);
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv_checker(argv[1]))
			so_long(argv[1]);
		else
		{
			ft_putstr_fd("Error: Invalid File", 1);
			exit(1);
		}
	}
	else
	{
		ft_putstr_fd("Error: Arguments", 1);
		exit(1);
	}
	return (0);
}

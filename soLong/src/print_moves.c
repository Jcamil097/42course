/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:52:03 by igvaz-fe          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

void	print_winner(t_game *game)
{
	int	w;

	w = game->map_w / 2;
	mlx_string_put(game->mlx, game->win, w, 20, 0xFFFFFF, "WINNER");
	mlx_string_put(game->mlx, game->win,
		w - 10, 40, 0xFFFFFF, "PRESS ESC OR Q");
}

void	display_moves(t_game *game)
{
	char	*str;
	char	*n_coins;

	str = ft_itoa(game->moves);
	n_coins = ft_itoa(game->n_colect);
	mlx_string_put(game->mlx, game->win, 25, 20, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game->mlx, game->win, 90, 20, 0xFFFFFF, str);
	mlx_string_put(game->mlx, game->win, 25, 50, 0xFFFFFF, "COINS: ");
	mlx_string_put(game->mlx, game->win, 90, 50, 0xFFFFFF, n_coins);
	free(str);
	free(n_coins);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:52:03 by igvaz-fe          #+#    #+#             */
/*   Updated: 2023/06/13 13:06:47 by jumoncad         ###   ########.fr       */
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
	mlx_string_put(game->mlx, game->win, 600, 10, 0xFFFFFF, "WINNER");
	mlx_string_put(game->mlx, game->win, 580, 30, 0xFFFFFF, "PRESS ESC OR Q");
}

void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 25, 20, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game->mlx, game->win, 90, 20, 0xFFFFFF, str);
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:52:03 by igvaz-fe          #+#    #+#             */
/*   Updated: 2023/06/09 17:09:00 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_putstr_fd(char *s, int fd)
{
	unsigned int len;

	len = ft_strlen(s);
	write(fd, s, len);
}

void display_moves(t_game *game)
{
	char *str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 25, 20, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game->mlx, game->win, 90, 20, 0xFFFFFF, str);
	free(str);
}

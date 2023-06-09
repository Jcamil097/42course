/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:51:51 by igvaz-fe          #+#    #+#             */
/*   Updated: 2023/06/09 17:01:45 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_backg);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_colect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_enemie);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}

static void	game_events(int keycode, t_game *game)
{
	if (keycode == W || keycode == UP)
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if (keycode == S || keycode == DOWN)
	{
		game->y_player += 1;
		player_s(game);
	}
	else if (keycode == D || keycode == RIGHT)
	{
		game->x_player += 1;
		player_d(game);
	}
	else if (keycode == A || keycode == LEFT)
	{
		game->x_player -= 1;
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
		exit_game(game);
	else if (!game->endgame)
		game_events(keycode, game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->win, 9, 1L << 21, map_draw, game);
	mlx_loop_hook(game->mlx, animation, game);
}

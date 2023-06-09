/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:51:55 by igvaz-fe          #+#    #+#             */
/*   Updated: 2023/06/09 16:44:56 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	img_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image
		(game->mlx, "assets/images/cesped.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "assets/images/muro.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/images/magoR.xpm", &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image
		(game->mlx, "assets/images/skull.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "assets/images/salida.xpm", &game->img_w, &game->img_h);
	game->img_enemie = mlx_xpm_file_to_image
		(game->mlx, "assets/images/ene1.xpm", &game->img_w, &game->img_h);
	game->img_final = mlx_xpm_file_to_image
		(game->mlx, "assets/images/final.xpm", &game->img_w, &game->img_h);
}

static void	size_window_init(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 64;
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i * 64 + 64;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	size_window_init(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->moves = 0;
	game->endgame = 0;
	game->pos_enemies = 1;
	game->loop = 0;
	img_init(game);
	map_draw(game);
}

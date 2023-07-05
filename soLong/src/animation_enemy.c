/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:09:18 by jumoncad          #+#    #+#             */
/*   Updated: 2023/07/05 11:10:02 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	change_img1(t_game *game)
{
	game->img_enemie = mlx_xpm_file_to_image
		(game->mlx, "assets/textures/ene1.xpm", &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image
		(game->mlx, "assets/textures/mon1.xpm", &game->img_w, &game->img_h);
}

void	change_img2(t_game *game)
{
	game->img_enemie = mlx_xpm_file_to_image
		(game->mlx, "assets/textures/ene2.xpm", &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image
		(game->mlx, "assets/textures/mon2.xpm", &game->img_w, &game->img_h);
}

void	change_img3(t_game *game)
{
	game->img_enemie = mlx_xpm_file_to_image
		(game->mlx, "assets/textures/ene3.xpm", &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image
		(game->mlx, "assets/textures/mon1.xpm", &game->img_w, &game->img_h);
}

void	change_img4(t_game *game)
{
	game->img_enemie = mlx_xpm_file_to_image
		(game->mlx, "assets/textures/ene4.xpm", &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image
		(game->mlx, "assets/textures/mon1.xpm", &game->img_w, &game->img_h);
}

int	animation(t_game *game)
{
	if (game->loop < 1000)
	{
		game->loop++;
		return (0);
	}
	game->loop = 0;
	mlx_destroy_image(game->mlx, game->img_enemie);
	mlx_destroy_image(game->mlx, game->img_colect);
	if (game->pos_enemies == 1)
		change_img1(game);
	else if (game->pos_enemies == 2)
		change_img2(game);
	else if (game->pos_enemies == 3)
		change_img3(game);
	else if (game->pos_enemies == 4)
	{
		change_img4(game);
		game->pos_enemies = 0;
	}
	game->x_enemy = game->x_enemy + 1;
	game->y_enemy = game->y_enemy + 1;
	map_draw(game);
	game->pos_enemies++;
	return (0);
}

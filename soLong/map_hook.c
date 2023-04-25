/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:17:17 by jumoncad          #+#    #+#             */
/*   Updated: 2023/04/25 15:17:57 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	are_there_coins(t_data *data, t_img *img)
{
	int		width;
	int		height;
	int		pos;

	pos = 0;
	while (data->map[pos] && data->map[pos] != 'C')
		pos++;
	if (data->map[pos] != 'C')
	{
		img->slime[0] = mlx_xpm_file_to_image(data->mlx,
				"imagenes/Perro/memeperro2.xpm", &width, &height);
		img->slime[1] = mlx_xpm_file_to_image(data->mlx,
				"imagenes/Perro/memeperro3.xpm", &width, &height);
		return (1);
	}
	return (0);
}

int	are_there_door(t_data data, t_img *img)
{
	int		pos;

	pos = 0;
	while (data.map[pos] && data.map[pos] != 'E')
		pos++;
	if (data.map[pos] != 'E')
	{
		data.win = mlx_new_window(data.mlx, 400, 300,
				"YOU WIN, press esc to quit");
		mlx_put_image_to_window(data.mlx, data.win, img->salida[0], 0, 0);
		mlx_key_hook(data.win, key_destroy, &data);
		mlx_hook(data.win, 17, 0, destroy, &data);
		mlx_loop(data.mlx);
		return (1);
	}
	return (0);
}

int	fail(t_data data, t_img *img, int next)
{
	if (data.map[next] == 'W' || data.map[next] == 'w' || data.map[next] == 'J')
	{
		data.win = mlx_new_window(data.mlx, 500, 300,
				"YOU LOSE, press esc to quit");
		mlx_put_image_to_window(data.mlx, data.win, img->salida[1], 0, 0);
		mlx_key_hook(data.win, key_destroy, &data);
		mlx_hook(data.win, 17, 0, destroy, &data);
		mlx_loop(data.mlx);
		data.map[0] = 'J';
		return (1);
	}
	return (0);
}
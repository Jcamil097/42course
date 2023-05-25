/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:18:57 by jumoncad          #+#    #+#             */
/*   Updated: 2023/05/25 13:13:15 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int make_img(t_data *data)
{
	t_img img;
	static int	count = 0;

	count++;
	img = data->img;
	if (count == 1000 && !are_there_door(*data, &data->img)
		&& !fail(*data, &data->img, 0))
	{
		count = 0;
		make_ground(*data, img);
		make_obj(*data, img);
		make_corner(*data, img);
		make_enemy(*data, img, 1);
	}
	return (0);
}

int	key_destroy(int keycode, t_data *data)
{
	if (keycode == ESC || keycode == Q)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	return (0);
}

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

int main(int argc, char *argv[])
{
	t_data data;

	if (argc != 2)
		ft_putstr_fd("error cantidad de argumentos\n", 1);
	data.mlx = mlx_init();
	data = save_map(data, argv[1]);
	find_exit(data);
	data.win = mlx_new_window(data.mlx, data.height, data.width, "SO_LONG");
	data.img = save_img(data);
	mlx_loop_hook(data.mlx, make_img, &data);
	mlx_hook(data.win, 2, 0, moves, &data);
	mlx_key_hook(data.win, key_destroy, &data);
	mlx_hook(data.win, 17, 0, destroy, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
}

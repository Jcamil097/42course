/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:52:12 by jumoncad          #+#    #+#             */
/*   Updated: 2023/05/25 13:13:10 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	make_ground(t_data data, t_img img)
{
	int		i;
	int		j;

	i = 0;
	while (i < data.height)
	{
		j = 0;
		while (j < data.width)
		{
			mlx_put_image_to_window(data.mlx, data.win, img.cesped, i, j);
			j = j + 32;
		}
		i = i + 32;
	}
}

void	make_corner(t_data data, t_img img)
{
	int	i;

	i = 0;
	while (i < data.height)
	{	
		mlx_put_image_to_window(data.mlx, data.win, img.muro, i, 0);
		mlx_put_image_to_window(data.mlx, data.win, img.muro, i, data.width - 64);
		i = i + 64;
	}
	i = 0;
	while (i < data.width)
	{	
		mlx_put_image_to_window(data.mlx, data.win, img.muro, 0, i);
		mlx_put_image_to_window(data.mlx, data.win,img.muro, data.height - 64, i);
		i = i + 64;
	}
	show_info(data);
}

void	make_obj(t_data data, t_img img)
{
	int	i;

	i = (data.height + 64);
	while (i < (data.height + 64) * (data.width - 64) / 64)
	{
		if (data.map[i / 64] == '1' && (i % (data.height + 64)) != 0
			&& (i % (data.height + 64)) != (data.height - 64))
			mlx_put_image_to_window(data.mlx, data.win, img.objeto,
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
		if (data.map[i / 64] == 'P')
			mlx_put_image_to_window(data.mlx, data.win, img.slime[0],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
		if (data.map[i / 64] == 'A')
			mlx_put_image_to_window(data.mlx, data.win, img.slime[1],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
		if (data.map[i / 64] == 'C')
			mlx_put_image_to_window(data.mlx, data.win, img.moneda,
				i % (data.height + 64) + 8, (i / (data.height + 64) * 64) + 16);
		if (data.map[i / 64] == 'E')
			mlx_put_image_to_window(data.mlx, data.win, img.salida[0],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
		i = i + 64;
	}
}

void	make_enemy(t_data data, t_img img, int a)
{
	int	i;

	i = (data.height + 64);
	while (i < (data.height + 64) * (data.width - 64) / 64)
	{
		if (data.map[i / 64] == 'W')
		{
			mlx_put_image_to_window(data.mlx, data.win, img.enemigo[0],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
			if (a)
				data.map[i / 64] = 'w';
		}
		else if (data.map[i / 64] == 'w')
		{
			mlx_put_image_to_window(data.mlx, data.win, img.enemigo[1],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
			if (a)
				data.map[i / 64] = 'W';
		}
		i = i + 64;
	}
}

void	show_info(t_data data)
{
	mlx_string_put(data.mlx, data.win, 80, 30, 0x00000000, "MOVES");
	mlx_string_put(data.mlx, data.win, 90, 50, 0x00000000, ft_itoa(data.move));
}

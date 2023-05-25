/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:28:03 by jumoncad          #+#    #+#             */
/*   Updated: 2023/05/25 13:13:07 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	collition(t_data *data, t_img *img, int next, int c)
{
	int	width;
	int	height;

	if (are_there_door(*data, img))
		return (0);
	if (fail(*data, img, next))
		return (0);
	if (data->map[next] == '1')
		return (0);
	if (data->map[next] == 'E' && !are_there_coins(data, img))
	{
		img->slime[0] = mlx_xpm_file_to_image(data->mlx,
				"image/slime1.xpm", &width, &height);
		img->slime[1] = mlx_xpm_file_to_image(data->mlx,
				"image/slime2.xpm", &width, &height);
		return (0);
	}
	data->map[next] = c;
	if (c != 'V')
		data->move++;
	return (1);
}

int	moves(int keycode, t_data *data)
{
	int		pos;

	pos = 0;
	while (data->map[pos] != 'P' && data->map[pos] != 'A')
		pos++;
	if (keycode == D && collition(data, &data->img, pos + 1, 'P'))
		data->map[pos] = '0';
	if (keycode == A && collition(data, &data->img, pos - 1, 'A'))
		data->map[pos] = '0';
	if (keycode == S && collition(data, &data->img, pos + data->line, 'P'))
		data->map[pos] = '0';
	if (keycode == W && collition(data, &data->img, pos - data->line, 'A'))
		data->map[pos] = '0';
	if (keycode == D || keycode == A || keycode == S || keycode == W)
		enemy_move(data, 0, 0);
	are_there_coins(data, &data->img);
	if (are_there_door(*data, &data->img))
		return (0);
	if (fail(*data, &data->img, 0))
		return (0);
	make_ground(*data, data->img);
	make_obj(*data, data->img);
	make_corner(*data, data->img);
	make_enemy(*data, data->img, 0);
	return (0);
}

void	enemy_move(t_data *data, int pos, int enemies)
{
	while (data->map[pos++])
	{
		if (data->map[pos] == 'W' || data->map[pos] == 'w')
			enemies++;
	}
	pos = 0;
	while (enemies-- != 0)
	{
		while (data->map[pos] != 'W' && data->map[pos] != 'w')
			pos++;
		if (data->map[pos + 1] == '0')
			collition(data, &data->img, pos + 1, 'V');
		else if (data->map[pos + data->line] == '0')
			collition(data, &data->img, pos + data->line, 'V');
		else if (data->map[pos - data->line] == '0')
			collition(data, &data->img, pos - data->line, 'V');
		else if (data->map[pos - 1] == '0')
			collition(data, &data->img, pos - 1, 'V');
		data->map[pos] = '0';
	}
	strchng(data->map, 'V', 'W');
}

void	strchng(char *str, int a, int b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			str[i] = b;
		i++;
	}
}

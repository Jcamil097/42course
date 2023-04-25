/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:28:03 by jumoncad          #+#    #+#             */
/*   Updated: 2023/04/25 15:19:32 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int collition(t_data *data, t_img *img, int next, int c)
{
	int width;
	int height;

	if (data->map[next] == '1')
		return (0);
	if (data->map[next] == 'E')
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

char letter_press(int keycode)
{
	char letter;
	int i;
	
	t_key g_key[] = {
		{0, 'a'},
		{13, 'w'},
		{1, 's'},
		{2, 'd'},
		{0, 0}};
	i = 0;
	letter = 0;
	while (g_key[i].letter != 0)
	{
		if (keycode == g_key[i].code)
		{
			letter = g_key[i].letter;
			break;
		}
		i++;
	}
	return (letter);
}

int moves(int keycode, t_data *data)
{
	int pos;
	char letter;
	
	pos = 0;
	while (data->map[pos] != 'P' && data->map[pos] != 'A')
		pos++;
	letter = letter_press(keycode);
	if (letter == 'd' && collition(data, &data->img, pos + 1, 'P'))
		data->map[pos] = '0';
	if (letter == 'a' && collition(data, &data->img, pos - 1, 'A'))
		data->map[pos] = '0';
	if (letter == 's' && collition(data, &data->img, pos + data->line, 'P'))
		data->map[pos] = '0';
	if (letter == 'w' && collition(data, &data->img, pos - data->line, 'A'))
		data->map[pos] = '0';
	if (letter == 'd' || letter == 'a' || letter == 's' || letter == 'w')
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

void enemy_move(t_data *data, int pos, int enemies)
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

void strchng(char *str, int a, int b)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			str[i] = b;
		i++;
	}
}
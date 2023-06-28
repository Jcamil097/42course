/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:35:32 by jumoncad          #+#    #+#             */
/*   Updated: 2023/06/28 16:37:51 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	search_position_y(t_game game, char searchcharacter)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (row < game.row_map)
	{
		while (column < game.col_map)
		{
			if (game.mapcopy[row][column] == searchcharacter)
				return (row);
			column++;
		}
		column = 0;
		row++;
	}
	return (-1);
}

int	search_position_x(t_game game, char searchcharacter)
{
	int	pos_x;
	int	found;
	int	row;
	int	column;

	pos_x = 0;
	found = 0;
	row = 0;
	column = 0;
	while (!found && row < game.row_map)
	{
		if (game.mapcopy[row][column] == searchcharacter)
		{
			pos_x = column;
			found = 1;
		}
		column++;
		if (column >= game.col_map)
		{
			row++;
			column = 0;
		}
	}
	return (pos_x);
}

int	count_rows(char **map)
{
	int	row;

	row = 0;
	while (map[row] != NULL)
		row++;
	return (row);
}

int	count_columns(char **map)
{
	int	column;

	column = 0;
	if (map[0] != NULL)
	{
		while (map[0][column] != '\0')
			column++;
	}
	return (column);
}

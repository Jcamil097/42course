/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:51:58 by igvaz-fe          #+#    #+#             */
/*   Updated: 2023/06/14 17:46:45 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_retangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_walls(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_pec(t_game *game)
{
	int	i;
	int	j;

	game->n_colect = 0;
	game->n_player = 0;
	game->n_exit = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				game->n_player++;
			else if (game->map[i][j] == 'E')
				game->n_exit++;
			else if (game->map[i][j] == 'C')
				game->n_colect++;
			j++;
		}
		i++;
	}
	if (game->n_player != 1 || game->n_exit == 0 || game->n_colect == 0)
		return (0);
	return (1);
}

static int	valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'K')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_checker(t_game *game)
{
	if (is_retangular(game->map) && is_walls(game->map) && is_pec(game)
		&& valid_characters(game->map))
		return (1);
	return (0);
}

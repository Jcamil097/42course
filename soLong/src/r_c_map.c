/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_c_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:22:37 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	tombstone_draw(t_game *game)
{
	int	w;

	mlx_destroy_image(game->mlx, game->img_player);
	mlx_clear_window(game->mlx, game->win);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/textures/T.xpm", &game->img_w, &game->img_h);
	game->endgame = 1;
	w = game->map_w / 2;
	mlx_string_put(game->mlx, game->win, w, 20, 0xFFFFFF, "GAME OVER");
	mlx_string_put(game->mlx, game->win,
		w - 10, 40, 0xFFFFFF, "PRESS ESC OR Q");
	map_draw(game);
}

int	map_size(int map_size, char **map)
{
	map_size = 0;
	while (map[map_size] != NULL)
		map_size++;
	return (map_size);
}

char	**copy_map(char **map)
{
	t_map	s_map;

	s_map.map_size = map_size(s_map.map_size, map);
	s_map.map_copy = (char **)malloc((s_map.map_size + 1) * sizeof(char *));
	if (s_map.map_copy == NULL)
		return (NULL);
	s_map.i = 0;
	while (s_map.i < s_map.map_size)
	{
		s_map.map_copy[s_map.i] = ft_strdup(map[s_map.i]);
		if (s_map.map_copy[s_map.i] == NULL)
		{
			s_map.j = 0;
			while (s_map.j < s_map.i)
			{
				free(s_map.map_copy[s_map.j]);
				s_map.j++;
			}
			free(s_map.map_copy);
			return (NULL);
		}
		s_map.i++;
	}
	s_map.map_copy[s_map.map_size] = NULL;
	return (s_map.map_copy);
}

char	**read_map(char *path)
{
	t_map	map;

	map.fd = open(path, O_RDONLY);
	if (map.fd == -1)
	{
		ft_putstr_fd("Error: Map not found\n", 2);
		exit(0);
	}
	map.holder_map = ft_strdup("");
	while (1)
	{
		map.line = get_next_line(map.fd);
		if (!map.line)
			break ;
		map.holder = map.holder_map;
		map.holder_map = ft_strjoin(map.holder, map.line);
		free(map.line);
		free(map.holder);
	}
	map.map = ft_split(map.holder_map, '\n');
	free(map.holder_map);
	close(map.fd);
	return (map.map);
}

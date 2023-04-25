/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:26:24 by jumoncad          #+#    #+#             */
/*   Updated: 2023/04/24 12:45:42 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	save_img(t_data data)
{
	t_img	img;
	int		width;
	int		height;

	img.cesped = mlx_xpm_file_to_image(data.mlx, "image/cesped.xpm", &width, &height);
	img.moneda = mlx_xpm_file_to_image(data.mlx, "image/moneda.xpm", &width, &height);
	img.muro = mlx_xpm_file_to_image(data.mlx,  "image/muro.xpm", &width, &height);
	img.objeto = mlx_xpm_file_to_image(data.mlx, "image/objeto.xpm", &width, &height);
	img.slime[0] = mlx_xpm_file_to_image(data.mlx, "image/slime1.xpm", &width, &height);
	img.slime[1] = mlx_xpm_file_to_image(data.mlx, "image/slime2.xpm", &width, &height);
	img.salida[0] = mlx_xpm_file_to_image(data.mlx, "image/salida.xpm", &width, &height);
	img.salida[1] = mlx_xpm_file_to_image(data.mlx, "image/salida2.xpm", &width, &height);
	img.enemigo[0] = mlx_xpm_file_to_image(data.mlx, "image/enemigo.xpm", &width, &height);
	img.enemigo[1] = mlx_xpm_file_to_image(data.mlx, "image/enemigo2.xpm", &width, &height);
	
	if (!img.cesped || !img.moneda || !img.muro || !img.objeto || !img.slime[0] || !img.slime[1]
		|| !img.salida[0] || !img.salida[1] || !img.enemigo[0] || !img.enemigo[1])
	{
		ft_putstr_fd("Error sprites corruptos save_img \n", 0);
		exit(0);
	}
	return (img);
}

int	ft_strnstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (needle[0] == '\0')
		return (0);
	while (((char *)haystack)[i])
	{
		j = 0;
		while (((char *)haystack)[i + j] == ((char *)needle)[j]
		&& ((char *)haystack)[i + j])
		{
			if (!((char *)needle)[j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_data	save_map(t_data data, char *map)
{
	int	fd;
	int	len;

	data.line = 0;
	data.map = malloc(sizeof(char) * 1000);
	fd = open(map, O_RDONLY);
	len = read(fd, data.map, 10000);
	if (fd < 0 || !ft_strnstr(map, ".ber") || len < 15)
	{
		ft_putstr_fd("Error mapa: No se puede abrir\n", 0);
		exit(0);
	}
	free(data.map);
	close(fd);
	data.map = malloc(sizeof(char) * len + 1);
	fd = open(map, O_RDONLY);
	read(fd, data.map, len);
	data.map[len] = '\0';
	while (data.map[data.line] && data.map[data.line] != '\n')
		data.line++;
	data.width = (len / data.line) * 64;
	data.height = data.line * 64;
	data.line++;
	data.move = 0;
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:19:42 by jumoncad          #+#    #+#             */
/*   Updated: 2023/04/25 15:26:26 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "unistd.h"
# include "fcntl.h"
# include "stdlib.h"
# include "stdio.h"
# include "mlx.h"

typedef struct s_img
{
	void	*cesped;
	void	*moneda;
	void	*muro;
	void	*objeto;
	void	*slime[2];
	void	*enemigo[2];
	void	*salida[2];
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*map;
	int		line;
	int		move;
	t_img	img;
}				t_data;

typedef struct s_key
{
	int	code;
	char letter;	
} 				t_key;

/* * check map* */
char	*next_step(char *test_map, int pos, int lar);
void	find_exit(t_data data);
void	is_rectangle(t_data data);
void	error_mapa_char(t_data data, int countp, int counte);
void	is_map_close(t_data data);
/* *ft_itoa* */
char	*ft_itoa(int n);

/* *map_hook* */
int	are_there_coins(t_data *data, t_img *img);
int	are_there_door(t_data data, t_img *img);
int	fail(t_data data, t_img *img, int next);

/* *move* */
int		collition(t_data *data, t_img *img, int next, int c);
int		moves(int keycode, t_data *data);
void	enemy_move(t_data *data, int pos, int enemies);

/* *render_img* */
void	make_ground(t_data data, t_img img);
void	make_corner(t_data data, t_img img);
void	make_obj(t_data data, t_img img);
void	make_enemy(t_data data, t_img img, int a);
void	show_info(t_data data);

/* *save_map* */
t_img	save_img(t_data data);
int	ft_strnstr(const char *haystack, const char *needle);
t_data	save_map(t_data data, char *map);

/* *libft* */
char	*ft_strjoin(char const *s1, char s2, char const *s3);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	strchng(char *str, int a, int b);
void	ft_putstr_fd(char *s, int fd);

/* *so_long* */
int	ft_strcmp(char *s1, char *s2);
int	destroy(t_data *data);
int	key_destroy(int keycode, t_data *data);

#endif
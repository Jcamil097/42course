/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:19:42 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libraries/mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# define W  13
# define A 	0
# define S  1
# define D  2
# define Q  12
# define ESC 53
# define UP  126
# define DOWN 125
# define LEFT  123
# define RIGHT  124

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**mapcopy;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	void	*img_enemie;
	void	*img_final;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		x_enemy;
	int		y_enemy;
	int		moves;
	int		endgame;
	int		pos_enemies;
	int		pos_colect;
	int		loop;
	int		loop2;
	int		x;
	int		y;
	int		p_x_player;
	int		p_y_player;
	int		row_map;
	int		col_map;
	int		map_playable;
	int		count;
}	t_game;

typedef struct s_map
{
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;
	char	**map_copy;
	int		fd;
	int		map_size;
	int		i;
	int		j;
}	t_map;

/***********animation***********/
int		animation(t_game *game);
int		animation_colect(t_game *game);

/***********draw***********/
void	img_draw(t_game *game, void *image, int x, int y);
void	tombstone_draw(t_game *game);
int		map_draw(t_game *game);

/***********ft_itoa***********/
char	*ft_itoa(int n);

/***********ft_split***********/
char	**ft_split(char const *s, char c);

/***********gameplay***********/
void	free_map(char **map);
void	gameplay(t_game *game);
int		exit_game(t_game *game);

/***********get_next_line***********/
char	*get_next_line(int fd);

/***********init***********/
void	game_init(t_game *game);
void	init(t_game game);

/***********libft_str***********/
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		ft_strnstr(const char *haystack, const char *needle);

/***********map_validate***********/
int		map_checker(t_game *game);

/***********moves***********/
void	display_moves(t_game *game);
void	ft_putstr_fd(char *s, int fd);
void	print_winner(t_game *game);

/***********player_update***********/
void	player_w(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);

/***********so_long***********/
char	**read_map(char *path);

/***********r_c_map***********/
char	**read_map(char *path);
char	**copy_map(char **map);

/***********position_player***********/
int		search_position_x(t_game game, char caracterBuscado);
int		search_position_y(t_game game, char caracterBuscado);
int		count_rows(char **map);
int		count_columns(char **map);

#endif
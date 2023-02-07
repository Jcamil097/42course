/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:46:42 by jumoncad          #+#    #+#             */
/*   Updated: 2023/01/25 12:50:51 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
int		ft_isalpha(int c);
int		ft_tolower(int c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strcat(char *s1, const char *s2);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:32:56 by jumoncad          #+#    #+#             */
/*   Updated: 2024/01/23 12:38:44 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (s[cont] != '\0')
		cont++;
	return (cont);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*sr;
	char		*dt;
	size_t		x;

	dt = dst;
	sr = src;
	x = 0;
	if (!dst && !src)
		return (NULL);
	while (x < n)
	{
		dt[x] = sr[x];
		x++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	x;

	x = ft_strlen(s1);
	str = (char *)malloc(sizeof(*s1) * (x + 1));
	if (str)
		ft_memcpy(str, s1, x + 1);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			cont;
	unsigned int	x;

	x = 0;
	cont = ft_strlen(src);
	if (!size)
		return (cont);
	while (src[x] != '\0' && x < size - 1)
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (cont);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*src;
	size_t	len_src;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	src = (char *)s + start;
	len_src = ft_strlen(src);
	if (len_src < len)
		len = ++len_src;
	else
		len++;
	str = malloc(sizeof(char) * len);
	if (str)
		ft_strlcpy(str, src, len);
	return (str);
}

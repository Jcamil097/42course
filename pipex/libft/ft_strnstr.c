/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:44:43 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:38:46 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;
	size_t	nd_l;
	char	*h;
	char	*n;

	x = 0;
	h = (char *)haystack;
	n = (char *)needle;
	nd_l = ft_strlen(n);
	if (h == n || nd_l == 0)
		return (h);
	while (h[x] && x < len)
	{
		y = 0;
		while (h[x + y] && n[y] && h[x + y] == n[y] && x + y < len)
			y++;
		if (y == nd_l)
			return (h + x);
		x++;
	}
	return (NULL);
}

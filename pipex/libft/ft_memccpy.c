/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:36:40 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t l)
{
	size_t			x;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	sym;

	x = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	sym = (unsigned char)c;
	while (x < l)
	{
		d[x] = s[x];
		if (s[x] == sym)
			return (d + x + 1);
		x++;
	}
	return (0);
}

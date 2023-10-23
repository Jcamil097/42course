/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:21:16 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/08 10:41:03 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	const char		*str;

	x = 0;
	str = s;
	while (x < n)
	{
		if (str[x] == (char)c)
		{
			return ((char *)(str + x));
		}
		x++;
	}
	return (NULL);
}

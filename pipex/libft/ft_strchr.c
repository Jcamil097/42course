/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:41:24 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:37:21 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;
	char	sb;

	x = 0;
	sb = (char)c;
	while (s[x])
	{
		if (s[x] == sb)
			return ((char *)s + x);
		x++;
	}
	if (s[x] == sb)
		return ((char *)s + x);
	return (NULL);
}

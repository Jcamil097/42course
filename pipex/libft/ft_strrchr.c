/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:44:51 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:38:51 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	sb;

	x = 0;
	sb = (char)c;
	while (s[x])
		x++;
	while (x >= 0)
	{
		if (s[x] == sb)
			return ((char *)s + x);
		x--;
	}
	return (NULL);
}

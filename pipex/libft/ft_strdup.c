/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:42:21 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:37:53 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	l;
	size_t	x;

	x = 0;
	l = ft_strlen(s1);
	str = (void *)malloc(sizeof(*str) * (l + 1));
	if (!str)
		return (NULL);
	while (x < l)
	{
		*(str + x) = *(s1 + x);
		x++;
	}
	str[x] = '\0';
	return (str);
}

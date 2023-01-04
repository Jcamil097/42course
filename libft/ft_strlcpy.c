/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:20:39 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/08 10:44:10 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

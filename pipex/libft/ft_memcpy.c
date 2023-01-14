/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:32:58 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/08 10:41:34 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

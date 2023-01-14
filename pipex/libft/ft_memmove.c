/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:58:50 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/08 10:41:45 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*sr;
	int			x;
	char		*dt;

	dt = dst;
	sr = src;
	if (dst > src)
	{
		x = (int)len - 1;
		while (x >= 0 && !(!dst && !src))
		{
			dt[x] = sr[x];
			x--;
		}
	}
	else
	{
		x = 0;
		while (x < (int)len && !(!dst && !src))
		{
			dt[x] = sr[x];
			x++;
		}
	}
	return (dst);
}

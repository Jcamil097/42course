/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:45:01 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/08 10:41:20 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				x;
	unsigned const char	*src1;
	unsigned const char	*src2;

	x = 0;
	src1 = s1;
	src2 = s2;
	while (x < n)
	{
		if (src1[x] != src2[x])
			return (src1[x] - src2[x]);
		x++;
	}
	return (0);
}

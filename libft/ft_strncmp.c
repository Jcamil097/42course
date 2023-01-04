/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:11:45 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/08 10:51:23 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	x;

	x = 0;
	while (x < n)
	{
		if (s1[x] != s2[x] || !s1[x] || !s2[x])
			return ((unsigned const char)s1[x] - (unsigned const char)s2[x]);
		x++;
	}
	return (0);
}

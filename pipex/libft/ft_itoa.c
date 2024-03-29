/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:31:53 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(long qs)
{
	int	x;

	x = 0;
	if (qs <= 0)
		x++;
	while (qs != 0)
	{
		qs /= 10;
		x++;
	}
	return (x);
}

static char	*ft_converter(char *str, long tmp, int l)
{
	if (tmp == 0)
		str[0] = '0';
	str[l] = '\0';
	if (tmp < 0)
	{
		str[0] = '-';
		tmp = -tmp;
	}
	while (tmp)
	{
		--l;
		str[l] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		l;
	long	tmp;

	tmp = n;
	l = ft_nlen(tmp);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	return (str = ft_converter(str, tmp, l));
}

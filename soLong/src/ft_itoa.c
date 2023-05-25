/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:16:29 by ubegona           #+#    #+#             */
/*   Updated: 2023/05/25 13:12:59 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	numlen(int num)
{
	int	x;

	x = 0;
	if (num <= 0)
		x++;
	while (num != 0)
	{
		num = num / 10;
		x++;
	}
	return (x);
}

int	cal_sign(int x, char *str)
{
	if (x == -2147483648)
		x++;
	if (x < 0)
	{
		str[0] = '-';
		x = x * -1;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	int		x;
	int		len;
	char	*str;

	x = n;
	len = numlen(x);
	str = malloc(sizeof(char) *(len + 1));
	if (str == 0)
		return (NULL);
	x = cal_sign(n, str);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (x != 0)
	{
		str[len - 1] = x % 10 + 48;
		x = x / 10;
		len--;
	}
	if (n == -2147483648)
		str[10] = '8';
	return (str);
}

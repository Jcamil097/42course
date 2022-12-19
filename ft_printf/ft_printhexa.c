/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:48:16 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/17 12:21:51 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printhexa(unsigned int x, const char *str)
{
	char	*hexa;
	int		res[100];
	int		i;

	if (*str == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	i = 0;
	while (x >= 16)
	{
		res[i] = hexa[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa[x];
	while (i >= 0)
	{
		ft_putchar_fd(res[i], 1);
		i--;
	}
}

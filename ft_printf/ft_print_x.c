/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:12:11 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/20 10:05:40 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned int x, const char *str)
{
	char	*hexa;
	int		res[100];
	int		i;
	int		cont;

	cont = 1;
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
	cont += i;
	res[i] = hexa[x];
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
	}
	return (cont);
}

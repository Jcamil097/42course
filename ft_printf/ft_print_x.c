/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:46:49 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
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

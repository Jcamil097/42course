/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:23:55 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/20 11:37:10 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putnbr_ptr(size_t num)
{
	if (num >= 16)
	{
		ft_putnbr_ptr(num / 16);
		ft_putnbr_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

int	ft_print_p(unsigned long int p)
{
	int	num;

	num = 0;
	num += write(1, "0x", 2);
	if (p == 0)
		num += write(1, "0", 1);
	else
	{
		ft_putnbr_ptr(p);
		num += ft_ptr_len(p);
	}
	return (num);
}

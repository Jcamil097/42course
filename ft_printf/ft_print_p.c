/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:47:58 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/17 12:23:47 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

void	ft_putnbr_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putnbr_ptr(num / 16);
		ft_putnbr_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
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

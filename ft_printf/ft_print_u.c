/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:46:44 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/23 16:46:47 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len_u(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len_u(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (len--)
	{
		num[len] = n % 10 + 48;
		n /= 10;
	}
	return (num);
}

int	ft_putnbr_u(unsigned int n)
{
	int		len;
	char	*num;
	int		cont;

	len = 0;
	cont = ft_num_len_u(n);
	if (n == 0)
	{
		len += write(1, "0", 1);
		cont = 1;
	}
	else
	{
		num = ft_uitoa(n);
		ft_putstr(num);
		free(num);
	}
	return (cont);
}

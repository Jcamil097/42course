/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:46:53 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/23 16:46:55 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	ft_search_type(va_list arg, const char *str)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len += ft_putchar((char)va_arg(arg, char *));
	else if (*str == 'd' || *str == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (*str == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (*str == 'u')
		len += ft_putnbr_u((unsigned long)va_arg(arg, unsigned int));
	else if (*str == 'x' || *str == 'X')
		len = ft_printhexa((unsigned long)va_arg(arg, unsigned long), str);
	else if (*str == 'p')
		len = ft_print_p(va_arg(arg, unsigned long long));
	else if (*str == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		cont;

	cont = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			cont += ft_search_type(arg, str + 1);
			str++;
		}
		else
			cont += ft_putchar(*str);
		str++;
	}
	va_end(arg);
	return (cont);
}

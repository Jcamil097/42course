/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:57:20 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 15:33:41 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	numlen(long num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num >= 1)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*new_str(char *str, long nb, unsigned int len)
{	
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
		nb *= -1;
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*str;

	len = numlen(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (str)
		str = new_str(str, n, len);
	return (str);
}
/* #include <stdio.h>
int main()
{
	char *str;

	str = ft_itoa(-2147483648LL);
	printf("%s", str);
	free(str);
	return 0;
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:33:30 by jumoncad          #+#    #+#             */
/*   Updated: 2022/11/29 18:50:22 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (ft_isascii(c))
	{
		if ((c >= 33 && c <= 126) || (c == 32))
		{
			return (1);
		}
	}
	return (0);
}
/* #include <stdio.h>
int main()
{
	printf("%d", ft_isprint('\n'));
	return 0;
} */
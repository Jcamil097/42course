/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:05:31 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/01 16:30:24 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	x;
	char *st;

	st = s;
	if (!s)
		return ;
	x = 0;
	while (x < n)
	{
		st[x] = 0;
		x++;
	}
}
/* #include <string.h>
int main()
{
	//probar con debug
	char buffer[80];

	buffer[1] = 's';
    bzero( buffer, 80);

	char buffer2[80];

	buffer2[1] = 's';
    ft_bzero( buffer2, 80);
	return 0;
} */
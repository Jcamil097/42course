/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:38:11 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 12:45:02 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*st;
	size_t	x;

	x = 0;
	st = str;
	while (x < n)
	{
		st[x] = c;
		x++;
	}
	return (st);
}
/* #include <stdio.h>

int main () {
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   memset(str,'$',3);
   puts(str);

   char str2[50];

   strcpy(str2,"This is string.h library function");
   puts(str2);

   ft_memset(str2,'$',3);
   puts(str2);
   
   return(0);
} */

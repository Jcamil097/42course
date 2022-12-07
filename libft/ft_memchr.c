/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:21:16 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 12:32:14 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	const char		*str;

	x = 0;
	str = s;
	while (x < n)
	{
		if (str[x] == (char)c)
		{
			return ((char *)(str + x));
		}
		x++;
	}
	return (NULL);
}
/* #include <stdio.h>

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);

   printf("%s","\n");

   const char str2[] = "http://www.tutorialspoint.com";
   const char ch2 = '.';
   char *ret2;

   ret2 = ft_memchr(str2, ch2, strlen(str2));

   printf("String after |%c| is - |%s|\n", ch2, ret2);

   return(0);
} */

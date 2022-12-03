/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:58:50 by jumoncad          #+#    #+#             */
/*   Updated: 2022/11/30 11:39:37 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	x;
	char *dt;
	const char *sr;

	dt = dst;
	sr = src;
	if (dst > src)
	{
		x = (int)len - 1;
		while (x >= 0)
		{
			dt[x] = sr[x];
			x--;
		}
	}
	else
	{
		x = 0;
		while (x < (int)len)
		{
			dt[x] = sr[x];
			x++;
		}
	}
	return (dst);
}
/* #include <stdio.h>
#include <string.h>

int main () {
   char dest[] = "oldstring";
   const char src[]  = "newstring";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   memmove(dest, src, 9);
   printf("After memmove dest = %s, src = %s\n", dest, src);
   
   printf("%s","\n");
   char dest2[] = "oldstring";
   const char src2[]  = "newstring";

   printf("Before memmove dest2 = %s, src2 = %s\n", dest2, src2);
   ft_memmove(dest2, src2, 9);
   printf("After memmove dest2 = %s, src2 = %s\n", dest2, src2);

   return(0);
} */
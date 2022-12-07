/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:58:50 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 12:43:38 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*sr;
	int			x;
	char		*dt;

	dt = dst;
	sr = src;
	if (dst > src)
	{
		x = (int)len - 1;
		while (x >= 0 && !(!dst && !src))
		{
			dt[x] = sr[x];
			x--;
		}
	}
	else
	{
		x = 0;
		while (x < (int)len && !(!dst && !src))
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

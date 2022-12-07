/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:45:01 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 12:37:56 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				x;
	unsigned const char	*src1;
	unsigned const char	*src2;

	x = 0;
	src1 = s1;
	src2 = s2;
	while (x < n)
	{
		if (src1[x] != src2[x])
			return (src1[x] - src2[x]);
		x++;
	}
	return (0);
}
/* #include <stdio.h>
int main () {
   char st1[15];
   char st2[15];
   int ret2;

   memcpy(st1, "t\200", 6);
   memcpy(st2, "t\0", 6);

   ret2 = ft_memcmp("t\200", "t\0", 2);

   if(ret2 > 0) {
      printf("st2 is less than st1 %d", ret2);
   } else if(ret2 < 0) {
      printf("st1 is less than st2 %d", ret2);
   } else {
      printf("st1 is equal to st2 %d", ret2);
   }
   
   return(0);
} */

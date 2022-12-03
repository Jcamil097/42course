/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:11:45 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/03 10:08:18 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	x;

	x = 0;
	while (x < n)
	{
		if (s1[x] != s2[x] || !s1[x] || !s2[x])
			return ((unsigned const char)s1[x] - (unsigned const char)s2[x]);
		x++;
	}
	return (0);
}
/* #include <stdio.h>

int main () {
   char st1[15];
   char st2[15];
   int ret2;

   strcpy(st1, "test\200");
   strcpy(st2, "test\0");

   ret2 = ft_strncmp(st1, st2, 6);

   if(ret2 < 0) {
      printf("str1 is less than str2 %d", ret2);
   } else if(ret2 > 0) {
      printf("str2 is less than str1 %d", ret2);
   } else {
      printf("str1 is equal to str2 %d", ret2);
   }
   
   return(0);
} */
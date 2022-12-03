/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:32:58 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/02 16:01:47 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;
	char *dt;
	const char *sr;

	dt = dst;
	sr = src;
	x = 0;
	while (x < n)
	{
		dt[x] = sr[x];
		x++;
	}
	return (dst);
}
 /* #include <stdio.h>
#include <string.h>
int main () {
  const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest); 
   
   printf("%s","\n");
   const char src2[50] = "http://www.tutorialspoint.com";
   char dest2[50];
   strcpy(dest2,"Heloooo!!");
   printf("Before memcpy dest2 = %s\n", dest2);
   ft_memcpy(dest2, src2, strlen(src2)+1);
   printf("After memcpy dest2 = %s\n", dest2);
   return(0);
}*/
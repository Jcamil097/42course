/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:00:09 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 14:50:57 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	x;

	x = ft_strlen(str) + 1;
	while (x--)
	{
		if (str[x] == (char)c)
			return ((char *)(str + x));
	}
	return (NULL);
}
/* #include <stdio.h>

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);

   printf("%s","\n");
   const char str2[] = "http://www.tutorialspoint.com";
   const char ch2 = '.';
   char *ret2;

   ret2 = ft_strrchr(str2, ch2);

   printf("String after |%c| is - |%s|\n", ch2, ret2);
   
   return(0);
} */

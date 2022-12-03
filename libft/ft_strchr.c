/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:32:43 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/02 17:12:18 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{

	while (*str)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	return (0);
}
/* #include <stdio.h>

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '\0';
   char *ret;

   ret = strchr(str, ch);
   printf("String after |%c| is - |%s|\n", ch, ret);
   printf("\n");
   const char str2[] = "http://www.tutorialspoint.com";
   const char ch2 = '\0';
   char *ret2;

   ret2 = ft_strchr(str2, ch2);
   printf("String after |%c| is - |%s|\n", ch2, ret2);
   return(0);
} */
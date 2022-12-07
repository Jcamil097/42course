/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:25:36 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 12:52:09 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	x;

	x = ft_strlen(s1);
	str = (char *) malloc(sizeof(*s1) * (x + 1));
	if (str)
		ft_memcpy(str, s1, x + 1);
	return (str);
}
/* #include <stdio.h>
#include <stdlib.h>
int main() {
   char *str = "Helloworld";
   char *result;
   result = strdup(str);
   printf("The string : %s", result);

   printf("%s","\n");
   char *str2 = "Helloworld";
   char *result2;
   result2 = strdup(str2);
   printf("The string : %s", result2);
   return 0;
} */

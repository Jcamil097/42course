/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:25:36 by jumoncad          #+#    #+#             */
/*   Updated: 2022/11/30 14:09:38 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
    char *str;
    size_t x;

    if (!s1)
    {
        return (NULL);
    }
    str = (char*)malloc(sizeof(*s1)*(ft_strlen(s1) + 1));
    if (!str)
    {
        return (NULL);
    }
    x = 0;
    while (s1[x])
    {
        str[x] = s1[x];
        x++;
    }
    str[x] = 0;
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
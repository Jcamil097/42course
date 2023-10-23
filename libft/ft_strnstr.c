/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:19:11 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 15:55:18 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		x = 0;
		while (haystack[x] == needle[x])
		{
			if (!needle[++x])
				return ((char *)haystack);
			if (x > len)
				return (0);
		}
		haystack++;
	}
	return (0);
}
/* #include <stdio.h>

int main()
{
    char *haystack = "Very secret Hidden text";
    char *needle = "hidden";
    char *location;

    location = strstr(haystack,needle);
    if(location == NULL)
        puts("Unable to find string with strstr().");
    else
        printf("strstr() found '%s' in '%s'.\n",needle,haystack);

    location = strcasestr(haystack,needle);
    if(location == NULL)
        puts("Can't find the string with strcasestr() either!");
    else
        printf("strcasestr() found '%s' in '%s'.\n",needle,haystack);

	printf("%s","\n");
	char *haystack2 = "Very secret Hidden text";
    char *needle2 = "hidden";
    char *location2;

    location2 = strstr(haystack2,needle2);
    if(location2 == NULL)
        puts("Unable to find string with strstr().");
    else
        printf("strstr() found '%s' in '%s'.\n",needle2,haystack2);

    location2 = strcasestr(haystack2,needle2);
    if(location2 == NULL)
        puts("Can't find the string with strcasestr() either!");
    else
        printf("strcasestr() found '%s' in '%s'.\n",needle2,haystack2);

    return(0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:19:11 by jumoncad          #+#    #+#             */
/*   Updated: 2022/11/30 12:58:24 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (!haystack || !needle)
		return (NULL);
	if (!needle || !needle[0])
		return ((char *)haystack);
	while (!haystack[x] && x < len)
	{
		y = 0;
		while (haystack[x + y] && needle[y]
			&& x + y < len && haystack[x + y] == needle[y])
		{
			y++;
		}
		if (!needle[y])
		{
			return ((char *)(haystack + x));
		}
		x++;
	}
	return (NULL);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:24:48 by jumoncad          #+#    #+#             */
/*   Updated: 2022/11/30 12:05:49 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstleng;
	size_t	srcleng;

	srcleng = ft_strlen(src);
	dstleng = ft_strlen(dst);
	j = dstleng;
	i = 0;
	if (dstleng < size - 1 && size > 0)
	{
		while (src[i] && dstleng + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dstleng >= size)
		dstleng = size;
	return (dstleng + srcleng);
}
/* #include <stdio.h>
#include <string.h>
int main()
{
	char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
    int size = 16;
    char buffer[size];

    strcpy(buffer,first);
    r = strlcat(buffer,last,size);

    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");

	printf("%s","\n");
	char first2[] = "This is ";
    char last2[] = "a potentially long string";
    int r2;
    int size2 = 16;
    char buffer2[size2];

    strcpy(buffer2,first2);
    r2 = ft_strlcat(buffer2,last2,size2);

    puts(buffer2);
    printf("Value returned: %d\n",r2);
    if( r2 > size2 )
        puts("String truncated");
    else
        puts("String was fully copied");	
	return 0;
} */
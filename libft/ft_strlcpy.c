/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:20:39 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 12:56:26 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			cont;
	unsigned int	x;

	x = 0;
	cont = ft_strlen(src);
	if (!size)
		return (cont);
	while (src[x] != '\0' && x < size - 1)
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (cont);
}
/* #include <stdio.h>
int main()
{
	char string[] = "lorem ipsum dolor sit amet";
	char buffer[15];
	int r;

	r = strlcpy(buffer, string, 15);

	printf("Copied '%s' into '%s', length %d\n", string, buffer, r);

	char string2[] = "lorem ipsum dolor sit amet";
	char buffer2[15];
	int r2;

	r2 = ft_strlcpy(buffer2, string2, 15);

	printf("Copied '%s' into '%s', length %d\n", string2, buffer2, r2);
	return 0;
} */

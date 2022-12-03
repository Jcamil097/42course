/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:42:35 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/02 13:22:07 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char    *srccpy;
    int x;

    x = 0;
	srccpy = dest;
	while (n > 0 && src[x] != '\0')
	{
		dest[x] = src[x];
        x++;
        n--;
	}
	while (n > 0 && *dest != '\0')
	{
		dest[x] = '\0';
		x++;
        n--;
	}
	return (srccpy);
}

char    *ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}

char    **ft_split(char const *s, char c)
{
	char	**tab;
	int		x;
	size_t	lenstr;
    
    x = 0;
	if (!s)
		return (NULL);
	while (*s == c)
		++s;
    if (!(tab = (char**)malloc((ft_strlen(s) + ft_strlen(&c)) * sizeof(char*))))
		return (NULL);
	while (*s != '\0')
	{
		lenstr = 0;
		while (*s != c && *s != '\0' && ++s)
			++lenstr;
		if (!(tab[x] = (char *)malloc(sizeof(char) * (lenstr + 1))))
			return (NULL);
		ft_strncpy(tab[x++], s - lenstr, lenstr);
		while (*s == c)
			++s;
	}
	tab[x] = 0;
	return (tab);
}
/* #include <stdio.h>
int main()
{
    char str[] = "Esta, cadena, esta formada, por varias, palabras";
    char **stnew;
    int x;

    x = 0;
    stnew = ft_split(str, ',');
    while (stnew[x])
    {
        printf("%s\n",stnew[x]);
        x++;
    }
    free(stnew);
    return 0;
} */
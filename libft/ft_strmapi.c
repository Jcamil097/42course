/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:17:01 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/02 16:37:01 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char strupper(unsigned int idx, char c) {
	if (idx < 0 ) {
		return ('1');
	}
	return (ft_toupper(c));
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char			*str;
	unsigned int	x;

	if (!s || !f)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))    
		return (NULL);
	x = 0;
	while (s[x])
	{
		str[x] = (*f)(x, s[x]);
		++x;
	}
	return (str);
}
/* #include <stdio.h>
int main()
{
    char *str = NULL;
    int j;
    
    str = ft_strmapi("hola mundo", &strupper);
	j = 0;
    printf("%s",str);
    return 0;
    free(str);
} */

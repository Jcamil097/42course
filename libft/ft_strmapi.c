/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:17:01 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 12:56:58 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	x;

	x = 0;
	if (!s || (!s && !f))
		return (ft_strdup(""));
	if (!f)
		return (ft_strdup(s));
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (str[x])
	{
		str[x] = (*f)(x, str[x]);
		x++;
	}
	return (str);
}
/* #include <stdio.h>
char strupper(unsigned int idx, char c) {
	if (idx < 0 ) {
		return ('1');
	}
	return (ft_toupper(c));
}
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

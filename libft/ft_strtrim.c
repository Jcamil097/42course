/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:50:51 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/03 13:12:33 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int getInit(char const *s1, char const *set)
{
    size_t len;
    size_t cont;

    len = ft_strlen(s1);
    cont = 0;
    while (s1[cont] &&ft_strchr(set, s1[cont]))
        cont++;
    return (cont);
}

int getEnd(char const *s1, char const *set)
{
    size_t cont;

    cont = ft_strlen(s1);
    while (ft_strchr(set, s1[cont - 1]))
        cont--;
    return (cont);
}

void    *ft_strtrim(char const *s1, char const *set)
{
    int		init;
	int		end;
	char	*str;

    if (!s1)
        return (ft_strdup(""));
    if (!set)
        return (ft_strdup(s1));
	init = getInit(s1, set);
	end = getEnd(s1, set);
	str = (char *)malloc(sizeof(char) * (end - init + 1));
    if (!str)
        return (NULL);
	return (ft_substr(s1, init, end - init + 1));
}
/* #include <stdio.h>
int main()
{
    printf("%s",ft_strtrim("          "," "));
    return 0;
} */
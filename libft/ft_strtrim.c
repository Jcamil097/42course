/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:50:51 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/06 18:02:22 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	init(char const *s1, char const *set)
{
	size_t	cont;

	cont = 0;
	while (s1[cont] && ft_strchr(set, s1[cont]))
		cont++;
	return (cont);
}

int	end(char const *s1, char const *set)
{
	size_t	cont;

	cont = ft_strlen(s1);
	while (cont && ft_strchr(set, s1[cont]))
		cont--;
	return (cont);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	e;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	i = init(s1, set);
	e = end(s1, set);
	if (i >= e)
		return (ft_strdup(""));
	return (ft_substr(s1, i, e - i + 1));
}
#include <stdio.h>
int main()
{
    printf("%s",ft_strtrim("lorem ipsum dolor sit amet","te"));
    printf("\n");
    printf("%s",ft_strtrim("            "," "));
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:45:09 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:39:01 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	x;

	x = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(s))
		str = (char *)malloc(sizeof(*s) * (ft_strlen(s) - start + 1));
	else
		str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (x < len && s[start])
	{
		str[x] = s[start];
		x++;
		start++;
	}
	str[x] = '\0';
	return (str);
}

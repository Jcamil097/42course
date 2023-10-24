/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:49:06 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*start;
	int		i;
	int		len;

	len = ft_strlen(s1);
	start = malloc(len + 1);
	if (!start)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		start[i] = s1[i];
		i++;
	}
	start[i] = 0;
	return (start);
}

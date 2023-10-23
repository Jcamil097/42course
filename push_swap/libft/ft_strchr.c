/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:48:27 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/13 12:29:46 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*letter;
	int		i;

	letter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			letter = (char *)(str + i);
			return (letter);
		}
		i++;
	}
	if (str[i] == c)
		return ((char *)(str + i));
	return (NULL);
}

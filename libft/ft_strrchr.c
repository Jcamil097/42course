/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:00:09 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/08 10:45:07 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	x;

	x = ft_strlen(str) + 1;
	while (x--)
	{
		if (str[x] == (char)c)
			return ((char *)(str + x));
	}
	return (NULL);
}

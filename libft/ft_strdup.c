/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:25:36 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/08 10:43:31 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	x;

	x = ft_strlen(s1);
	str = (char *) malloc(sizeof(*s1) * (x + 1));
	if (str)
		ft_memcpy(str, s1, x + 1);
	return (str);
}

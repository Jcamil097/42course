/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:24:48 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/08 10:50:46 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstleng;
	size_t	srcleng;

	srcleng = ft_strlen(src);
	dstleng = ft_strlen(dst);
	j = dstleng;
	i = 0;
	if (dstleng < size - 1 && size > 0)
	{
		while (src[i] && dstleng + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dstleng >= size)
		dstleng = size;
	return (dstleng + srcleng);
}

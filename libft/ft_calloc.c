/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:22:26 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/08 10:38:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	if (count != 0 && (count * size) / count != size)
		return (NULL);
	c = (void *)malloc(count * size);
	if (!c)
		return (NULL);
	ft_memset(c, 0, count * size);
	return (c);
}

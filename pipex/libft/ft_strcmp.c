/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:44:36 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:37:38 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	it;

	it = 0;
	while (s1[it] && s2[it] && (s1[it] == s2[it]))
		it++;
	return ((unsigned char)s1[it] - (unsigned char)s2[it]);
}

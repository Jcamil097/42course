/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:40:46 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/09 11:28:12 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*src;
	size_t	len_src;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	src = (char *)s + start;
	len_src = ft_strlen(src);
	if (len_src < len)
		len = ++len_src;
	else
		len++;
	str = malloc(sizeof(char) * len);
	if (str)
		ft_strlcpy(str, src, len);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_only_for_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:50:06 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_only_for_num(const char *str)
{
	int		in;
	int		sign;
	long	num;

	in = 0;
	sign = 1;
	num = 0;
	while ((((str[in] > 8) && (str[in] < 14)) || str[in] == 32) && \
			str[in] != '\0')
		in++;
	if (str[in] == 43 || str[in] == 45)
		sign = (str[in++] & 2) - 1;
	while (str[in])
	{
		if (str[in] < 48 || str[in] > 57)
			ft_error("Error: not number");
		num = num * 10 + (str[in] - '0');
		in++;
	}
	num = num * sign;
	if (num > 2147483647 || num < -2147483648)
		ft_error("Error: argument not in INT");
	return ((int)num);
}

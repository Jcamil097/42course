/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:57:20 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/02 12:12:56 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		sign;
	int		tenp;

	i = 1;
	tenp = 1;
    sign = 1;
    if (n < 0)
        sign = 2;
	while ((n / tenp / 10) != 0 && ++i)
		tenp *= 10;
	if (!(result = malloc((unsigned int)(i + sign) * sizeof(char))))
		return (NULL);
	i = 0;
	if (sign == 2 && (sign = -1))
		result[i++] = '-';
	while (tenp != 0)
	{
		result[i++] = (char)((int)n / tenp * sign + 48);
		n %= tenp;
		tenp /= 10;
	}
	result[i++] = '\0';
	return (result);
}
/* #include <stdio.h>
int main()
{
    printf("%s",ft_itoa(2147483647));
    return 0;
} */

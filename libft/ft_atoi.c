/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:34:10 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/03 12:00:40 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	x;
	int	n;
	int	sig;

	x = 0;
	n = 0;
	sig = 1;
	while ((str[x] >= '\t' && str[x] <= '\r') || str[x] == 32)
		x++;
	while (str[x] && (str[x] == '-' || str[x] == '+'))
	{
		if (str[x] == '-')
			sig = sig * -1;
		x++;
		if (str[x] == '-' || str[x] == '+')
			return (0);
	}
	while (str[x] >= 48 && str[x] <= 57)
	{
		n = (n * 10) + (str[x] - '0');
		x++;
	}
	return (n * sig);
}
/* #include <stdio.h>
#include <string.h>
int main () {
	
   int val2;
   char str2[20];
   
   strcpy(str2, "++47");
   val2 = ft_atoi(str2);
   printf("String value = %s, Int value = %d\n", str2, val2);

   return(0);
} */
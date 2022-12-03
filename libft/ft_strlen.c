/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:48:28 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/02 15:19:02 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (s[cont] != '\0')
		cont++;
	return (cont);
}
/* #include <stdio.h>
#include <string.h>
int main()
{
	printf("%zu",ft_strlen("holasss"));
	printf("%s","\n");
	printf("%zu",strlen("holasss"));
	return 0;
} */
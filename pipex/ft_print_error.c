/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:30:36 by jumoncad          #+#    #+#             */
/*   Updated: 2023/02/07 12:05:10 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
/*
imprime los mensajes
*/
void ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	_exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:30:38 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/17 12:25:06 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_sc
{
	int	len;
	int	width;
}				t_sc;

void	ft_printhexa(unsigned int x, const char *str);
void	ft_putnbr_u(unsigned int n);
int		ft_print_p(unsigned long int p);

#endif

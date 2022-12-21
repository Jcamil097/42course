/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:12:20 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/21 10:28:55 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_ptr_len(unsigned long int num);
void	ft_putnbr_ptr(size_t num);
int		ft_print_p(unsigned long int p);
int		ft_putnbr_u(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_num_len_u(unsigned int num);
int		ft_printhexa(unsigned int x, const char *str);
int		ft_search_type(va_list arg, const char *str);
int		ft_putchar(char c);
int		num_len(int n);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_printf(char const *str, ...);

#endif

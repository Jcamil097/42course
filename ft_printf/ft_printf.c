/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:10:41 by jumoncad          #+#    #+#             */
/*   Updated: 2022/12/17 14:03:32 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const char	*ft_search_type(va_list arg, const char *str)
{
	unsigned long	x;

	if (*str == 'd' || *str == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1);
	else if (*str == 's')
		ft_putstr_fd(va_arg(arg, char *), 1);
	else if (*str == 'x' || *str == 'X')
	{
		/*verificar pruebas de x X*/
		x = va_arg(arg, unsigned long);
		ft_printhexa((unsigned long) x, str);
		/*ft_printhexa((unsigned long)va_arg(arg, unsigned long),str);*/
	}
	else if (*str == 'c')
		ft_putchar_fd((char)va_arg(arg, char *), 1);
	else if (*str == 'u')
		ft_putnbr_u((unsigned long)va_arg(arg, unsigned int));
	else if (*str == 'p')
		//verificar pruebas P
		ft_print_p(va_arg(arg, unsigned long long));
	else if (*str == '%')
		ft_putchar_fd('%', 1);
	else
		return (NULL);
	str++;
	return (str);
}

const char	*ft_read_text(t_sc *sc, const char *str)
{
	char	*next;

	next = ft_strchr(str, '%');
	if (next)
		sc ->width = next - str;
	else
		sc ->width = ft_strlen(str);
	write(1, str, sc ->width);
	sc ->len += sc->width;
	while (*str && *str != '%')
		++str;
	return (str);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	t_sc	sc;

	va_start(arg, str);
	sc.len = 0;
	sc.width = 0;
	while (*str)
	{
		if (*str == '%')
			str = ft_search_type(arg, str + 1);
		else
			str = ft_read_text(&sc, str);
		if (!str)
		{
			va_end(arg);
			return (sc.len);
		}
	}
	va_end(arg);
	return (sc.len);
}
#define INT_MIN -2147483648
#define INT_MAX +2147483647
#define UINT_MAX +4294967295

int	main(void)
{
	char	*ptr;

	printf("Test 1\n");
	printf(" -> My total:   %i\n", (ft_printf("%c", 'a')));
	printf(" -> Real total: %i\n", (printf("%c", 'a')));
	printf("\n");
	printf("Test 2\n");
	printf(" -> My total:   %i\n", (ft_printf("%s", "_ Kaixo !!")));
	printf(" -> Real total: %i\n", (printf("%s", "_ Kaixo !!")));
	printf("\n");
	printf("Test 3\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", 123)));
	printf(" -> Real total: %i\n", (printf("%d", 123)));
	printf("\n");
	printf("Test 4\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", -123)));
	printf(" -> Real total: %i\n", (printf("%d", -123)));
	printf("\n");
	printf("Test 5\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", 0)));
	printf(" -> Real total: %i\n", (printf("%d", 0)));
	printf("\n");
	printf("Test 6\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", INT_MAX)));
	printf(" -> Real total: %i\n", (printf("%d", INT_MAX)));
	printf("\n");
	printf("Test 7\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", INT_MIN)));
	printf(" -> Real total: %i\n", (printf("%d", INT_MIN)));
	printf("\n");
	printf("Test 8\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", UINT_MAX)));
	printf(" -> Real total: %i\n", (printf("%d", UINT_MAX)));
	printf("\n");
	printf("Test 9\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", 123)));
	printf(" -> Real total: %i\n", (printf("%i", 123)));
	printf("\n");
	printf("Test 10\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", -123)));
	printf(" -> Real total: %i\n", (printf("%i", -123)));
	printf("\n");
	printf("Test 11\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", 0)));
	printf(" -> Real total: %i\n", (printf("%i", 0)));
	printf("\n");
	printf("Test 12\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", INT_MAX)));
	printf(" -> Real total: %i\n", (printf("%i", INT_MAX)));
	printf("\n");
	printf("Test 13\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", INT_MIN)));
	printf(" -> Real total: %i\n", (printf("%i", INT_MIN)));
	printf("\n");
	printf("Test 14\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", UINT_MAX)));
	printf(" -> Real total: %i\n", (printf("%i", UINT_MAX)));
	printf("\n");
	printf("Test 15\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", 123)));
	printf(" -> Real total: %i\n", (printf("%u", 123)));
	printf("\n");
	printf("Test 16\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", -123)));
	printf(" -> Real total: %i\n", (printf("%u", -123)));
	printf("\n");
	printf("Test 17\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", 0)));
	printf(" -> Real total: %i\n", (printf("%u", 0)));
	printf("\n");
	printf("Test 18\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", INT_MAX)));
	printf(" -> Real total: %i\n", (printf("%u", INT_MAX)));
	printf("\n");
	printf("Test 19\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", INT_MIN)));
	printf(" -> Real total: %i\n", (printf("%u", INT_MIN)));
	printf("\n");
	printf("Test 20\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", UINT_MAX)));
	printf(" -> Real total: %i\n", (printf("%u", UINT_MAX)));
	printf("\n");
	printf("Test 21\n");
	printf(" -> My total:   %i\n", (ft_printf("%x", 123)));
	printf(" -> Real total: %i\n", (printf("%x", 123)));
	printf("\n");
	printf("Test 22\n");
	printf("  -> My total:   %i\n", (ft_printf("%x", -123)));
	printf(" -> Real total: %i\n", (printf("%x", -123)));
	printf("\n");
	printf("Test 23\n");
	printf(" -> My total:   %i\n", (ft_printf("%x", 0)));
	printf(" -> Real total: %i\n", (printf("%x", 0)));
	printf("\n");
	printf("Test 24\n");
	printf(" -> My total:   %i\n", (ft_printf("%x", INT_MAX)));
	printf(" -> Real total: %i\n", (printf("%x", INT_MAX)));
	printf("\n");
	printf("Test 25\n");
	printf(" -> My total:   %i\n", (ft_printf("%x", INT_MIN)));
	printf(" -> Real total: %i\n", (printf("%x", INT_MIN)));
	printf("\n");
	printf("Test 26\n");
	printf(" -> My total:   %i\n", (ft_printf("%X", 123)));
	printf(" -> Real total: %i\n", (printf("%X", 123)));
	printf("\n");
	printf("Test 27\n");
	printf(" -> My total:   %i\n", (ft_printf("%X", -123)));
	printf(" -> Real total: %i\n", (printf("%X", -123)));
	printf("\n");
	printf("Test 28\n");
	printf(" -> My total:   %i\n", (ft_printf("%X", 0)));
	printf(" -> Real total: %i\n", (printf("%X", 0)));
	printf("\n");
	printf("Test 29\n");
	printf(" -> My total:   %i\n", (ft_printf("%X", INT_MAX)));
	printf(" -> Real total: %i\n", (printf("%X", INT_MAX)));
	printf("\n");
	printf("Test 30\n");
	printf(" -> My total:   %i\n", (ft_printf("%X", INT_MIN)));
	printf(" -> Real total: %i\n", (printf("%X", INT_MIN)));
	printf("\n");
	printf("Test 31\n");
	printf(" -> My total:   %i\n", (ft_printf("%p", ptr)));
	printf(" -> Real total: %i\n", (printf("%p", ptr)));
	printf("\n");
	printf("Test 32\n");
	printf(" -> My total:   %i\n", (ft_printf("%p", 0)));
	printf(" -> Real total: %i\n", (printf("%p", 0)));
	printf("\n");
	printf("Test 33\n");
	printf(" -> My total:   %i\n", (ft_printf("%%")));
	printf(" -> Real total: %i\n", (printf("%%")));
	printf("\n");
	printf("Test 34\n");
	printf(" -> My total:   %i\n", (ft_printf("%")));
	printf(" -> Real total: %i\n", (printf("%")));
	printf("\n\n\n");


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:21:32 by jumoncad          #+#    #+#             */
/*   Updated: 2023/04/21 14:42:17 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define INT_MIN -2147483648
#define INT_MAX +2147483647
#define UINT_MAX +4294967295

int	main(void)
{
	char	*ptr;
	//gcc ft_print_p.c ft_print_u.c ft_print_x.c ft_printf.c ft_utils.c main.c
	printf("-------------------------- MANDATORY --------------------------\n");
	printf("Test c\n");
	printf(" -> My total:   %i\n", (ft_printf("%c", 'a')));
	printf(" -> Real total: %i\n", (printf("%c", 'a')));
	printf("\n");
	printf("Test s\n");
	printf(" -> My total:   %i\n", (ft_printf("%s", "_ Kaixo !!")));
	printf(" -> Real total: %i\n", (printf("%s", "_ Kaixo !!")));
	printf("\n");
	printf("Test d\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", 123)));
	printf(" -> Real total: %i\n", (printf("%d", 123)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", -123)));
	printf(" -> Real total: %i\n", (printf("%d", -123)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", 0)));
	printf(" -> Real total: %i\n", (printf("%d", 0)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", INT_MAX)));
	printf(" -> Real total: %i\n", (printf("%d", INT_MAX)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", INT_MIN)));
	printf(" -> Real total: %i\n", (printf("%d", INT_MIN)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%d", UINT_MAX)));
	printf(" -> Real total: %i\n", (printf("%d", UINT_MAX)));
	printf("\n");
	printf("Test i\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", 123)));
	printf(" -> Real total: %i\n", (printf("%i", 123)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", -123)));
	printf(" -> Real total: %i\n", (printf("%i", -123)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", 0)));
	printf(" -> Real total: %i\n", (printf("%i", 0)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", INT_MAX)));
	printf(" -> Real total: %i\n", (printf("%i", INT_MAX)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", INT_MIN)));
	printf(" -> Real total: %i\n", (printf("%i", INT_MIN)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%i", UINT_MAX)));
	printf(" -> Real total: %i\n", (printf("%i", UINT_MAX)));
	printf("\n");
	printf("Test u\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", 123)));
	printf(" -> Real total: %i\n", (printf("%u", 123)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", -123)));
	printf(" -> Real total: %i\n", (printf("%u", -123)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", 0)));
	printf(" -> Real total: %i\n", (printf("%u", 0)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", INT_MAX)));
	printf(" -> Real total: %i\n", (printf("%u", INT_MAX)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", INT_MIN)));
	printf(" -> Real total: %i\n", (printf("%u", INT_MIN)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%u", UINT_MAX)));
	printf(" -> Real total: %i\n", (printf("%u", UINT_MAX)));
	printf("\n");
	printf("Test x\n");
	printf(" -> My total:   %i\n", (ft_printf("%x", 123)));
	printf(" -> Real total: %i\n", (printf("%x", 123)));
	printf("\n");
	printf("  -> My total:   %i\n", (ft_printf("%x", -123)));
	printf(" -> Real total: %i\n", (printf("%x", -123)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%x", 0)));
	printf(" -> Real total: %i\n", (printf("%x", 0)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%x", INT_MAX)));
	printf(" -> Real total: %i\n", (printf("%x", INT_MAX)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%x", INT_MIN)));
	printf(" -> Real total: %i\n", (printf("%x", INT_MIN)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%X", 123)));
	printf(" -> Real total: %i\n", (printf("%X", 123)));
	printf("\n");
	printf("Test X\n");
	printf(" -> My total:   %i\n", (ft_printf("%X", -123)));
	printf(" -> Real total: %i\n", (printf("%X", -123)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%X", 0)));
	printf(" -> Real total: %i\n", (printf("%X", 0)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%X", INT_MAX)));
	printf(" -> Real total: %i\n", (printf("%X", INT_MAX)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%X", INT_MIN)));
	printf(" -> Real total: %i\n", (printf("%X", INT_MIN)));
	printf("\n");
	printf("Test p\n");
	printf(" -> My total:   %i\n", (ft_printf("%p", ptr)));
	printf(" -> Real total: %i\n", (printf("%p", ptr)));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%p", 0)));
	printf(" -> Real total: %i\n", (printf("%p", 0)));
	printf("\n");
	printf("Test %%\n");
	printf(" -> My total:   %i\n", (ft_printf("%%")));
	printf(" -> Real total: %i\n", (printf("%%")));
	printf("\n");
	printf(" -> My total:   %i\n", (ft_printf("%")));
	printf(" -> Real total: %i\n", (printf("%")));
	/*printf("\n\n\n");
	
	 printf("------------------------------------------------------\n");
	printf("------------------------------------------------------\n");
	printf("-------------------------- BONUS ---------------------\n");
	printf("------------------------------------------------------\n");
	printf("------------------------------------------------------\n");
	printf("Test 35\n");
	printf(" -> My total:   %i\n", (ft_printf("%+c", '+')));
	printf(" -> Real total: %i\n", (printf("%+c", '+')));
	printf("\n");
	printf("Test 36\n");
	printf(" -> My total:   %i\n", (ft_printf("%-c", '-')));
	printf(" -> Real total: %i\n", (printf("%-c", '-')));
	printf("\n");
	printf("Test 37\n");
	printf(" -> My total:   %i\n", (ft_printf("% c", ' ')));
	printf(" -> Real total: %i\n", (printf("% c", ' ')));
	printf("\n");
	printf("Test 38\n");
	printf(" -> My total:   %i\n", (ft_printf("%#c", '#')));
	printf(" -> Real total: %i\n", (printf("%#c", '#')));
	printf("\n");
	printf("Test 39\n");
	printf(" -> My total:   %i\n", (ft_printf("%0c", '0')));
	printf(" -> Real total: %i\n", (printf("%0c", '0')));
	printf("\n");
	printf("Test 40\n");
	printf(" -> My total:   %i\n", (ft_printf("%1c", '1')));
	printf(" -> Real total: %i\n", (printf("%1c", '1')));
	printf("\n");
	printf("Test 41\n");
	printf(" -> My total:   %i\n", (ft_printf("%2c", '0')));
	printf(" -> Real total: %i\n", (printf("%2c", '0')));
	printf("\n");
	printf("Test 42\n");
	printf(" -> My total:   %i\n", (ft_printf("%1.1c", '.')));
	printf(" -> Real total: %i\n", (printf("%1.1c", '.')));
	printf("\n");
	printf("Test 43\n");
	printf(" -> My total:   %i\n", (ft_printf("%1.2c", '.')));
	printf(" -> Real total: %i\n", (printf("%1.2c", '.')));
	printf("\n");
	printf("Test 44\n");
	printf(" -> My total:   %i\n", (ft_printf("%4.1c", '.')));
	printf(" -> Real total: %i\n", (printf("%4.1c", '.')));
	printf("\n");

	printf("Test 45\n");
	printf(" -> My total:   %i\n", (ft_printf("%+s", "%+s")));
	printf(" -> Real total: %i\n", (printf("%+s", "%+s")));
	printf("\n");
	printf("Test 46\n");
	printf(" -> My total:   %i\n", (ft_printf("%-s", "%-s")));
	printf(" -> Real total: %i\n", (printf("%-s", "%-s")));
	printf("\n");
	printf("Test 47\n");
	printf(" -> My total:   %i\n", (ft_printf("% s", "% s")));
	printf(" -> Real total: %i\n", (printf("% s", "% s")));
	printf("\n");
	printf("Test 48\n");
	printf(" -> My total:   %i\n", (ft_printf("%#s", "%#s")));
	printf(" -> Real total: %i\n", (printf("%#s", "%#s")));
	printf("\n");
	printf("Test 49\n");
	printf(" -> My total:   %i\n", (ft_printf("%0s", "%0s")));
	printf(" -> Real total: %i\n", (printf("%0s", "%0s")));
	printf("\n");
	printf("Test 50\n");
	printf(" -> My total:   %i\n", (ft_printf("%1s", "%1s")));
	printf(" -> Real total: %i\n", (printf("%1s", "%1s")));
	printf("\n");
	printf("Test 51\n");
	printf(" -> My total:   %i\n", (ft_printf("%2s", "%2s")));
	printf(" -> Real total: %i\n", (printf("%2s", "%2s")));
	printf("\n");
	printf("Test 52\n");
	printf(" -> My total:   %i\n", (ft_printf("%1.1s", "%1.1s")));
	printf(" -> Real total: %i\n", (printf("%1.1s", "%1.1s")));
	printf("\n");
	printf("Test 53\n");
	printf(" -> My total:   %i\n", (ft_printf("%1.2s", "%1.2s")));
	printf(" -> Real total: %i\n", (printf("%1.2s", "%1.2s")));
	printf("\n");
	printf("Test 54\n");
	printf(" -> My total:   %i\n", (ft_printf("%4.1s", "%4.1s")));
	printf(" -> Real total: %i\n", (printf("%4.1s", "%4.1s")));
	printf("\n");

	printf("Test 55\n");
	printf(" -> My total:   %i\n", (ft_printf("%#d", 123)));
	printf(" -> Real total: %i\n", (printf("%#d", 123)));
	printf("\n");

	printf("Test 56\n");
	printf(" -> My total:   %i\n", (ft_printf("%#i", 123)));
	printf(" -> Real total: %i\n", (printf("%#i", 123)));
	printf("\n");

	printf("Test 57\n");
	printf(" -> My total:   %i\n", (ft_printf("%+u", 123)));
	printf(" -> Real total: %i\n", (printf("%+u", 123)));
	printf("\n");
	printf("Test 58\n");
	printf(" -> My total:   %i\n", (ft_printf("% u", 123)));
	printf(" -> Real total: %i\n", (printf("% u", 123)));
	printf("\n");
	printf("Test 59\n");
	printf(" -> My total:   %i\n", (ft_printf("%#u", 123)));
	printf(" -> Real total: %i\n", (printf("%#u", 123)));
	printf("\n");

	printf("Test 60\n");
	printf(" -> My total:   %i\n", (ft_printf("%+p", ptr)));
	printf(" -> Real total: %i\n", (printf("%+p", ptr)));
	printf("\n");
	printf("Test 61\n");
	printf(" -> My total:   %i\n", (ft_printf("% p", ptr)));
	printf(" -> Real total: %i\n", (printf("% p", ptr)));
	printf("\n");
	printf("Test 62\n");
	printf(" -> My total:   %i\n", (ft_printf("%#p", ptr)));
	printf(" -> Real total: %i\n", (printf("%#p", ptr)));
	printf("\n");
	printf("Test 63\n");
	printf(" -> My total:   %i\n", (ft_printf("%0p", ptr)));
	printf(" -> Real total: %i\n", (printf("%0p", ptr)));
	printf("\n");
	printf("Test 64\n");
	printf(" -> My total:   %i\n", (ft_printf("%.p", ptr)));
	printf(" -> Real total: %i\n", (printf("%.p", ptr)));
	printf("\n");
	printf("Test 65\n");
	printf(" -> My total:   %i\n", (ft_printf("%1.1p", ptr)));
	printf(" -> Real total: %i\n", (printf("%1.1p", ptr)));
	printf("\n");
	printf("Test 66\n");
	printf(" -> My total:   %i\n", (ft_printf("%1.2p", ptr)));
	printf(" -> Real total: %i\n", (printf("%1.2p", ptr)));
	printf("\n");
	printf("Test 67\n");
	printf(" -> My total:   %i\n", (ft_printf("%4.2p", ptr)));
	printf(" -> Real total: %i\n", (printf("%4.2p", ptr)));
	printf("\n");

	printf("Test 68\n");
	printf(" -> My total:   %i\n", (ft_printf("%+%")));
	printf(" -> Real total: %i\n", (printf("%+%")));
	printf("\n");
	printf("Test 68\n");
	printf(" -> My total:   %i\n", (ft_printf("% %")));
	printf(" -> Real total: %i\n", (printf("% %")));
	printf("\n");
	printf("Test 68\n");
	printf(" -> My total:   %i\n", (ft_printf("%#%")));
	printf(" -> Real total: %i\n", (printf("%#%")));
	printf("\n");
	printf("Test 68\n");
	printf(" -> My total:   %i\n", (ft_printf("%.%")));
	printf(" -> Real total: %i\n", (printf("%.%")));
	printf("\n");
	printf("Test 68\n");
	printf(" -> My total:   %i\n", (ft_printf("%1.1%")));
	printf(" -> Real total: %i\n", (printf("%1.1%")));
	printf("\n");
	printf("Test 68\n");
	printf(" -> My total:   %i\n", (ft_printf("%1.0%")));
	printf(" -> Real total: %i\n", (printf("%1.0%")));
	printf("\n");
	printf("Test 68\n");
	printf(" -> My total:   %i\n", (ft_printf("%3.1%")));
	printf(" -> Real total: %i\n", (printf("%3.1%"))); 
	printf("\n");*/
	return (0);
}
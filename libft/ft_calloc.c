/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:22:26 by jumoncad          #+#    #+#             */
/*   Updated: 2022/11/30 14:03:58 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;

    ptr = (void*) malloc(count * size);
    if (!ptr)
    {
        return NULL;
    }
    ft_bzero(ptr, count);
    return (ptr);
}
/* #include <stdio.h>
#include <stdlib.h>
int main (void) {
   long *buffer;

   buffer = (long *)ft_calloc( 40, sizeof( long ) );
   buffer = (long *)calloc( 40, sizeof( long ) );
   if( buffer != NULL )
      printf( "Allocated 40 long integers\n" );
   else
      printf( "Can't allocate memory\n" );
   free( buffer );
} */
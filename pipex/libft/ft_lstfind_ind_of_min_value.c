/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_ind_of_min_value.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:50:45 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstfind_ind_of_min_value(t_list *lst)
{
	int	min_value;
	int	min_ind;
	int	it;

	min_ind = 0;
	min_value = (int)lst->content;
	lst = lst->next;
	it = 1;
	while (lst)
	{
		if ((int)lst->content < min_value)
		{
			min_ind = it;
			min_value = (int)lst->content;
		}
		lst = lst->next;
		it++;
	}
	return (min_ind);
}

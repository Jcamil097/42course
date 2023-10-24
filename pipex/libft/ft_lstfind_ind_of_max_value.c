/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_ind_of_max_value.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:50:42 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:08 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstfind_ind_of_max_value(t_list *lst)
{
	int	max_value;
	int	max_ind;
	int	it;

	max_ind = 0;
	max_value = (int)lst->content;
	lst = lst->next;
	it = 1;
	while (lst)
	{
		if ((int)lst->content > max_value)
		{
			max_ind = it;
			max_value = (int)lst->content;
		}
		lst = lst->next;
		it++;
	}
	return (max_ind);
}

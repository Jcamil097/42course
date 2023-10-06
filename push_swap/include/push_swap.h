/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:59:50 by jumoncad          #+#    #+#             */
/*   Updated: 2023/10/05 15:34:47 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	max_size;
	int	middle;
}		t_stack;

/*****************ft_error*****************/
void	ft_error(char **str, t_stack *stack, int *array);
void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b);

/*****************ft_check_args*****************/
void	ft_check_args(int argc, char **argv);

/*****************ft_process_args*****************/
char	**ft_process_args(int argc, char **argv, t_stack *stack);

/*****************ft_parse_args*****************/
int		*ft_parse_args(char **str, t_stack *stack);

/*****************ft_utils*****************/
int		ft_is_sorted(t_stack *stack);
int		ft_is_sign(char c);
void	ft_print_instruction(char *action);

/*****************ft_sort_process*****************/
void	ft_init_sort(t_stack *stack_a, t_stack *stack_b);

/*****************ft_instructions*****************/
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate(t_stack *stack, char c);
void	ft_reverse_rotate(t_stack *stack, char c);
void	ft_s(t_stack *stack, char c);

/*****************ft_utils_sort*****************/
void	ft_insert_min_int_to_top(t_stack *stack, char c);
int		ft_get_min(t_stack *stack);

/*****************ft_quick_sort*****************/
void	ft_quick_sort(t_stack *stack_a, t_stack *stack_b, int quick_size);

/*****************ft_utils_quick_sort*****************/
int		ft_get_index(t_stack *stack, int number);
int		ft_find_next_min_int(t_stack *stack, int min);
int		ft_get_min_index(t_stack *stack, int min);
void	ft_insert_int_to_top(t_stack *stack, char c, int number);

#endif
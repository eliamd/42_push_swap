/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:51:14 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/09 18:44:15 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node *last;

	if (!stack || !*stack || ps_stack_len(stack) == 0)
		return ;
	last = last_node(stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **stack, bool check)
{
	reverse_rotate(stack);
	if (!check)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **stack, bool check)
{
	reverse_rotate(stack);
	if (!check)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool check)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!check)
		ft_putstr_fd("rrr\n", 1);
}
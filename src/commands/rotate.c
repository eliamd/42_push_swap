/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:51:14 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/09 18:23:56 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node *tmp;
	t_stack_node *last;

	if (!stack || !*stack || ps_stack_len(stack) == 0)
		return ;
	last = last_node(stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_node **stack, bool check)
{
	rotate(stack);
	if (!check)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_node **stack, bool check)
{
	rotate(stack);
	if (!check)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool check)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!check)
		ft_putstr_fd("rr\n", 1);
}
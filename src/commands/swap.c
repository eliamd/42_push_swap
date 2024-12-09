/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:31:13 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/09 13:32:51 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack_node **stack)
{
	if (!stack || ps_stack_len(stack) == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **stack, bool check)
{
	swap(stack);
	if (!check)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **stack, bool check)
{
	swap(stack);
	if (!check)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, bool check)
{
	swap(stack_a);
	swap(stack_b);
	if (!check)
		ft_putstr_fd("ss\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:36:02 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/10 16:45:55 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_stack_len(t_stack_node **stack)
{
	t_stack_node	*stack_work;
	int				i;

	if (!stack)
		return (0);
	i = 0;
	stack_work = *stack;
	while (stack_work)
	{
		stack_work = stack_work->next;
		i++;
	}
	return (i);
}

t_stack_node	*last_node(t_stack_node **stack)
{
	t_stack_node	*stack_work;

	if (!stack)
		return (NULL);
	stack_work = *stack;
	while (stack_work->next)
		stack_work = stack_work->next;
	return (stack_work);
}

t_stack_node	*find_smallest(t_stack_node **stack)
{
	t_stack_node	*smallest;
	t_stack_node	*stack_work;
	int				smallest_nbr;

	if (!*stack || !stack)
		return (NULL);
	stack_work = *stack;
	smallest = stack_work;
	while (stack_work)
	{
		if (stack_work->value < smallest_nbr)
		{
			smallest_nbr = stack_work->value;
			smallest = stack_work;
		}
		stack_work = stack_work->next;
	}
	return (smallest);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

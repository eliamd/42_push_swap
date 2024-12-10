/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:59:18 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/10 16:41:24 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int		i;
	int		centerline;

	i = 0;
	if (!stack)
		return ;
	centerline = (ps_stack_len(&stack) / 2);
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smallest(&a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int		len_a;
	int		len_b;

	len_a = ps_stack_len(&a);
	len_b = ps_stack_len(&b);
	while (b)
	{
		b->push_cost = b->current_position;
		if (!(b->above_median))
			b->push_cost = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->current_position;
		else
			b->push_cost += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (!b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_match_value)
		{
			best_match_value = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	nodes_init(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

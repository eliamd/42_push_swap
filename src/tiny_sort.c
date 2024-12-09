/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:01:31 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/09 12:30:00 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_highsest_node(t_stack_node *node)
{
	t_stack_node *node_work;
	t_stack_node *tmp;

	if (!node)
		return ;
	node_work = node;
	tmp = node;
	while (node_work)
	{
		if (node_work->value > tmp->value)
			tmp = node_work;
		node_work = node_work->next;
	}
	return (tmp);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node *highest_node;

	highest_node = find_highsest_node(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->next > (*a)->next->value)
		sa(a, false);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:32:44 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/10 13:23:33 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*tmp;

	if (!src || ps_stack_len(src) == 0)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
}

void	pa(t_stack_node **a, t_stack_node **b, bool check)
{
	push(b, a);
	if (!check)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack_node **a, t_stack_node **b, bool check)
{
	push(a, b);
	if (!check)
		ft_putstr_fd("pb\n", 1);
}

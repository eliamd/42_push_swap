/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:36:02 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/09 12:39:40 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_stack_len(t_stack_node **stack)
{
	t_stack_node	*stack_work;
	int				i;

	if (!stack)
		return 0;
	i = 0;
	stack_work = *stack;
	while (stack_work)
	{
		stack_work = stack_work->next;
		i++;
	}
	return (i);
}
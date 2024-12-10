/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:59:18 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/10 16:42:51 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apprend_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (!*stack)
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = node;
		node->prev = last_node;
	}
}

void	stack_init(t_stack_node **a, char **argv, bool flag_argc)
{
	int		i;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atoi_long(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(a, argv, flag_argc);
		if (error_repetition(*a, (int)nbr))
			free_error(a, argv, flag_argc);
		apprend_node(a, (int)nbr);
		i++;
	}
}

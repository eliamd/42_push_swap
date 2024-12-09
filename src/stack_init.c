/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:59:18 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/09 11:58:35 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *nptr)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 0;
	n = 0;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32) && nptr[i])
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	if (sign % 2)
	{
		n *= -1;
	}
	return (n);
}

bool	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}



void	apprend_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;
	t_stack_node	*t;

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
			error_free(a, argv, flag_argc);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc);
		apprend_node(a, (int)nbr);
		i++;
	}
}

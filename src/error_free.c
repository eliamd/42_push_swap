/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:10:01 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/09 11:34:42 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **argv)
{
	int	i;

	i = 0;
	if (!argv || !*argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*stack_before;
	t_stack_node	*tmp;

	if (!stack)
		return ;
	stack_before = *stack;
	while (stack_before)
	{
		tmp = stack_before->next;
		free(stack_before);
		stack_before = tmp;
	}
	stack = NULL;
}

void	free_error(t_stack_node **stack, char **argv, bool flag)
{
	free_stack(stack);
	if (flag)
		free_split(argv);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

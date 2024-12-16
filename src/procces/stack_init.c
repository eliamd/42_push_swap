/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:55:46 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/16 17:37:23 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Sets index and median status for each node.
// Parameter: stack (pointer to stack).
// Updates index and above_median fields.
// Returns: Nothing (void function).

void	set_index_and_median(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

// Appends a new node with value n to the stack.
// Parameters: stack (pointer to stack), n (value).
// Allocates memory and sets node properties.
// Returns: Nothing (void function).

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

// Initializes stack a with values from argv.
// Parameters: a (pointer to stack a),
// argv (array of strings), use_split (bool).
// Parses argv, checks for errors, and appends nodes.
// Returns: Nothing (void function).

void	init_stack_a(t_stack_node **a, char **argv, bool use_split)
{
	long	n;
	int		i;

	i = 0;
	if (!argv)
		free_errors(a, use_split, argv);
	if (!use_split)
		argv++;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a, use_split, argv);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, use_split, argv);
		if (error_duplicate(*a, (int)n))
			free_errors(a, use_split, argv);
		append_node(a, (int)n);
		i++;
	}
}

// Finds the cheapest node in the stack.
// Parameter: stack (pointer to stack).
// Searches for the node marked as cheapest.
// Returns: Pointer to the cheapest node or NULL.

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

// Prepares stack for pushing a node to the top.
// Parameters: stack (pointer to stack),
// top_node (node to move), stack_name (a or b).
// Rotates stack until top_node is at the top.
// Returns: Nothing (void function).

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

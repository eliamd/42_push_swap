/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:04:58 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/09 18:44:42 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../42_libft-mylibft/libft.h"

typedef struct s_stack_node
{
	int						value;
	int						current_position;
	int						final_position;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}							t_stack_node;

bool	ft_isnumber(char *str);
void	stack_init(t_stack_node **a, char **argv, bool flag_argc);

// =============== Utils ================

int				ps_stack_len(t_stack_node **stack);
void			print_stack(t_stack_node *stack);
t_stack_node	*last_node(t_stack_node **stack);

// =============== End Utils ================

// =============== Commands ================

//swap
void	sa(t_stack_node **stack, bool check);
void	sb(t_stack_node **stack, bool check);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b, bool check);
//push
void	pa(t_stack_node **a, t_stack_node **b, bool check);
void	pb(t_stack_node **a, t_stack_node **b, bool check);
//rotate
void	ra(t_stack_node **stack, bool check);
void	rb(t_stack_node **stack, bool check);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool check);
//reverse rotate
void	rra(t_stack_node **stack, bool check);
void	rrb(t_stack_node **stack, bool check);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool check);
// =============== End Commands ================

#endif
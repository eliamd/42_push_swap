/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:04:58 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/06 18:08:25 by edetoh           ###   ########.fr       */
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
void	stack_init(t_stack_node **a, char **argv, bool split);

#endif
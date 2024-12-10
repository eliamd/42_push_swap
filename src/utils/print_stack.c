/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edetoh <edetoh@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:03:03 by edetoh            #+#    #+#             */
/*   Updated: 2024/12/10 13:22:13 by edetoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_stack(t_stack_node *stack)
{
	t_stack_node *current = stack;
	int position = 1;

	ft_printf("╔════════════════════════════════════════╗\n");
	ft_printf("║            🏆 STACK DETAILS           ║\n");
	ft_printf("╠════════════════════════════════════════╣\n");
	if (!current) {
		ft_printf("║           📭 Stack is Empty!          ║\n");
		ft_printf("╚════════════════════════════════════════╝\n");
		return;
	}
	while (current) {
		ft_printf("║ 📍 Position: %d                       ║\n", position);
		ft_printf("╠════════════════════════════════════════╣\n");
		ft_printf("║   🔢 Value:            %d           ║\n", current->value);
		ft_printf("║   📊 Current Position: %d           ║\n", current->current_position);
		ft_printf("║   🎯 Final Position:   %d           ║\n", current->final_position);
		ft_printf("║   💰 Push Cost:        %d           ║\n", current->push_cost);
		ft_printf("║   📈 Above Median:     %s           ║\n", current->above_median ? "Yes" : "No");
		ft_printf("║   💡 Cheapest:         %s           ║\n", current->cheapest ? "Yes" : "No");

		// Liens
		ft_printf("║   🔗 Prev Node:   %p                 ║\n", (void*)current->prev);
		ft_printf("║   🔗 Next Node:   %p                 ║\n", (void*)current->next);

		ft_printf("╠════════════════════════════════════════╣\n");

		current = current->next;
		position++;
	}
	ft_printf("╚════════════════════════════════════════╝\n");
}

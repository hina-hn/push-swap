/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:21:05 by YourName          #+#    #+#             */
/*   Updated: 2025/02/12 18:36:06 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_node_on_top(t_node **top)
{
	t_node	*min_node;
	int		stack_size;

	min_node = find_min_node(*top);
	stack_size = stak_len(*top);
	set_index_stack(*top);
	while ((*top) != min_node)
	{
		if (min_node->index <= (stack_size - 1) / 2)
			rotate(top, "ra");
		else
			rev_rotate(top, "rra");
	}
}

void	sort_stacks(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len((*a));
	if (len_a-- > 3 && _is_sorted(*a))
		push(b, a, "pb");
	if (len_a-- > 3 && !is_sorted(*a))
		push(b, a, "pb");
	while (len_a-- > 3 && !is_sorted(*a))
	{
		set_index_both_stack(*a, *b);
		find_target_a(*a, *b);
		calc_all_push_costs(*a, *b);
		mark_cheapest_node(*a);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_index_both_stack(*a, *b);
		find_target_b(*a, *b);
		move_b_to_a(a, b);
	}
	min_on_top(a);
}

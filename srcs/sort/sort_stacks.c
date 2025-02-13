/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:21:05 by YourName          #+#    #+#             */
/*   Updated: 2025/02/13 21:34:23 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_node_on_top(t_node **top)
{
	t_node	*min_node;
	int		stack_size;

	min_node = find_min_node(*top);
	stack_size = stack_len(*top);
	set_index_stack(*top);
	while ((*top) != min_node)
	{
		if (min_node->index <= (stack_size - 1) / 2)
			rotate(top, "ra");
		else
			reverse_rotate(top, "rra");
	}
}

void	sort_stacks(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len((*a));
	printf("stack-len: %d\n", len_a);
	if (len_a-- > 3 && !is_sorted(*a))
	{
		push(b, a, "pb");
	}
	if (len_a-- > 3 && !is_sorted(*a))
	{
		push(b, a, "pb");
	}
	while (len_a-- > 3 && !is_sorted(*a))
	{
		set_index_both_stack(*a, *b);
		find_target_a(*a, *b);
		calc_all_push_costs(*a, *b);
		mark_cheapest_node(*a);
		printf("is-cheapest: %d\n", (*a)->is_cheapest);
		move_a_to_b(a, b);
	}
	sort_three(a);
	print_stack(*a, 'A');
	print_stack(*b, 'B');
	while (*b)
	{
		set_index_both_stack(*a, *b);
		find_target_b(*a, *b);
		move_b_to_a(a, b);
	}
	min_node_on_top(a);
}

int	stack_len(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	is_sorted(t_node *stack)
{
	if (!stack || !(stack->next))
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
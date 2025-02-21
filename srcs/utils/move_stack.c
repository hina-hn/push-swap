/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:50:47 by YourName          #+#    #+#             */
/*   Updated: 2025/02/21 16:55:19 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_cheapest_node(t_node *a)
{
	t_node	*current;

	current = a;
	while (current)
	{
		if (current->is_cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	move_to_positions(t_node **a, t_node **b, t_node *cheapest_node)
{
	if (cheapest_node->best_direction == UP_UP)
		while (*a != cheapest_node && *b != cheapest_node->target_node)
			rr(a, b);
	else if (cheapest_node->best_direction == DOWN_DOWN)
		while (*a != cheapest_node && *b != cheapest_node->target_node)
			rrr(a, b);
	while (*a != cheapest_node)
	{
		if (cheapest_node->best_direction == UP_DOWN
			|| cheapest_node->best_direction == UP_UP)
			rotate(a, "ra");
		else
			reverse_rotate(a, "rra");
	}
	while (*b != cheapest_node->target_node)
	{
		if (cheapest_node->best_direction == DOWN_UP
			|| cheapest_node->best_direction == UP_UP)
			rotate(b, "rb");
		else
			reverse_rotate(b, "rrb");
	}
}

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	if (!a || !(*a))
		return ;
	cheapest_node = get_cheapest_node(*a);
	if (!cheapest_node)
		return ;
	move_to_positions(a, b, cheapest_node);
	push(b, a, "pb");
}

void	move_b_to_a(t_node **a, t_node **b)
{
	t_node	*target_node;

	if (!b || !(*b))
		return ;
	target_node = (*b)->target_node;
	if (!target_node)
		return ;
	if (!is_target_in_a(*a, target_node))
		return ;
	while (*a != target_node)
	{
		if (target_node->index <= stack_len(*a) / 2)
			rotate(a, "ra");
		else
			reverse_rotate(a, "rra");
	}
	push(a, b, "pa");
}

int	is_target_in_a(t_node *a, t_node *target_node)
{
	while (a)
	{
		if (a == target_node)
			return (1);
		a = a->next;
	}
	return (0);
}
